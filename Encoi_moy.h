#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "convert.h"
#include "Dictionary.h"
#include "file_miner.h"
#include "err_proc.h"

#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

#define FILE_NAME "small_book.txt"

namespace Encoimoy {

	dictionary dct;
	bool first_run = true;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Encoi_moy : public System::Windows::Forms::Form
	{
	public:
		Encoi_moy(void)
		{
			InitializeComponent();
		}

	protected:
		~Encoi_moy()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ listBox1;

	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Encoi_moy::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(21, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(141, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите слово";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(168, 21);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(255, 29);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(429, 18);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 34);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Поиск";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Encoi_moy::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(24, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(570, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Вводите слово по-русски, и оно будет переведено на Encoi moȳ";
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 22;
			this->listBox1->Location = System::Drawing::Point(28, 99);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(851, 1038);
			this->listBox1->TabIndex = 4;
			// 
			// Encoi_moy
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1135, 1156);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Encoi_moy";
			this->Text = L"Encoi_moy";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->textBox1->Text == L"") return;

		if (first_run) {
			first_run = false;

			Error* code = new Error;
			*code = OPERATION_FAILED;
			file_miner(FILE_NAME, &dct, code);
			delete code;
		}

		this->listBox1->Items->Clear();

		dictionary relev;

		/*for (size_t i = 0; i < dct.size; i++) {
			if (i == 0) {
				prev = dct.find(msclr::interop::marshal_as<std::wstring>(this->textBox1->Text), i);

				if (prev.is_empty()) {
					this->listBox1->Items->Add(L"Слово не найдено");
					break;
				}

				this->listBox1->Items->Add(gcnew String(prev.key.c_str()) + L" - " + gcnew String(prev.value.c_str()));
				continue;
			}

			node now = dct.find(msclr::interop::marshal_as<std::wstring>(this->textBox1->Text), i);

			if (now.is_empty()) break;

			if (comparison(&prev, &now)) continue;
			else {
				this->listBox1->Items->Add(gcnew String(now.key.c_str()) + L" - " + gcnew String(now.value.c_str()));
				prev = now;
			}

		}*/

		size_t index = 0;
		int max_relev = -1;

		for (size_t i = 0; i < dct.size; i++) {

			node now = find(msclr::interop::marshal_as<std::wstring>(this->textBox1->Text), dct.book[i]);

			if (now.is_empty()) continue;

			max_relev = now.relevance > max_relev ? now.relevance : max_relev;

			if (index + 1 > relev.size) relev.add(1);

			relev.book[index] = now;
			index++;
		}

		if (max_relev == -1) {
			this->listBox1->Items->Add(L"Слово не найдено");
			return;
		}

		for (int i = 0; i < max_relev + 1; i++) {
			for (size_t j = 0; j < index; j++) {
				if (relev.book[j].relevance == i) this->listBox1->Items->Add(gcnew String(relev.book[j].key.c_str()) + L" - " + gcnew String(relev.book[j].value.c_str()));
			}
		}
	}
};
}

// TODO: Добавить сортировку по релевантности, добавить иконку приложения, создать .exe, дописать, перевести и внедрить book.txt