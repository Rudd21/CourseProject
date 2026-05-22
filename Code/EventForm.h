#pragma once

#include "Event.h"
#include "EditEventForm.h"
#include "AddEventForm.h"

namespace Kursova {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EventForm
	/// </summary>
	public ref class EventForm : public System::Windows::Forms::Form
	{
	public:
		EventForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EventForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::ComboBox^ cmbStatus;
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: void LoadData() {
		try {
			Kursova::EventService^ service = gcnew Kursova::EventService();

			// Зчитуємо значення з контролів (якщо вони вже створені)
			String^ name = (txtSearch != nullptr) ? txtSearch->Text : "";
			String^ status = (cmbStatus != nullptr && cmbStatus->SelectedItem != nullptr)
				? cmbStatus->SelectedItem->ToString() : "Всі";

			// Викликаємо наш універсальний метод
			auto events = service->GetAll(name, status);
			this->dataGridView1->DataSource = nullptr; // Скидаємо старе
			this->dataGridView1->DataSource = events;

			dataGridView1->Columns["idEvent"]->DisplayIndex = 0;
			dataGridView1->Columns["name"]->DisplayIndex = 1;
			dataGridView1->Columns["description"]->DisplayIndex = 2;
			dataGridView1->Columns["startDate"]->DisplayIndex = 3;
			dataGridView1->Columns["endDate"]->DisplayIndex = 4;
			dataGridView1->Columns["goal"]->DisplayIndex = 5;
			dataGridView1->Columns["status"]->DisplayIndex = 6;
			if (dataGridView1->Columns->Count > 0) {
				dataGridView1->Columns["idEvent"]->HeaderText = "№";
				dataGridView1->Columns["name"]->HeaderText = "Назва";
				dataGridView1->Columns["description"]->HeaderText = "Опис";
				dataGridView1->Columns["startDate"]->HeaderText = "Дата початку";
				dataGridView1->Columns["endDate"]->HeaderText = "Дата кінця";
				dataGridView1->Columns["goal"]->HeaderText = "Ціль";
				dataGridView1->Columns["status"]->HeaderText = "Статус";

				dataGridView1->Columns["idEvent"]->DisplayIndex = 0;
				dataGridView1->Columns["name"]->DisplayIndex = 1;
				dataGridView1->Columns["description"]->DisplayIndex = 2;
				dataGridView1->Columns["startDate"]->DisplayIndex = 3;
				dataGridView1->Columns["endDate"]->DisplayIndex = 4;
				dataGridView1->Columns["goal"]->DisplayIndex = 5;
				dataGridView1->Columns["status"]->DisplayIndex = 6;
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка: " + ex->Message);
			MessageBox::Show("Помилка при завантаженні: " + ex->Message);
		}
	}
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EventForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->cmbStatus = (gcnew System::Windows::Forms::ComboBox());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(196)));
			this->label1->Location = System::Drawing::Point(133, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Події";
			this->label1->Click += gcnew System::EventHandler(this, &EventForm::label1_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Transparent;
			this->button1->Location = System::Drawing::Point(390, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(138, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Додати";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &EventForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::Transparent;
			this->button2->Location = System::Drawing::Point(534, 65);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(138, 39);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Редагувати";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &EventForm::buttonEdit_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::Transparent;
			this->button3->Location = System::Drawing::Point(678, 65);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(138, 39);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Видалити";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &EventForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::Color::Transparent;
			this->button4->Location = System::Drawing::Point(822, 65);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(138, 39);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Вихід";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &EventForm::button4_Click_1);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 110);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(958, 371);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &EventForm::dataGridView1_CellContentClick);
			// 
			// cmbStatus
			// 
			this->cmbStatus->FormattingEnabled = true;
			this->cmbStatus->Location = System::Drawing::Point(839, 25);
			this->cmbStatus->Name = L"cmbStatus";
			this->cmbStatus->Size = System::Drawing::Size(121, 24);
			this->cmbStatus->TabIndex = 6;
			this->cmbStatus->SelectedIndexChanged += gcnew System::EventHandler(this, &EventForm::cmbStatus_SelectedIndexChanged);
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(497, 27);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(100, 22);
			this->txtSearch->TabIndex = 7;
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &EventForm::txtSearch_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(319, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(156, 23);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Пошук за назвою:";
			this->label2->Click += gcnew System::EventHandler(this, &EventForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(618, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(198, 23);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Фільтрація за статусом:";
			// 
			// EventForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(982, 493);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->cmbStatus);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Name = L"EventForm";
			this->Text = L"EventForm";
			this->Load += gcnew System::EventHandler(this, &EventForm::EventForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EventForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// Налаштовуємо таблицю, щоб виділявся весь рядок
		this->dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
		this->dataGridView1->MultiSelect = false;
		this->dataGridView1->ReadOnly = true;

		this->cmbStatus->Items->Add(L"Всі");
		this->cmbStatus->Items->Add(L"Активний");
		this->cmbStatus->Items->Add(L"Завершено");
		this->cmbStatus->Items->Add(L"Заплановано");
		this->cmbStatus->SelectedIndex = 0;

		LoadData();
	}

	   // КНОПКА ДОДАТИ (button1)
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			AddEventForm^ form = gcnew AddEventForm();
			form->ShowDialog();
			LoadData();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка при відкритті форми додавання: " + ex->Message);
		}
		//AddEventForm^ form = gcnew AddEventForm();
		//if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		//	LoadData();
		//}
	}

		   // КНОПКА РЕДАГУВАТИ (button2)
	private: System::Void buttonEdit_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->SelectedRows->Count > 0) {
			auto row = dataGridView1->SelectedRows[0];

			try {
				// 1. Витягуємо дані
				int id = Convert::ToInt32(row->Cells["idEvent"]->Value);
				String^ name = row->Cells["Name"]->Value->ToString();
				String^ desc = row->Cells["Description"]->Value->ToString();
				DateTime start = Convert::ToDateTime(row->Cells["StartDate"]->Value);
				DateTime end = Convert::ToDateTime(row->Cells["EndDate"]->Value);
				String^ goal = row->Cells["Goal"]->Value->ToString();
				String^ status = row->Cells["Status"]->Value->ToString();

				// 2. Створюємо форму, передаючи ВСІ дані
				EditEventForm^ form = gcnew EditEventForm(id, name, desc, start, end, goal, status);

				// 3. Тільки тепер показуємо
				form->ShowDialog();
				LoadData();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Помилка при передачі даних у форму: " + ex->Message);
			}
		}
	}

		   // КНОПКА ВИДАЛИТИ (button3)
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->SelectedRows->Count > 0) {
			int id = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["idEvent"]->Value);

			if (MessageBox::Show("Видалити цю подію?", "Підтвердження", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) {
				Kursova::EventService^ service = gcnew Kursova::EventService();
				if (service->Delete(id)) {
					LoadData();
				}
				else {
					MessageBox::Show("Не вдалося видалити: на цю подію посилаються активні збори!");
				}
			}
		}
		else {
			MessageBox::Show("Будь ласка, виберіть рядок для видалення.");
		}
	}

		   // КНОПКА ВИХІД (button4)
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	LoadData();
}
private: System::Void cmbStatus_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	LoadData();
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
