#pragma once

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include <iterator>
#include <cstdlib>
#include<string>
#include<ctime>

namespace test1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	protected:


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
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Info;
			this->textBox1->Location = System::Drawing::Point(127, 142);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(259, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(124, 126);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Write the desire ip address";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(127, 204);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(259, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(505, 539);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();


		}


		#define BLUE "\033[34m"
		#define RESET "\033[0m"
		#define GREEN "\033[32m"
		#define YELLOW "\033[33m"
		#define RED "\033[31m"


		int check(string file) {
			string a, b;
			int x, c;
			vector<int>ms;
			ifstream fin(file);
			while (!fin.eof()) {
				getline(fin, a);
				if (a[0] == 'P') {
					if (a == "PING: transmit failed. General failure. ")
						return -1;
				}
				if (a[0] == 'R') {
					if (a == "Request timed out.")
						return -1;
					for (unsigned int i = 0; i < a.size(); i++) {
						if (a[i] == 't') {
							x = i + 4;
							while (a[x] != 'm') {
								b += a[x];
								x++;
							}
							c = stoi(b);
							ms.push_back(c);
						}
					}
				}
			}
			for (unsigned int i = 0; i < ms.size(); i++) {
				if (ms[i] < 20)
					return 0;
				else if (ms[i] > 20 && ms[i] < 60)
					return 1;
				else
					return 2;
			}
		}

		int main() {
			ofstream fout("traffic.txt");
			string file_name = "result.txt";
			vector<char> buffer;
			string a = "ping ";
			string b;
			string result;
			cin >> b;
			a += b;
			int j;
			while (true) {
				system((a + ">" + file_name).c_str());
				time_t now = time(0);
				tm* ltm = localtime(&now);
				j = check(file_name);
				if (j == 0)
					cout << "[" << ltm->tm_hour << ":" << 30 + ltm->tm_min << ":" << ltm->tm_sec << "] " << GREEN << "OK!" << RESET << endl;
				else if (j == 1)
					cout << "[" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << "] " << YELLOW << "MINIMUM" << RESET << endl;
				else if (j == -1) {
					cout << BLUE << "request time out. Check the ip address again";
					return 0;
				}
				else {
					cout << "[" << ltm->tm_hour << ":" << 30 + ltm->tm_min << ":" << ltm->tm_sec << "] " << RED << "NOT OK" << RESET << endl;
					fout << "[" << ltm->tm_hour << ":" << 30 + ltm->tm_min << ":" << ltm->tm_sec << "] " << RED << "NOT OK" << RESET << endl;
				}
			}
		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {


	}
	};
}
