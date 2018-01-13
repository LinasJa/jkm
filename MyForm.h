#pragma once

#include <fstream>
#include <cmath>
#include <iostream>
#include <iomanip>
#include<limits>
#include "Singleton.h"
#include <stdio.h>

namespace JKMND1 {

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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;

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
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->label1 = (gcnew System::Windows::Forms::Label());
	this->SuspendLayout();
	// 
	// button1
	// 
	this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
		static_cast<System::Int32>(static_cast<System::Byte>(150)));
	this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)),
		static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
	this->button1->FlatAppearance->BorderSize = 0;
	this->button1->Location = System::Drawing::Point(232, 235);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(170, 41);
	this->button1->TabIndex = 0;
	this->button1->Text = L"Vykdyti programa";
	this->button1->UseVisualStyleBackColor = false;
	this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
	// 
	// label1
	// 
	this->label1->AutoSize = true;
	this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
	this->label1->Location = System::Drawing::Point(55, 58);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(95, 13);
	this->label1->TabIndex = 1;
	this->label1->Text = L"";
	// 
	// MyForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
		static_cast<System::Int32>(static_cast<System::Byte>(70)));
	this->ClientSize = System::Drawing::Size(434, 311);
	this->Controls->Add(this->label1);
	this->Controls->Add(this->button1);
	this->Name = L"MyForm";
	this->Text = L"MyForm";
	this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
	this->ResumeLayout(false);
	this->PerformLayout();

}
#pragma endregion
//Pakelimo kvadratu funkcija
double _pow(double x)
{
	return x*x;
}

double AtkarposIlgis(int x[], int y[], int pirmI, int antrI)
{
	double ilgis = 0;
	double ilgX = x[antrI] - x[pirmI];
	double ilgY = y[antrI] - y[pirmI];
	//Apskaiciuoja vienos atkarpos ilgi
	ilgis = sqrt(_pow(ilgX) + _pow(ilgY));


	return ilgis;

}

bool StatusT(double TrikampioAt[])
{
	//Patikrina ar status trikampis pagal pitagoro teorema
	if (int(_pow(TrikampioAt[0])) + int(_pow(TrikampioAt[1])) == int(_pow(TrikampioAt[2])))
	{
		return true;
	}
		else if (int(_pow(TrikampioAt[0])) + int(_pow(TrikampioAt[2])) == int(_pow(TrikampioAt[1])))
		{
			return true;
		}
			else if (int(_pow(TrikampioAt[1])) + int(_pow(TrikampioAt[2])) == int(_pow(TrikampioAt[0])))
			{
				return true;
			}
				else
				{
					return false;
				}
	}

void isvedimas(ofstream& fout, int X[], int Y[], int k,int m,int n)
{
	fout <<"|" <<setw(5) <<X[k] << " | " <<setw(5)<< Y[k]<<"|" <<endl <<"|"<<setw(5)<< X[m] << " | "<<setw(5) << Y[m]<<"|" <<endl <<"|"<<setw(5)<< X[n] << " | " <<setw(5)<< Y[n] <<"|"<<endl << "Sudaro statu trikampi."<<endl <<endl;

}


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		this->label1->Text = L"Programa startuojama";
		ifstream fin("fin.txt");
		ofstream fout("fout.txt");
		bool status = false;
		int X[100];
		int Y[100];
		double TrikampioAtkarpos[3];
		int x = 0;
		int butina;
		int k = 0;
		Singleton::Instance()->fin;
		//Kol nepasibaiges file
		while (!Singleton::Instance()->fin.eof())
		{
			//Iraso skaicius i masyvas
			X[x] = Singleton::Instance()->ivedimas();
			Y[x] = Singleton::Instance()->ivedimas();
			x++;

		}
		for (int k = 0; k < x; k++)
		{
			butina = k + 1;

			for (int m = butina; m < x; m++)
			{
				for (int n = butina+1; n < x; n++)
				{
					if (n > k && n>m)
					{
						//Apskaiciuoja pirma atkarpa
						TrikampioAtkarpos[0] = AtkarposIlgis(X, Y, k, m);
						//Apskaiciuoja antra atkarpa
						TrikampioAtkarpos[1] = AtkarposIlgis(X, Y, k, n);
						//Apskaiciuoja trecia atkarpa
						TrikampioAtkarpos[2] = AtkarposIlgis(X, Y, m, n);
						//Patikrina ar status trikampis
						status = StatusT(TrikampioAtkarpos);
						if (status == true)
						{
							isvedimas(fout, X,Y,k,m,n);
						}
					}
				}
				butina++;
			}	
		}
		this->label1->Text = L"Programa baige savo darba";	
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
