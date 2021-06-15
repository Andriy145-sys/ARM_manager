#pragma once
#include <string>
using namespace std;
class Goods {
private:
	int ID;
	string Nazv_v, Model,Type,Type_coll ,Countr_v;
	int Eng_cap,Num_of_horse_power,Price_per_piece;
public:
	//get
int getID(int ID) { return ID; };
string getNazv_v_model(string Nazv_v_model) { return Nazv_v_model; };
string getType(string Type) { return Type; };
int getEng_cap(int Eng_cap) { return Eng_cap; };
int getNum_of_horse_power(int Num_of_horse_power) { return Num_of_horse_power; };
string getType_coll(string Type_coll) { return Type_coll; };
string getCountr_v(string Countr_v) { return Countr_v; };
int getPrice_per_piece(int Price_per_pice) { return Price_per_pice; };
    
Goods();
~Goods();
void Print(string Motof);
void AddMoto(string Motof);
void SearchMoto(string Motof, string word_fn, int v);
int SearchMoto(string Motof, string word_fn,string nazv);
void Models(string Motof);
void Parametrs(int Id,string N,string M,string T, string TC, string Cv, int E,int Nh,int PPP);
void ChangeMoto(string Motof);
void DeleteMoto(string Motof);
int Kil(string Motof);
};
