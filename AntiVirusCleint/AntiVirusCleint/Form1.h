#pragma once
#include "stdafx.h"
#include <iostream>
#include <windows.h> 
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <psapi.h>
#include <TlHelp32.h>

namespace CppCLR_WinformsProjekt {

#include <iostream>
#include <windows.h> 


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Zusammenfassung f�r Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzuf�gen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnScan;
	private: System::Windows::Forms::Label^  test;
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnScan = (gcnew System::Windows::Forms::Button());
			this->test = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnScan
			// 
			this->btnScan->Location = System::Drawing::Point(12, 12);
			this->btnScan->Name = L"btnScan";
			this->btnScan->Size = System::Drawing::Size(121, 46);
			this->btnScan->TabIndex = 0;
			this->btnScan->Text = L"�����������";
			this->btnScan->UseVisualStyleBackColor = true;
			this->btnScan->Click += gcnew System::EventHandler(this, &Form1::btnScan_Click);
			// 
			// test
			// 
			this->test->AutoSize = true;
			this->test->Location = System::Drawing::Point(192, 56);
			this->test->Name = L"test";
			this->test->Size = System::Drawing::Size(35, 13);
			this->test->TabIndex = 1;
			this->test->Text = L"label1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(424, 472);
			this->Controls->Add(this->test);
			this->Controls->Add(this->btnScan);
			this->Name = L"Form1";
			this->Text = L"WitchDoctor";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	String^ folderName;
	HANDLE   hNamedPipe;
	LPDWORD   dwBytesWritten;// ��� ���������� ���������� ������
	DWORD   dwBytesRead;// ��� ���������� ����������� ������
	int    nMessageLength;     // ����� ���������


	private: System::Void btnScan_Click(System::Object^  sender, System::EventArgs^  e) {
		FolderBrowserDialog^ folderBrowserDialog1;
		folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;
		System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();
		folderName = folderBrowserDialog1->SelectedPath;
		test->Text = folderName;
		folderName += " 001";
		//path = test->Text;
		LPCSTR pchMessage = "001";
		if (!WriteFile(
			hNamedPipe,      // ���������� ������
			pchMessage,      // ������
			3,//nMessageLength,  // ������ ������
			dwBytesWritten, // ���������� ���������� ������
			NULL))           // ���������� ������
			test->Text += "��������: " + GetLastError();
	}
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		TCHAR   pipeName[80] = L"\\\\.\\pipe\\demo_pipe";

		hNamedPipe = CreateFile(
			pipeName,          // ��� ������
			GENERIC_READ | GENERIC_WRITE,       // ������ � ���������� � �����
			FILE_SHARE_READ | FILE_SHARE_WRITE, // ��������� ������ � ������ 
			NULL,                  // ������������ �� ���������
			OPEN_EXISTING,         // ��������� ������������ �����
			FILE_ATTRIBUTE_NORMAL, // �������� �� ���������
			NULL);

		if (hNamedPipe == INVALID_HANDLE_VALUE)
		{
			test->Text += "��������: " + GetLastError();
		}
	}
};
}
