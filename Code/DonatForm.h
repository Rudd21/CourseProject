#pragma once

#include "Donat.h"
#include "AddDonatForm.h"
#include "EditDonatForm.h"

namespace Kursova {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DonatForm
	/// </summary>
	public ref class DonatForm : public System::Windows::Forms::Form
	{
	public:
		DonatForm(void)
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
		~DonatForm()
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

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: void LoadDonations() {
		try {
			Kursova::DonatService^ service = gcnew Kursova::DonatService();

			// Зчитуємо текст напряму
			String^ searchPersonName = (textBox1 != nullptr) ? textBox1->Text->Trim() : "";
			String^ searchCollectionTitle = (textBox2 != nullptr) ? textBox2->Text->Trim() : "";
			Decimal minSum = (numericUpDown1 != nullptr) ? numericUpDown1->Value : 0;

			auto donations = service->GetDonations(searchPersonName, searchCollectionTitle, minSum);

			// Прив'язуємо дані до таблиці
			this->dataGridView1->DataSource = donations;

			// Налаштовуємо заголовки
			if (dataGridView1->Columns->Count > 0) {
				if (dataGridView1->Columns->Contains("idDonat"))
					dataGridView1->Columns["idDonat"]->HeaderText = "ID";
				if (dataGridView1->Columns->Contains("sum")) {
					dataGridView1->Columns["sum"]->HeaderText = "Сума";
					dataGridView1->Columns["sum"]->DefaultCellStyle->Format = "C2"; // Формат валюти
				}
				if (dataGridView1->Columns->Contains("donationDate"))
					dataGridView1->Columns["donationDate"]->HeaderText = "Дата";
				if (dataGridView1->Columns->Contains("personName"))
					dataGridView1->Columns["personName"]->HeaderText = "Донор";
				if (dataGridView1->Columns->Contains("collectionTitle"))
					dataGridView1->Columns["collectionTitle"]->HeaderText = "Назва Збору";
				if (dataGridView1->Columns->Contains("idPerson"))
					dataGridView1->Columns["idPerson"]->HeaderText = "ID Донора";
				if (dataGridView1->Columns->Contains("idCollection"))
					dataGridView1->Columns["idCollection"]->HeaderText = "ID Збору";
			}

			dataGridView1->Columns["idDonat"]->DisplayIndex = 0;
			dataGridView1->Columns["sum"]->DisplayIndex = 1;
			dataGridView1->Columns["donationDate"]->DisplayIndex = 2;
			dataGridView1->Columns["personName"]->DisplayIndex = 3;
			dataGridView1->Columns["collectionTitle"]->DisplayIndex = 4;
			dataGridView1->Columns["idPerson"]->DisplayIndex = 5;
			dataGridView1->Columns["idCollection"]->DisplayIndex = 6;

		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка завантаження пожертв: " + ex->Message);
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DonatForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
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
			this->label1->Location = System::Drawing::Point(113, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(115, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Донати";
			this->label1->Click += gcnew System::EventHandler(this, &DonatForm::label1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 113);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(958, 368);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DonatForm::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Transparent;
			this->button1->Location = System::Drawing::Point(404, 64);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 43);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Додати";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &DonatForm::buttonAdd_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::Transparent;
			this->button2->Location = System::Drawing::Point(541, 64);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(131, 43);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Редагувати";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &DonatForm::buttonEdit_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::Transparent;
			this->button3->Location = System::Drawing::Point(678, 64);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(131, 43);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Видалити";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &DonatForm::buttonDelete_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->Location = System::Drawing::Point(815, 64);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(131, 43);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Вихід";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &DonatForm::button4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(349, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(203, 23);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Пошук за ПІБ донатера:";
			this->label3->Click += gcnew System::EventHandler(this, &DonatForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(579, 8);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(208, 23);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Пошук за назвою збору:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(389, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(111, 22);
			this->textBox1->TabIndex = 9;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &DonatForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(618, 34);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(111, 22);
			this->textBox2->TabIndex = 10;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &DonatForm::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(844, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 23);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Донат від:";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(826, 35);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 12;
			this->numericUpDown1->Maximum = 100000000;
			this->numericUpDown1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &DonatForm::numericUpDown1_KeyUp);
			// 
			// DonatForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(982, 493);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Name = L"DonatForm";
			this->Text = L"DonatForm";
			this->Load += gcnew System::EventHandler(this, &DonatForm::DonatForm_Load_1);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DonatForm_Load_1(System::Object^ sender, System::EventArgs^ e) {
		LoadDonations();
	}
private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedRows->Count > 0) {
		int id = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["idDonat"]->Value);

		if (MessageBox::Show("Видалити запис про пожертву?", "Увага", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			Kursova::DonatService^ service = gcnew Kursova::DonatService();
			service->Delete(id);
			LoadDonations(); // Твій метод оновлення таблиці
		}
	}
}
private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	AddDonatForm^ form = gcnew AddDonatForm();
	if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		LoadDonations();
	}
}
private: System::Void buttonEdit_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedRows->Count > 0) {
		// Отримуємо дані з рядка таблиці
		int id = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["idDonat"]->Value);
		Decimal sum = Convert::ToDecimal(dataGridView1->SelectedRows[0]->Cells["sum"]->Value);
		DateTime date = Convert::ToDateTime(dataGridView1->SelectedRows[0]->Cells["donationDate"]->Value);
		int pId = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["idPerson"]->Value);
		int cId = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["idCollection"]->Value);

		// Відкриваємо форму редагування
		EditDonatForm^ editForm = gcnew EditDonatForm(id, sum, date, pId, cId);

		if (editForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			LoadDonations(); // Оновлюємо таблицю після редагування
		}
	}
	else {
		MessageBox::Show("Будь ласка, виберіть рядок!");
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	LoadDonations();
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	LoadDonations();
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void numericUpDown1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	String^ currentText = numericUpDown1->Text;
	Decimal val;

	if (Decimal::TryParse(currentText, val)) {
		// Якщо введено коректне число — завантажуємо дані
		LoadDonations();
	}
}
};
}
