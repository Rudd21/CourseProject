#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Collections::Generic;

namespace Kursova {

    // Клас
    public ref class DonatItem {
    public:
        property int idDonat;
        property Decimal sum;
        property DateTime donationDate;
        property int idPerson;
        property int idCollection;
        property String^ personName;
        property String^ collectionTitle;

        DonatItem(int id, Decimal s, DateTime date, int personId, int collId,
            String^ pName, String^ cTitle) {
            idDonat = id;
            sum = s;
            donationDate = date;
            idPerson = personId;
            idCollection = collId;
            personName = pName;
            collectionTitle = cTitle;
        }
    };

    // Клас для логіки взаємодії з таблицею [Donat]
    public ref class DonatService {
    private:
        String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\\charity.mdf;Initial Catalog=CharityDB_Final;Integrated Security=True;Connect Timeout=30";

    public:
        // CREATE: Реєстрація нової пожертви
        void Create(Decimal sum, DateTime date, int personId, int collectionId) {
            SqlConnection^ conn = gcnew SqlConnection(connString);
            String^ query = "INSERT INTO [Donat] ([sum], donationDate, idPerson, idCollection) "
                "VALUES (@sum, @date, @pId, @cId)";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@sum", sum);
            cmd->Parameters->AddWithValue("@date", date);
            cmd->Parameters->AddWithValue("@pId", personId);
            cmd->Parameters->AddWithValue("@cId", collectionId);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            finally {
                conn->Close();
            }
        }

        // READ: Перегляд з фільтрами
        // Якщо передати id = 0, фільтр не застосовується
        List<DonatItem^>^ GetDonations(String^ personSearch, String^ collectionSearch, Decimal minSum) {
            auto list = gcnew List<DonatItem^>();
            SqlConnection^ conn = gcnew SqlConnection(connString);

            String^ query =
                "SELECT d.idDonat, d.[sum], d.donationDate, d.idPerson, d.idCollection, "
                "       p.fullName AS personName, c.title AS collectionTitle "
                "FROM [Donat] d "
                "JOIN [Person] p ON d.idPerson = p.idPerson "
                "JOIN [Collection] c ON d.idCollection = c.idCollection "
                "WHERE 1=1";

            if (!String::IsNullOrEmpty(personSearch))
                query += " AND p.fullName LIKE @pName";
            if (!String::IsNullOrEmpty(collectionSearch))
                query += " AND c.title LIKE @cTitle";

            // Фільтр "Сума від"
            if (minSum > 0)
                query += " AND d.[sum] >= @minSum";

            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            if (!String::IsNullOrEmpty(personSearch))
                cmd->Parameters->AddWithValue("@pName", "%" + personSearch + "%");
            if (!String::IsNullOrEmpty(collectionSearch))
                cmd->Parameters->AddWithValue("@cTitle", "%" + collectionSearch + "%");
            if (minSum > 0)
                cmd->Parameters->AddWithValue("@minSum", minSum);

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read()) {
                    list->Add(gcnew DonatItem(
                        (int)reader["idDonat"],
                        Convert::ToDecimal(reader["sum"]),
                        Convert::ToDateTime(reader["donationDate"]),
                        (int)reader["idPerson"],
                        (int)reader["idCollection"],
                        reader["personName"]->ToString(),
                        reader["collectionTitle"]->ToString()
                    ));
                }
            }
            finally { conn->Close(); }
            return list;
        }

        // UPDATE: Зміна суми або дати пожертви
        void Update(int id, Decimal sum, DateTime date, int personId, int collectionId) {
            SqlConnection^ conn = gcnew SqlConnection(connString);
            String^ query = "UPDATE [Donat] SET sum=@s, donationDate=@d, idPerson=@p, idCollection=@c WHERE idDonat=@id";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@id", id);
            cmd->Parameters->AddWithValue("@s", sum);
            cmd->Parameters->AddWithValue("@d", date);
            cmd->Parameters->AddWithValue("@p", personId);
            cmd->Parameters->AddWithValue("@c", collectionId);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            finally {
                conn->Close();
            }
        }

        // DELETE: Видалення запису про пожертву
        void Delete(int id) {
            SqlConnection^ conn = gcnew SqlConnection(connString);
            String^ query = "DELETE FROM [Donat] WHERE idDonat = @id";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@id", id);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            finally {
                conn->Close();
            }
        }
    };
}