#include"Purchase.h"
#include"Customer.h"
#include<fstream>
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

Purchase::Purchase() {
	ID = 0;
	Number = 0;
	Date_of_sale = "0";
    ID_goods = 0;
	ID_customer = 0;
    Purchase_amout = 0;
}
Purchase::~Purchase() {

}
void Purchase::PurParametrs(int Id, int Num, int Id_god, int Id_cust, int Pa, string Date){
	ID = Id;
	Number = Num;
	Date_of_sale = Date;
	ID_goods = Id_god;
	ID_customer = Id_cust;
	Purchase_amout = Pa;
}
void Purchase::AddPurchase(string Purchasef){
	fstream fs;
	fs.open(Purchasef, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open()) {
		cout << "Помилка відкриття файлу" << endl;

	}
	else {
		fs <<"ID: "<< ID << endl;
		fs << "Кількість:" << Number << endl;
		fs << "ID мотоцикла:" << ID_goods << endl;
		fs << "ID покупця:" << ID_customer << endl;
		fs << "Дата продажу:" << Date_of_sale;
		fs << "Сума покупки:" << Purchase_amout << endl;
		fs << "_________________________________" << endl;
	}
	fs.close();
}
void Purchase::PrintPurchase(string Purchasef)
{	char* str = new char[1024];
	int a = 0;
	Customer cust;
	fstream fs, fss;
	fs.open(Purchasef, fstream::in);
	fss.open(Purchasef, fstream::in);
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
void Purchase::PrintDate(string Purchasef,string date)
{
	std::vector <std::string> v;
	fstream purchase(Purchasef, ios::in);
	string line, s;
	int a=0;
	while (getline(purchase, line))
	{
		v.push_back(line);
		a++;
		size_t search = line.find(date);

		if (search != string::npos)
		{
			for (int s = a - 6; s < a; s++) {
				cout << v[s] << endl;
			}
		}
	}
	purchase.close();
	system("pause");
}
void Purchase::SearchDate(string Purchasef, string poch_date)
{
	char* str = new char[1024];
	int a = 0, b = 0;
	string word_in, line;
	ifstream in(Purchasef, ios::in);
	fstream fs("Bufer.txt", ios::out, ios::trunc);
	vector<string>v;
	while (getline(in, line))
	{
		v.push_back(line);
	}
	in.close();

	while (in >> word_in) {

		if (word_in == poch_date)
		{a++;
			in.getline(str, 1024, '\n');
			cout << a;
			for (int i = a + 15; i > a; i--) {
				in.getline(str, 1024);
				cout << str << endl;
			}
			in.close();

		}
		
	}system("pause");
		system("cls");
}
