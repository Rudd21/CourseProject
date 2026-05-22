#pragma once

#include "Receipient.h"
#include "AddReceipientForm.h"
#include "EditReceipientForm.h"

namespace Kursova {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ReceipientForm
	/// </summary>
	public ref class ReceipientForm : public System::Windows::Forms::Form
	{
	public:
		ReceipientForm(void)
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
		~ReceipientForm()
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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: bool isLoading;

	private: void LoadReceipients() {
		if (isLoading) return;
		isLoading = true;
		try {
			Kursova::ReceipientService^ service = gcnew Kursova::ReceipientService();

			String^ searchName = (textBox1 != nullptr) ? textBox1->Text->Trim() : "";

			String^ searchContact = maskedTextBox1->Text->Trim();
			maskedTextBox1->TextMaskFormat = MaskFormat::IncludePromptAndLiterals;

			// Якщо цифр менше 8 — не фільтруємо
			if (searchContact->Replace(" ", "")->Length < 8) searchContact = "";

			// Отримуємо список усіх отримувачів через ваш метод GetAll
			auto data = service->GetAll(searchName, searchContact);

			// Прив'язуємо дані (переконайтеся, що назва dataGridView збігається)
			this->dataGridView1->DataSource = data;

			// Налаштування красивих заголовків
			if (dataGridView1->Columns->Count > 0) {
				if (dataGridView1->Columns->Contains("idReceipient"))
					dataGridView1->Columns["idReceipient"]->HeaderText = "ID";
				if (dataGridView1->Columns->Contains("fullName"))
					dataGridView1->Columns["fullName"]->HeaderText = "Назва";
				if (dataGridView1->Columns->Contains("description"))
					dataGridView1->Columns["description"]->HeaderText = "Опис";
				if (dataGridView1->Columns->Contains("contactInfo"))
					dataGridView1->Columns["contactInfo"]->HeaderText = "Контакти";
			}

			dataGridView1->Columns["idReceipient"]->DisplayIndex = 0;
			dataGridView1->Columns["fullName"]->DisplayIndex = 1;
			dataGridView1->Columns["description"]->DisplayIndex = 2;
			dataGridView1->Columns["contactInfo"]->DisplayIndex = 3;

			dataGridView1->Columns["description"]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка завантаження отримувачів: " + ex->Message);
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ReceipientForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(196)));
			this->label1->Location = System::Drawing::Point(98, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Рецепієнти";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 105);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(958, 376);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ReceipientForm::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Transparent;
			this->button1->Location = System::Drawing::Point(389, 54);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 45);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Додати";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ReceipientForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::Transparent;
			this->button2->Location = System::Drawing::Point(533, 54);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(137, 45);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Редагувати";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &ReceipientForm::button2_Click_1);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::Transparent;
			this->button3->Location = System::Drawing::Point(680, 54);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(137, 45);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Видалити";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &ReceipientForm::button3_Click_1);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::Color::Transparent;
			this->button4->Location = System::Drawing::Point(824, 54);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(137, 45);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Вихід";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &ReceipientForm::button4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(306, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(156, 23);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Пошук за назвою:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(631, 18);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(186, 23);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Пошук за телефоном:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(468, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(147, 22);
			this->textBox1->TabIndex = 9;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ReceipientForm::textBox1_TextChanged);
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(823, 20);
			this->maskedTextBox1->Mask = L"+38 (000) 000-00-00";
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(130, 22);
			this->maskedTextBox1->TabIndex = 10;
			this->maskedTextBox1->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &ReceipientForm::maskedTextBox1_MaskInputRejected);
			this->maskedTextBox1->TextChanged += gcnew System::EventHandler(this, &ReceipientForm::maskedTextBox1_TextChanged);
			// 
			// ReceipientForm
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
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Name = L"ReceipientForm";
			this->Text = L"ReceipientForm";
			this->Load += gcnew System::EventHandler(this, &ReceipientForm::ReceipientForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Завантаження при відкритті форми
	private: System::Void ReceipientForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
		this->dataGridView1->MultiSelect = false;
		LoadReceipients();
	}

	// ДОДАТИ (Потрібно буде створити форму AddReceipientForm)
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		AddReceipientForm^ form = gcnew AddReceipientForm();
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			LoadReceipients();
		}
	}

	// РЕДАГУВАТИ
	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->SelectedRows->Count > 0) {
			auto row = dataGridView1->SelectedRows[0];
			int id = Convert::ToInt32(row->Cells["idReceipient"]->Value);
			String^ name = row->Cells["fullName"]->Value->ToString();
			String^ desc = row->Cells["description"]->Value->ToString();
			String^ contact = row->Cells["contactInfo"]->Value->ToString();

			EditReceipientForm^ form = gcnew EditReceipientForm(id, name, desc, contact);
			if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				LoadReceipients();
			}
		}
	}

	// ВИДАЛИТИ
	private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->SelectedRows->Count > 0) {
			int id = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["idReceipient"]->Value);
			if (MessageBox::Show("Видалити цього отримувача?", "Підтвердження", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
				Kursova::ReceipientService^ service = gcnew Kursova::ReceipientService();
				if (service->Delete(id)) {
					LoadReceipients();
				}
				else {
					MessageBox::Show("Неможливо видалити: у отримувача є активні збори!");
				}
			}
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	LoadReceipients();
}
private: System::Void maskedTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	LoadReceipients();
}
private: System::Void maskedTextBox1_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
	// Порожня
}
};
}
