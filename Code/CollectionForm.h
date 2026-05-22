#pragma once

#include "Collection.h"
#include "AddCollectionForm.h"
#include "EditCollectionForm.h"

namespace Kursova {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CollectionForm
	/// </summary>
	public ref class CollectionForm : public System::Windows::Forms::Form
	{
	public:
		CollectionForm(void)
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
		~CollectionForm()
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
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	
	private: void LoadData() {
		try {

			// Зчитуємо назву збору з textBox1
			String^ searchTitle = (textBox1 != nullptr) ? textBox1->Text->Trim() : "";

			// Зчитуємо ім'я отримувача з textBox2
			String^ searchRec = (textBox2 != nullptr) ? textBox2->Text->Trim() : "";

			Kursova::CollectionService^ service = gcnew Kursova::CollectionService();

			// Викликаємо оновлений GetAll
			auto collections = service->GetAll(searchTitle, searchRec);

			this->dataGridView1->DataSource = collections;

			if (dataGridView1->Columns->Count > 0) {
				// Використовуємо Contains для безпеки
				if (dataGridView1->Columns->Contains("idCollection"))
					dataGridView1->Columns["idCollection"]->HeaderText = "ID";

				if (dataGridView1->Columns->Contains("title"))
					dataGridView1->Columns["title"]->HeaderText = "Назва";

				if (dataGridView1->Columns->Contains("targetAmount")) // Виправлено Amount
					dataGridView1->Columns["targetAmount"]->HeaderText = "Ціль";

				if (dataGridView1->Columns->Contains("report"))
					dataGridView1->Columns["report"]->HeaderText = "Звіт";

				if (dataGridView1->Columns->Contains("receipientName"))
					dataGridView1->Columns["receipientName"]->HeaderText = "Назва отримувача";

				if (dataGridView1->Columns->Contains("eventName"))
					dataGridView1->Columns["eventName"]->HeaderText = "Назва Заходу";

				if (dataGridView1->Columns->Contains("idReceipient"))
					dataGridView1->Columns["idReceipient"]->HeaderText = "ID Отримувача";

				if (dataGridView1->Columns->Contains("idEvent"))
					dataGridView1->Columns["idEvent"]->HeaderText = "ID Заходу";

				dataGridView1->Columns["idCollection"]->DisplayIndex = 0;
				dataGridView1->Columns["title"]->DisplayIndex = 1;
				dataGridView1->Columns["targetAmount"]->DisplayIndex = 2;
				dataGridView1->Columns["report"]->DisplayIndex = 3;
				dataGridView1->Columns["receipientName"]->DisplayIndex = 4;
				dataGridView1->Columns["eventName"]->DisplayIndex = 5;
				dataGridView1->Columns["idReceipient"]->DisplayIndex = 6;
				dataGridView1->Columns["idEvent"]->DisplayIndex = 7;

			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка при завантаженні: " + ex->Message);
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CollectionForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
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
			this->label1->Location = System::Drawing::Point(125, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Збори";
			this->label1->Click += gcnew System::EventHandler(this, &CollectionForm::label1_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Transparent;
			this->button1->Location = System::Drawing::Point(405, 64);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(134, 49);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Додати";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &CollectionForm::buttonAdd_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::Transparent;
			this->button2->Location = System::Drawing::Point(545, 64);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(134, 49);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Редагувати";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &CollectionForm::buttonEdit_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::Transparent;
			this->button3->Location = System::Drawing::Point(825, 64);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(134, 49);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Вихід";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &CollectionForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->button4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::Color::Transparent;
			this->button4->Location = System::Drawing::Point(685, 64);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(134, 49);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Видалити";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &CollectionForm::buttonDelete_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 119);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(958, 362);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CollectionForm::dataGridView1_CellContentClick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(384, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(156, 23);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Пошук за назвою:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(636, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(323, 23);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Пошуком за подією або отримувачем:";
			this->label3->Click += gcnew System::EventHandler(this, &CollectionForm::label3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(388, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(151, 22);
			this->textBox1->TabIndex = 8;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &CollectionForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(705, 35);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(180, 22);
			this->textBox2->TabIndex = 9;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &CollectionForm::textBox2_TextChanged);
			// 
			// CollectionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(982, 493);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Name = L"CollectionForm";
			this->Text = L"CollectionForm";
			this->Load += gcnew System::EventHandler(this, &CollectionForm::CollectionForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void CollectionForm_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadData();
	}
	private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		AddCollectionForm^ form = gcnew AddCollectionForm();
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			LoadData();
		}
	}
	private: System::Void buttonEdit_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->SelectedRows->Count > 0) {
			auto row = dataGridView1->SelectedRows[0];
			EditCollectionForm^ f = gcnew EditCollectionForm(
				Convert::ToInt32(row->Cells["idCollection"]->Value),
				row->Cells["title"]->Value->ToString(),
				Convert::ToDecimal(row->Cells["targetAmount"]->Value),
				row->Cells["report"]->Value->ToString(),
				Convert::ToInt32(row->Cells["idReceipient"]->Value),
				Convert::ToInt32(row->Cells["idEvent"]->Value)
			);
			if (f->ShowDialog() == System::Windows::Forms::DialogResult::OK) LoadData();
		}

	}
	private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->SelectedRows->Count > 0) {
			int id = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["idCollection"]->Value);
			if (MessageBox::Show("Видалити цей збір?", "Увага", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
				Kursova::CollectionService^ service = gcnew Kursova::CollectionService();
				if (service->Delete(id)) {
					LoadData();
				}
				else {
					MessageBox::Show("Не можна видалити збір, до якого вже є пожертви!");
				}
			}
		}
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	LoadData();
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	LoadData();
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
