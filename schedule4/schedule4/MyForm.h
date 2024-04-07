#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <msclr\marshal_cppstd.h>

int sIZE;
bool** memVsSeries;
bool** memVsSlot;
short int** slotVsSeries;
std::string* show;

#pragma once

namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::TextBox^ textBox3;
    private: System::Windows::Forms::Label^ label4;




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
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::SystemColors::Control;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::SystemColors::ControlDark;
            this->label2->Location = System::Drawing::Point(175, 85);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(581, 38);
            this->label2->TabIndex = 14;
            this->label2->Text = L"_________________";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->label1->Location = System::Drawing::Point(89, 85);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(91, 38);
            this->label1->TabIndex = 13;
            this->label1->Text = L"Error: ";
            // 
            // textBox1
            // 
            this->textBox1->BackColor = System::Drawing::SystemColors::Control;
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox1->Location = System::Drawing::Point(316, 27);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(427, 43);
            this->textBox1->TabIndex = 12;
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::LightGray;
            this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->button1->Location = System::Drawing::Point(770, 12);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(201, 63);
            this->button1->TabIndex = 11;
            this->button1->Text = L"Schedule";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->label3->Location = System::Drawing::Point(87, 30);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(271, 38);
            this->label3->TabIndex = 15;
            this->label3->Text = L"Enter The File Path : ";
            // 
            // textBox2
            // 
            this->textBox2->BackColor = System::Drawing::SystemColors::Control;
            this->textBox2->Font = (gcnew System::Drawing::Font(L"Candara", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox2->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
            this->textBox2->HideSelection = false;
            this->textBox2->Location = System::Drawing::Point(135, 314);
            this->textBox2->Multiline = true;
            this->textBox2->Name = L"textBox2";
            this->textBox2->ReadOnly = true;
            this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
            this->textBox2->Size = System::Drawing::Size(485, 495);
            this->textBox2->TabIndex = 16;
            this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
            // 
            // textBox3
            // 
            this->textBox3->BackColor = System::Drawing::SystemColors::Control;
            this->textBox3->Font = (gcnew System::Drawing::Font(L"Candara", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox3->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
            this->textBox3->HideSelection = false;
            this->textBox3->Location = System::Drawing::Point(770, 314);
            this->textBox3->Multiline = true;
            this->textBox3->Name = L"textBox3";
            this->textBox3->ReadOnly = true;
            this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Both;
            this->textBox3->Size = System::Drawing::Size(485, 495);
            this->textBox3->TabIndex = 17;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Candara", 31.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->ForeColor = System::Drawing::Color::Black;
            this->label4->Location = System::Drawing::Point(478, 201);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(441, 64);
            this->label4->TabIndex = 18;
            this->label4->Text = L"Schedule Of Series";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(13, 31);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1578, 821);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->button1);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->ForeColor = System::Drawing::Color::DarkGreen;
            this->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
            this->Name = L"MyForm";
            this->Text = L"TV Channel Scheduler";
            this->ResumeLayout(false);
            this->PerformLayout();

        }


		//=======================================================================================================


        std::string slotToString(int num) {
            std::string slot;
            if (num <= 0 || num > 168) {
                slot = "Invalid slot number!";
            }
            else {
                if (num >= 1 && num <= 24) {
                    slot = "MON " + std::to_string(num - 1) + "-" + std::to_string(num);
                }
                else if (num >= 25 && num <= 48) {
                    slot = "TUE " + std::to_string(num - 25) + "-" + std::to_string(num - 24);
                }
                else if (num >= 49 && num <= 72) {
                    slot = "WED " + std::to_string(num - 49) + "-" + std::to_string(num - 48);
                }
                else if (num >= 73 && num <= 96) {
                    slot = "THU " + std::to_string(num - 73) + "-" + std::to_string(num - 72);
                }
                else if (num >= 97 && num <= 120) {
                    slot = "FRI " + std::to_string(num - 97) + "-" + std::to_string(num - 96);
                }
                else if (num >= 121 && num <= 144) {
                    slot = "SAT " + std::to_string(num - 121) + "-" + std::to_string(num - 120);
                }
                else if (num >= 145 && num <= 168) {
                    slot = "SUN " + std::to_string(num - 145) + "-" + std::to_string(num - 144);
                }
            }
            return slot;
        }

        int Slottoint(std::string s)
        {
            char str[4]{};
            for (int i = 0; i < 3; ++i)
            {
                str[i] = s[i];
            }
            str[3] = '\0';

            int n[2]{};
            int index_num;
            if (s[3] == ' ')
            {
                index_num = 4;
            }
            else
            {
                index_num = 5;
            }

            n[0] = s[index_num] - '0';
            n[1] = s[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(index_num) + 1] - '0';

            if (strcmp(str, "MON") == 0)
            {
                int x = (n[0] * 10 + n[1]);
                return x + 1;
            }

            if (strcmp(str, "TUE") == 0)
            {
                int x = (n[0] * 10 + n[1]);
                return x + 25;
            }

            if (strcmp(str, "WED") == 0)
            {
                int x = (n[0] * 10 + n[1]);
                return x + 49;
            }

            if (strcmp(str, "THU") == 0)
            {
                int x = (n[0] * 10 + n[1]);
                return x + 73;
            }

            if (strcmp(str, "FRI") == 0)
            {
                int x = (n[0] * 10 + n[1]);
                return x + 97;
            }

            if (strcmp(str, "SAT") == 0)
            {
                int x = (n[0] * 10 + n[1]);
                return x + 121;
            }

            if (strcmp(str, "SUN") == 0)
            {
                int x = (n[0] * 10 + n[1]);
                return x + 145;
            }

            return -1;
        }


        void input(std::string& filePath, int& sIZE, int& totalNames, bool*& memVsSeries, bool*& Nametoslot)
        {
            std::ifstream inputFile(filePath);

            if (!inputFile.is_open() || inputFile.fail())
            {
                label2->Text = "File not found!";
                label2->ForeColor = System::Drawing::Color::Red;
                textBox2->Text = "";
                textBox3->Text = "";
                return;
            }

            std::string line;
            if (!getline(inputFile, line))
            {
                label2->Text = "Failed to read first line!";
                label2->ForeColor = System::Drawing::Color::Red;
                textBox2->Text = "";
                textBox3->Text = "";
                return;
            }

            std::stringstream ss(line);
            if (!(ss >> sIZE))
            {
                label2->Text = "Failed to read total number of shows from first line!";
                label2->ForeColor = System::Drawing::Color::Red;
                textBox2->Text = "";
                textBox3->Text = "";
                return;
            }
            if (!(ss >> totalNames))
            {
                label2->Text = "Failed to read total number of members from first line!";
                label2->ForeColor = System::Drawing::Color::Red;
                textBox2->Text = "";
                textBox3->Text = "";
                return;
            }
            int i = 0;
            show = new std::string[sIZE];

            while (getline(inputFile, line) && i < sIZE)
            {
                std::stringstream ss(line);
                std::string token;
                while (getline(ss, token, ','))
                {
                    token.erase(0, token.find_first_not_of(' '));
                    token.erase(token.find_last_not_of(' ') + 1);
                    show[i] = token;
                    i++;
                }
            }

            std::string* Name;
            Name = new std::string[totalNames];
            memVsSeries = new bool* [totalNames];
            memVsSlot = new bool* [totalNames];


            for (size_t i = 0; i < totalNames; i++)
            {
                memVsSeries[i] = new bool[sIZE] {false};
                memVsSlot[i] = new bool[168] {false};
            }
            for (int k = 0; k < totalNames; k++) {
                getline(inputFile, line);
                Name[k] = line;

                getline(inputFile, line);

                std::stringstream sl(line);
                std::string token;
                int countAvailslots = 0;
                while (getline(sl, token, ',')) {
                    if (token == "\n") break;
                    token.erase(0, token.find_first_not_of(' '));
                    token.erase(token.find_last_not_of(' ') + 1);
                    int slot = Slottoint(token);
                    if (slot >= 0 && slot < 168) {
                        memVsSlot[k][slot] = true;
                        countAvailslots++;
                    }
                }

                int countfavoriteshow = 0;
                getline(inputFile, line);
                std::stringstream sh(line);
                std::string token2;
                while (getline(sh, token2, ','))
                {
                    if (token2 == "\n") break;
                    token2.erase(0, token2.find_first_not_of(' '));
                    token2.erase(token2.find_last_not_of(' ') + 1);
                    for (size_t j = 0; j < sIZE; j++)
                    {
                        if (token2 == show[j]) { memVsSeries[k][j] = true; countfavoriteshow++; }
                    }
                }
            }
            label2->Text = "File read successfully!";
            label2->ForeColor = System::Drawing::Color::Black;
            inputFile.close();
        }

        void storeSlotVsSeries(int memTotal, int slotTotal, int seriesTotal) {
            slotVsSeries = new short int* [slotTotal];
            for (int i = 0; i < slotTotal; i++) {
                slotVsSeries[i] = new short int[seriesTotal + 1]();
            }

            for (int i = 0; i < slotTotal; i++) {
                for (int j = 0; j < seriesTotal; j++) {
                    for (int k = 0; k < memTotal; k++) {
                        if (memVsSlot[k][i] == true && memVsSeries[k][j] == true) {
                            slotVsSeries[i][j]++;
                        }
                    }
                    slotVsSeries[i][seriesTotal] += slotVsSeries[i][j];
                }
            }
        }


        void findMax(int memTotal, int slotTotal, int seriesTotal) {
            std::vector<int> mAX(3);
            std::vector<int> cURR;
            int count = 0;

            do {
                mAX.clear();
                mAX.push_back(0);
                mAX.push_back(0);
                mAX.push_back(0);
                for (int i = 0; i < slotTotal; i++) {
                    for (int j = 0; j < seriesTotal; j++) {

                        if (slotVsSeries[i][j] > mAX[2]) {
                            mAX.clear();
                            mAX.push_back(i);
                            mAX.push_back(j);
                            mAX.push_back(slotVsSeries[i][j]);
                            for (int k = 0; k < memTotal; k++) {
                                if (memVsSlot[k][i] == true && memVsSeries[k][j] == true) {
                                    mAX.push_back(k);
                                }
                            }
                        }
                        else if (slotVsSeries[i][j] == mAX[2]) {
                            if ((slotVsSeries[i][seriesTotal] < slotVsSeries[mAX[0]][seriesTotal]) && (i != mAX[0])) {
                                mAX.clear();
                                mAX.push_back(i);
                                mAX.push_back(j);
                                mAX.push_back(slotVsSeries[i][j]);
                                for (int k = 0; k < memTotal; k++) {
                                    if (memVsSlot[k][i] == true && memVsSeries[k][j] == true) {
                                        mAX.push_back(k);
                                    }
                                }
                            }
                            else if ((slotVsSeries[i][seriesTotal] == slotVsSeries[mAX[0]][seriesTotal]) || (i == mAX[0])) {
                                cURR.clear();
                                for (int k = 0; k < memTotal; k++) {
                                    if (memVsSlot[k][i] == true && memVsSeries[k][j] == true) {
                                        cURR.push_back(k);
                                    }
                                }
                                int sum = 0, count1 = 0, count2 = 0;
                                for (int k = 0; k < slotTotal; k++) {
                                    for (int l = 0; l < cURR.size(); ++l) {
                                        if (memVsSlot[cURR[l]][k] == true && memVsSeries[cURR[l]][j] == true) {
                                            count1++;
                                        }
                                    }
                                }
                                for (int k = 0; k < slotTotal; k++) {
                                    for (int l = 3; l < mAX.size(); ++l) {
                                        if (memVsSlot[mAX[l]][k] == true && memVsSeries[mAX[l]][j] == true) {
                                            count2++;
                                        }
                                    }
                                }
                                if (count1 > count2) {
                                    mAX.clear();
                                    mAX.push_back(i);
                                    mAX.push_back(j);
                                    mAX.push_back(slotVsSeries[i][j]);
                                    for (int k = 0; k < memTotal; k++) {
                                        if (memVsSlot[k][i] == true && memVsSeries[k][j] == true) {
                                            mAX.push_back(k);
                                        }
                                    }
                                }
                            }
                        }

                    }
                }
                if (mAX[2] == 0)
                {
                    return;
                }
                if (count % 2 == 1) {
                    textBox2->Text += gcnew String(slotToString(mAX[0]).c_str()) + " " + gcnew String((show[mAX[1]]).c_str()) + Environment::NewLine;
                    count++;
                }
                else {
					textBox3->Text += gcnew String(slotToString(mAX[0]).c_str()) + " " + gcnew String((show[mAX[1]]).c_str()) + Environment::NewLine;
					count++;
				}

                for (int l = 3; l < mAX.size(); l++) {
                    for (int k = 0; k < slotTotal; k++) {
                        if (memVsSlot[mAX[l]][k] == true && memVsSeries[mAX[l]][mAX[1]] == true) {
                            slotVsSeries[k][mAX[1]]--;
                            slotVsSeries[k][seriesTotal]--;
                        }
                    }
                    memVsSeries[mAX[l]][mAX[1]] = false;
                }
                for (int k = 0; k < memTotal; k++) {
                    memVsSlot[k][mAX[0]] = false;
                }
                for (int k = 0; k < seriesTotal + 1; k++) {
                    slotVsSeries[mAX[0]][k] = 0;
                }

            } while (mAX[2] != 0);

        }


		//=======================================================================================================

#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    int totalNames = 0;
    std::string filePath = msclr::interop::marshal_as<std::string>(textBox1->Text);
	input(filePath, sIZE, totalNames, memVsSeries, memVsSlot);
	storeSlotVsSeries(totalNames, 168, sIZE);
	findMax(totalNames, 168, sIZE);
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
