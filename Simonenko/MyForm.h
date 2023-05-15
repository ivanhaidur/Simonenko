#include <iostream>
#include <fstream>
#include <vector>
#include <msclr\marshal_cppstd.h>\
#include <string>
#pragma once

namespace Simonenko {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;
	using namespace msclr::interop;

	struct Anketa
	{
		int Vik;
		string Stat;
		string Osvita;
	};
	vector<Anketa> anketa_vector;
	void MarshalString(String^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(116, 36);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 69);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Ввести дані у файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(271, 169);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 31);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(271, 243);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 31);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(271, 310);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 31);
			this->textBox3->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(70, 227);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 25);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Введіть вік";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(13, 13);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1481, 823);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Location = System::Drawing::Point(8, 39);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1465, 776);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(49, 246);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(147, 25);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Введіть стать";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(49, 316);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 25);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Введіть освіту";
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(8, 39);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1465, 776);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1500, 845);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		 Anketa point;

		// Зчитування даних з TextBox і присвоєння їх структурі

		point.Vik = Convert::ToInt32(textBox1->Text);
		point.Stat = marshal_as<std::string>(textBox2->Text);
		point.Osvita = marshal_as<std::string>(textBox3->Text);
		String^ fileName = "Anketa.txt";

		std::ofstream file(marshal_as<std::string>(fileName), std::ofstream::app); // Відкриття файлу у режимі додавання

		if (file.is_open())
		{
			// Запис структури в файл
			file << point.Vik << " "
				<< point.Stat << " "
				<< point.Osvita << "\n";

			file.close();
		}
	}
};
}
