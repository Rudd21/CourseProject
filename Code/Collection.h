#pragma once
using namespace System;

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Collections::Generic;

namespace Kursova {

    // Клас
    public ref class CollectionItem {
    public:
        property int idCollection;
        property String^ title;
        property Decimal targetAmount;
        property String^ report;
        property int idReceipient;
        property int idEvent;
        property String^ receipientName;
        property String^ eventName;

        CollectionItem(int id, String^ t, Decimal target, String^ rep,
            int recId, int evId, String^ recName, String^ evName) {
            idCollection = id;
            title = t;
            targetAmount = target;
            report = rep;
            idReceipient = recId;
            idEvent = evId;
            receipientName = recName;
            eventName = evName;
        }
    };
    
    // Клас для взаємодії з таблицею [Collection]
    public ref class CollectionService {
    private:
        String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\\charity.mdf;Initial Catalog=CharityDB_Final;Integrated Security=True;Connect Timeout=30";

    public:
        // CREATE: Додати новий збір (з урахуванням idEvent)
        void Create(String^ title, Decimal target, String^ report, int recipientId, int eventId) {
            SqlConnection^ conn = gcnew SqlConnection(connString);
            // Додаємо idEvent у запит
            String^ query = "INSERT INTO [Collection] (title, targetAmount, report, idReceipient, idEvent) "
                "VALUES (@title, @target, @report, @recId, @eventId)";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@title", title);
            cmd->Parameters->AddWithValue("@target", target);
            cmd->Parameters->AddWithValue("@report", report);
            cmd->Parameters->AddWithValue("@recId", recipientId);
            cmd->Parameters->AddWithValue("@eventId", eventId);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            finally {
                conn->Close();
            }
        }

        // READ: Отримати збори з фільтрацією за назвою та отримувачем
        List<CollectionItem^>^ GetAll(String^ searchTitle, String^ searchRecipientOrEvent) {
            auto list = gcnew List<CollectionItem^>();
            SqlConnection^ conn = gcnew SqlConnection(connString);

            String^ query =
                "SELECT c.idCollection, c.title, c.targetAmount, c.report, "
                "       c.idReceipient, c.idEvent, "
                "       r.fullName AS receipientName, "
                "       e.Name AS eventName "
                "FROM [Collection] c "
                "JOIN [Receipient] r ON c.idReceipient = r.idReceipient "
                "LEFT JOIN [Event] e ON c.idEvent = e.idEvent "
                "WHERE 1=1";

            if (!String::IsNullOrWhiteSpace(searchTitle))
                query += " AND c.title LIKE @title";

            // Розумний пошук: Отримувач OR Захід
            if (!String::IsNullOrWhiteSpace(searchRecipientOrEvent))
                query += " AND (r.fullName LIKE @recEvent OR e.Name LIKE @recEvent)";

            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            if (!String::IsNullOrWhiteSpace(searchTitle))
                cmd->Parameters->AddWithValue("@title", "%" + searchTitle + "%");
            if (!String::IsNullOrWhiteSpace(searchRecipientOrEvent))
                cmd->Parameters->AddWithValue("@recEvent", "%" + searchRecipientOrEvent + "%");

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read()) {
                    list->Add(gcnew CollectionItem(
                        (int)reader["idCollection"],
                        reader["title"]->ToString(),
                        Convert::ToDecimal(reader["targetAmount"]),
                        reader["report"] == DBNull::Value ? "" : reader["report"]->ToString(),
                        (int)reader["idReceipient"],
                        reader["idEvent"] == DBNull::Value ? 0 : (int)reader["idEvent"],
                        reader["receipientName"]->ToString(),
                        reader["eventName"] == DBNull::Value ? "—" : reader["eventName"]->ToString()
                    ));
                }
            }
            finally { conn->Close(); }
            return list;
        }

        // UPDATE: Оновлення даних збору
        void Update(int id, String^ title, Decimal target, String^ report, int recId, int evId) {
            SqlConnection^ conn = gcnew SqlConnection(connString);
            String^ query = "UPDATE [Collection] SET title=@t, targetAmount=@target, report=@rep, idReceipient=@recId, idEvent=@evId WHERE idCollection=@id";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@id", id);
            cmd->Parameters->AddWithValue("@t", title);
            cmd->Parameters->AddWithValue("@target", target);
            cmd->Parameters->AddWithValue("@rep", report);
            cmd->Parameters->AddWithValue("@recId", recId);
            cmd->Parameters->AddWithValue("@evId", evId);

            try { conn->Open(); cmd->ExecuteNonQuery(); }
            finally { conn->Close(); }
        }

        // DELETE: Видалення збору (код, який ми обговорювали раніше з перевіркою на донати)
        bool Delete(int id) {
            SqlConnection^ conn = gcnew SqlConnection(connString);
            try {
                conn->Open();
                // Перевірка, чи є пожертви до цього збору
                SqlCommand^ checkCmd = gcnew SqlCommand("SELECT COUNT(*) FROM [Donat] WHERE idCollection = @id", conn);
                checkCmd->Parameters->AddWithValue("@id", id);
                if ((int)checkCmd->ExecuteScalar() > 0) return false;

                SqlCommand^ delCmd = gcnew SqlCommand("DELETE FROM [Collection] WHERE idCollection = @id", conn);
                delCmd->Parameters->AddWithValue("@id", id);
                delCmd->ExecuteNonQuery();
                return true;
            }
            finally { conn->Close(); }
        }
    };
}