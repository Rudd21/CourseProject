#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Collections::Generic;

namespace Kursova {

    // Клас
    public ref class PersonItem {
    public:
        property int idPerson;
        property String^ fullName;
        property String^ phone;
        property String^ email;
        property String^ address;

        PersonItem(int id, String^ name, String^ ph, String^ mail, String^ addr) {
            idPerson = id;
            fullName = name;
            phone = ph;
            email = mail;
            address = addr;
        }
    };


    // Клас для логіки взаємодії з таблицею [Person]
    public ref class PersonService {
    private:
        String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\\charity.mdf;Initial Catalog=CharityDB_Final;Integrated Security=True;Connect Timeout=30";

    public:
        // CREATE: Додати нового донора
        void Create(String^ name, String^ phone, String^ email, String^ address) {
            SqlConnection^ conn = gcnew SqlConnection(connString);
            String^ query = "INSERT INTO [Person] (fullName, phone, email, address) "
                "VALUES (@name, @phone, @email, @addr)";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@name", name);
            cmd->Parameters->AddWithValue("@phone", phone);
            cmd->Parameters->AddWithValue("@email", email);
            cmd->Parameters->AddWithValue("@addr", address);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            catch (SqlException^ ex) {
                if (ex->Number == 2627) // Код помилки для Unique Constraint (дублікат email)
                    throw gcnew Exception("Користувач з таким Email вже існує!");
                else throw ex;
            }
            finally {
                conn->Close();
            }
        }

        // READ: Перегляд списку з пошуком
        List<PersonItem^>^ GetPersons(String^ searchGeneral, String^ searchPhone) {
            auto list = gcnew List<PersonItem^>();
            SqlConnection^ conn = gcnew SqlConnection(connString);

            String^ query = "SELECT * FROM [Person] WHERE 1=1";

            // Розумний пошук: ПІБ OR Email OR Адреса
            if (!String::IsNullOrEmpty(searchGeneral))
                query += " AND (fullName LIKE @gen OR email LIKE @gen OR address LIKE @gen)";

            if (!String::IsNullOrEmpty(searchPhone))
                query += " AND phone LIKE @phone";

            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            if (!String::IsNullOrEmpty(searchGeneral))
                cmd->Parameters->AddWithValue("@gen", "%" + searchGeneral + "%");
            if (!String::IsNullOrEmpty(searchPhone))
                cmd->Parameters->AddWithValue("@phone", "%" + searchPhone + "%");

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read()) {
                    list->Add(gcnew PersonItem(
                        (int)reader["idPerson"],
                        reader["fullName"]->ToString(),
                        reader["phone"]->ToString(),
                        reader["email"]->ToString(),
                        reader["address"]->ToString()
                    ));
                }
            }
            finally { conn->Close(); }
            return list;
        }

        // UPDATE: Редагування контактів
        void Update(int id, String^ name, String^ phone, String^ email, String^ address) {
            SqlConnection^ conn = gcnew SqlConnection(connString);

            String^ query = "UPDATE [Person] SET fullName=@n, phone=@p, email=@e, address=@a WHERE idPerson=@id";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@id", id);
            cmd->Parameters->AddWithValue("@n", name);
            cmd->Parameters->AddWithValue("@p", phone);
            cmd->Parameters->AddWithValue("@e", email);
            cmd->Parameters->AddWithValue("@a", address);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            finally {
                conn->Close();
            }
        }

        // DELETE: Видалення (При умові якщо немає пожертв)
        bool Delete(int id) {
            SqlConnection^ conn = gcnew SqlConnection(connString);

            // Перевірка, чи робила ця людина пожертви (таблиця Donat)
            String^ checkQuery = "SELECT COUNT(*) FROM [Donat] WHERE idPerson = @id";
            SqlCommand^ checkCmd = gcnew SqlCommand(checkQuery, conn);
            checkCmd->Parameters->AddWithValue("@id", id);

            try {
                conn->Open();
                int count = (int)checkCmd->ExecuteScalar();

                if (count > 0) return false; // Перевірка чи можна видаляти активного донора

                String^ delQuery = "DELETE FROM [Person] WHERE idPerson = @id";
                SqlCommand^ delCmd = gcnew SqlCommand(delQuery, conn);
                delCmd->Parameters->AddWithValue("@id", id);
                delCmd->ExecuteNonQuery();
                return true;
            }
            finally {
                conn->Close();
            }
        }
    };
}