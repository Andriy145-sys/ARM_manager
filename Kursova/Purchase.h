#pragma once
#include<string>

using namespace std;

class Purchase {
	int ID;
	int Number;
	string Date_of_sale;
	int ID_goods, ID_customer;
	int Purchase_amout;
public:
	//get
	int getID(int ID) { return ID; };
	int getNumber(int Number) { return Number; };
	string getDate_of_sale(string Date_of_sale) { return Date_of_sale; };
	int getID_goods(int ID_goods) { return ID_goods; };
	int getPurchase_amout(int Purchase_amout) { return Purchase_amout; };
	Purchase();
	~Purchase();
	void PurParametrs(int Id,int Num,int Id_god,int Id_cust, int Pa, string Date);
	void AddPurchase(string Purchasef);
	void PrintDate(string Purchasef,string date);
	void PrintPurchase(string Purchasef);
	void SearchDate(string Purchasef, string poch_date);
};
