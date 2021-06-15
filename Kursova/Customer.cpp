#include"Customer.h"
#include<fstream>
#include <iostream>

using namespace std;

Customer::Customer() {
    ID= 0;
    lastname = "Немає інформації";
    name = "Немає інформації";
    surname="Немає інформації";
    N_password = "Немає інформації";
}
Customer::~Customer(){}
void Customer::CusParametrs(int Id_cust,string P, string I, string B, string N_p) {
	ID = Id_cust;
	lastname = P;
    name = I;
    surname = B;
    N_password = N_p;
}
void Customer::AddCustomer(string Customerf) {
	fstream fs;
	fs.open(Customerf, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open()) {
		cout << "Помилка відкриття файлу" << endl;

	}
	else {
		fs <<"ID: "<< ID << endl;
		fs << "№ паспорта:" << N_password << endl;
		fs << "ПІБ:" << lastname<<" "<<name<<" "<<surname << endl;
		fs << "_________________________________" << endl;
	}
	fs.close();
}
void Customer::PrintCustomer(string Customerf)
{
	char* str = new char[1024];
	int a = 0;
	fstream fs, fss;
	fs.open(Customerf, fstream::in);
	fss.open(Customerf, fstream::in);
	if (!fs.is_open()) {
		cout << "Помилка відкриття файлу" << endl;

	}
	else {
		while (!fs.eof())
		{
			fs.getline(str, 1024, '\n');
			a++;
		}fs.close();
		for (int i = 0; i < a; i++) {
			fss.getline(str, 1024);
			cout << str << endl;
		}
		fss.close();
	}
	system("pause");
	system("cls");
}
void Customer::SearchCustomer(string Customerf, string word_fn)
{
	char* str = new char[1024];
	int a = 0;
	string word_in;
	ifstream in(Customerf, ios::in);
	while (in >> word_in)

		if (word_in == word_fn)
		{
			in.getline(str, 1024, '\n');
			a++;
			int b = a;
			cout << "ID: " << word_fn << endl;
			for (int i = b - 2; i <= b; i++) {
				in.getline(str, 1024);
				cout << str << endl;
			}
			in.close();
		}
}
