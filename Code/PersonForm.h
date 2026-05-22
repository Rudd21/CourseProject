#pragma once

#include "Person.h"
#include "AddPersonForm.h"
#include "EditPersonForm.h"

namespace Kursova {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PersonForm
	/// </summary>
	public ref class PersonForm : public System::Windows::Forms::Form
	{
	public:
		PersonForm(void)
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
		~PersonForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
	private: bool isLoading;

	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: void LoadData() {
		if (isLoading) return;
		isLoading = true;
		try {
			Kursova::PersonService^ service = gcnew Kursova::PersonService();

			// 1. ПІБ
			String^ searchName = (textBox1 != nullptr) ? textBox1->Text->Trim() : "";

			String^ searchContact = maskedTextBox1->Text->Trim();
			maskedTextBox1->TextMaskFormat = MaskFormat::IncludePromptAndLiterals;

			if (searchContact->Replace(" ", "")->Length < 8) searchContact = "";

			auto data = service->GetPersons(searchName, searchContact);

			this->dataGridView1->DataSource = data;

			auto persons = service->GetPersons(searchName, searchContact);
			this->dataGridView1->DataSource = persons;

			if (dataGridView1->Columns->Count > 0) {
				dataGridView1->Columns["idPerson"]->HeaderText = "№";
				dataGridView1->Columns["fullName"]->HeaderText = "ПІБ";
				dataGridView1->Columns["phone"]->HeaderText = "Телефон";
				dataGridView1->Columns["email"]->HeaderText = "Електронна пошта";
				dataGridView1->Columns["address"]->HeaderText = "Адреса";
				dataGridView1->Columns["idPerson"]->DisplayIndex = 0;
				dataGridView1->Columns["fullName"]->DisplayIndex = 1;
				dataGridView1->Columns["address"]->DisplayIndex = 2;
				dataGridView1->Columns["phone"]->DisplayIndex = 3;
				dataGridView1->Columns["email"]->DisplayIndex = 4;
				dataGridView1->Columns["fullName"]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
				dataGridView1->Columns["address"]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка при завантаженні: " + ex->Message);
		}
		finally {
			isLoading = false;
		}
	}

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PersonForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(196)));
			this->label1->Location = System::Drawing::Point(107, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Персони";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Transparent;
			this->button1->Location = System::Drawing::Point(404, 62);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 42);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Додати";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &PersonForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 110);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(958, 370);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &PersonForm::DataGridView1_CellContentClick_2);
			this->dataGridView1->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &PersonForm::dataGridView1_CellFormatting);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::Transparent;
			this->button2->Location = System::Drawing::Point(677, 63);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(131, 42);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Видалити";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &PersonForm::buttonDelete_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->Location = System::Drawing::Point(540, 62);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(131, 42);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Редагувати";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &PersonForm::buttonEdit_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->Location = System::Drawing::Point(812, 62);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(131, 43);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Вихід";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &PersonForm::button4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(316, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(154, 23);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Загальний пошук:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(650, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(186, 23);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Пошук за телефоном:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(476, 22);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(128, 22);
			this->textBox1->TabIndex = 8;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &PersonForm::textBox1_TextChanged);
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(842, 23);
			this->maskedTextBox1->Mask = L"+38 (000) 000-00-00";
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(128, 22);
			this->maskedTextBox1->TabIndex = 9;
			this->maskedTextBox1->TextChanged += gcnew System::EventHandler(this, &PersonForm::maskedTextBox1_TextChanged);
			// 
			// PersonForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(982, 493);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Name = L"PersonForm";
			this->Text = L"PersonForm";
			this->Load += gcnew System::EventHandler(this, &PersonForm::PersonForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PersonForm_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadData();
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void dataGridView1_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		AddPersonForm^ form = gcnew AddPersonForm();
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			LoadData(); // Оновити таблицю після додавання
		}
	}
private: System::Void DataGridView1_CellContentClick_2(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	// Перевірка, чи вибрано хоча б один рядок
	if (dataGridView1->SelectedRows->Count > 0) {
		// Отримання ID 
		int id = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["idPerson"]->Value);

		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Ви впевнені, що хочете видалити цього донора?",
			"Підтвердження",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			Kursova::PersonService^ service = gcnew Kursova::PersonService();

			// Виклик методу Delete
			if (service->Delete(id)) {
				MessageBox::Show("Запис видалено!");
				LoadData(); // Оновлення таблиці
			}
			else {
				MessageBox::Show("Неможливо видалити: у цього донора є активні пожертви.");
			}
		}
	}
	else {
		MessageBox::Show("Будь ласка, виберіть рядок для видалення.");
	}
}
private: System::Void buttonEdit_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedRows->Count > 0) {
		// Зчитуємо дані з виділеного рядка
		int id = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["idPerson"]->Value);
		String^ name = dataGridView1->SelectedRows[0]->Cells["fullName"]->Value->ToString();
		String^ phone = dataGridView1->SelectedRows[0]->Cells["phone"]->Value->ToString();
		String^ email = dataGridView1->SelectedRows[0]->Cells["email"]->Value->ToString();
		String^ address = dataGridView1->SelectedRows[0]->Cells["address"]->Value->ToString();

		// Відкриваємо форму редагування
		EditPersonForm^ editForm = gcnew EditPersonForm(id, name, phone, email, address);
		if (editForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			LoadData(); // Оновлюємо таблицю після успішного редагування
		}
	}
	else {
		MessageBox::Show("Виберіть запис для редагування.");
	}
}
private: System::Void dataGridView1_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e) {
	// Перевіряємо, чи це колонка з телефоном
	if (this->dataGridView1->Columns[e->ColumnIndex]->Name == "phone" && e->Value != nullptr) {
		String^ phone = e->Value->ToString();

		if (phone->Length == 12) {
			// Форматуємо як: +38 (0XX) XXX-XX-XX
			e->Value = String::Format("+{0}{1} ({2}) {3}-{4}-{5}",
				phone->Substring(0, 1), phone->Substring(1, 1), // 38
				phone->Substring(2, 3),
				phone->Substring(5, 3),
				phone->Substring(8, 2),
				phone->Substring(10, 2));

			e->FormattingApplied = true;
		}
	}
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	LoadData();
}
private: System::Void maskedTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	LoadData();
}
};
}
