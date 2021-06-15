#include<iostream>
#include<fstream>
#include<vector>
#include<windows.h>
#include"Goods.h"

using namespace std;

Goods::Goods() {
	ID = 0;
	Nazv_v = "Немає інформації";
	Model="Немає iнформацiї";
	Type="Немає iнформацiї";
	Type_coll="Немає iнформацiї";
	Countr_v="Немає iнформацiї";
	Eng_cap=0;
	Num_of_horse_power=0;
	Price_per_piece=0;
}
Goods::~Goods(void) 
{
}
void Goods::Print(string Motof) {
	char* str = new char[1024];
	int a=0;
	fstream fs, fss;
	fs.open(Motof, fstream::in);
	fss.open(Motof, fstream::in);
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
void Goods::Parametrs(int Id,string N,string M, string T, string Tc, string Cv,int E, int Nh,int PPP){
	ID = Id;
	Nazv_v = N;
	Model = M;
	Type = T;
	Type_coll = Tc;
	Countr_v = Cv;
	Eng_cap = E;
	Num_of_horse_power = Nh;
	Price_per_piece = PPP;
}
void Goods::AddMoto(string Motof)
{
	fstream fs;
	fs.open(Motof, fstream::out | fstream::app);
	if (!fs.is_open()) {
		cout << "Помилка відкриття файлу" << endl;

	}
	else {
		fs << "\tМотоцикл:" << Nazv_v<<" "<< Model << endl;
		fs << "ID: " << ID<<endl;
		fs <<"Назва виробника:"<< Nazv_v<<endl;
		fs << "Модель:" << Model << endl;
		fs << "Тип:" << Type << endl; 
		fs << "Тип охолодження:" << Type_coll << endl;
		fs << "Об'єм двигуна:" << Eng_cap <<"cм3"<< endl;
		fs << "Кількість кінських сил:" << Num_of_horse_power << endl;
		fs << "Країна виробник:" << Countr_v << endl;
		fs << "Ціна за одиницю:" << Price_per_piece <<"$"<< endl;
		fs << "_________________________________" << endl;
	}
	fs.close();
}
void Goods::SearchMoto(string Motof, string word_fn, int v)
{
	char* str = new char[1024];
	int a = 0;
	string word_in;
	ifstream in(Motof, ios::in);
	switch (v)
	{
	case 1: {
		while (in >> word_in)

			if (word_in == word_fn)
			{
				in.getline(str, 1024, '\n');
				a++;
				int b = a;
				for (int i = b + 8; i >= b; i--) {
					in.getline(str, 1024);
					cout << str << endl;
				}
				in.close();
			}

	}break;
	case 2: {
		while (in >> word_in)

			if (word_in == word_fn)
			{
				in.getline(str, 1024, '\n');
				a++;
				for (int i = a + 9; i >= a; i--) {
					in.getline(str, 1024);
					cout << str << endl;
				}
				in.close();
			}}break;
	default:cout << "Введіть правильне значення\n";
		break;
	}
	}
int Goods::SearchMoto(string Motof, string word_fn, string nazv){
	char* str = new char[1024];
	int a = 0,b=0;
	string word_in;
	ifstream in(Motof, ios::in);
	fstream fs("Bufer.txt", ios::out, ios::trunc);

	while (in >> word_in) {
		a++;
		if (word_in == word_fn)
		{
			in.getline(str, 1024, '\n');
			b++;
			fs << "\tМотоцикл:" << nazv << " " << word_fn << endl;
			for (int i = b + 9; i >= b; i--) {
				in.getline(str, 1024);
				fs << str << endl;
			}
			in.close();
			fs.close();
			return a;
			a = 0;
		}
	}
}
void Goods::Models(string Motof) {
	string line;
	ifstream Moto(Motof, ios::in);
	vector<string>model;
	while (getline(Moto, line))
	{
		model.push_back(line);
	}
	for (int i = 0; i < model.size(); i += 11) {
		cout << model[i] << endl;
	}
	Moto.close();
}
int Goods::Kil(string Motof){
	char* str = new char[1024];
	int a = 0;
	fstream fs(Motof, ios::in);
	while (!fs.eof())
	{
		fs.getline(str, 1024, '\n');
		a++;
	}fs.close();
	return a/10;
}
void Goods::ChangeMoto(string Motof) {
	ifstream Motoin(Motof, ios::in);
	string line, nazv, word_fn, lines,eng,hor,price,id;
	int a, i,e = 0;
	vector<string>changemoto;
	//Ввід потрібних даних
	cout << "\t\tЗміна параметрів мотоцикла\n";
	cout << "Доступні мотоцикли:\n";
	Models(Motof);
    cout<<"\nВведіть стару назву виробника мотоцикла: ";
	cin >> nazv;
	cout << "Введіть стару модель: ";
	cin >> word_fn;

	a = SearchMoto(Motof, word_fn, nazv);//Виклик функції пошуку мотоциклів
	//зчитування мотоциклів з бази даних
	while (getline(Motoin, line))
	{
		changemoto.push_back(line);
	}
	Motoin.close();

	//створення тимчасового вектора для нових даних
	vector<string>t;
	//ввід нових даних
	cout << "Щоб продовжити введіть id мотоцикла\nID:";
	cin >> id;
	t.push_back(id);
	cout << "Введіть нову назву виробника:";
	cin >> Nazv_v;
	t.push_back(Nazv_v);
	cout << "Введіть нову модель: ";
	cin >> Model;
	t.push_back(Model);
	cout << "Введіть новий тип: ";
	cin >> Type;
	t.push_back(Type);
	cout << "Введіть новий тип охолодження: ";
	cin >> Type_coll;
	t.push_back(Type_coll);
	cout << "Введіть новий об'єм двигуна: ";
	cin >> eng;
	t.push_back(eng);
	cout << "Введіть нову кількість кінських сил: ";
	cin >> hor;
	t.push_back(hor);
	cout << "Введіть нову країну виробника: ";
	cin >> Countr_v;
	t.push_back(Countr_v);
	cout << "Введіть нову ціну за одиницю: ";
	cin >> price;
	t.push_back(price);
	//Створення буфера для тимчасового збереження нових мотоциклів
	ofstream Bufer("Bufer.txt", ios::out);
	//Запис нового значення в тимчасовий буфер
	while (e < t.size()) {
	    Bufer << "\tМотоцикл:" << t[e+1] << " "<< t[e+2] << endl;
		e = 0;
		Bufer << "ID: " << t[e++]<<endl;
		Bufer << "Назва виробника: " << t[e++] << endl;
		Bufer << "Модель:" << t[e++] << endl;
		Bufer << "Тип:" << t[e++] << endl;
		Bufer << "Тип охолодження:" << t[e++] << endl;
		Bufer << "Об'єм двигуна:" <<t[e++]<<"см3"<< endl;
		Bufer << "Кількість кінських сил:"<<t[e++] << endl;
		Bufer << "Країна виробник:" << t[e++] << endl;
		Bufer << "Ціна за одиницю:" <<t[e++]<<"$"<< endl;
		Bufer << "_________________________________" << endl;
		e++;
	}Bufer.close();
	t.clear();//очищення вектора
	ifstream Buferin("Bufer.txt", ios::in);
	//Зчитування значення з тимчасового буфера
	while (getline(Buferin, line))
	{
		t.push_back(line);
	}
	//зміна для 1 елемента
	if (a == 2)
	{
		a -=2;
		i = a + 11;
		auto iter3 = changemoto.cbegin();
		changemoto.erase(changemoto.begin(), changemoto.begin() + i);//видалення старих значень
		changemoto.insert(iter3, t.begin(), t.begin() + t.size());//запис нових значень
	}
	else {//зміна для всіх інших елементів
		a /= 2;
		a += 11;
		i = a - 11;
		auto iter3 = changemoto.cbegin();
		changemoto.erase(changemoto.begin() + i, changemoto.begin() + a);//видалення старих значень
	    changemoto.insert(iter3 + i, t.begin(), t.begin() + t.size());//запис нових значень
	}
	//Вивід в базу даних нових значень
	ofstream Motoout(Motof, ios::out, ios::trunc);
	for (int e = 0; e < changemoto.size(); e++) {
		Motoout << changemoto[e] << endl;
	}
	system("pause");
	system("cls");
}
void Goods::DeleteMoto(string Motof)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string line, nazv, word_fn;
	int a,i;
//Ввід потрібних даних
	cout << "Введіть назву виробника: ";
	cin >> nazv;
	cout << "Введіть модель: ";
	cin >> word_fn;

//Зчитування даних з файлу у вектор
fstream Moto(Motof, ios::in);
vector<string>motodb;
motodb.clear();
	while (getline(Moto, line))
	{
		motodb.push_back(line);
	}
	Moto.close();
a = SearchMoto(Motof, word_fn, nazv);//Виклик функції пошуку мотоциклів
if(a==2)//видалення для 1 елемента
{
	a-=a;
	i = a + 11;
	motodb.erase(motodb.begin() + a, motodb.begin() + i);
	cout << "Мотоцикл успішно видалено\n";
}
else if(a>2 && a<=motodb.size()){
	a /= 2;
	a += 11;
	i = a - 11;
	motodb.erase(motodb.begin() + i, motodb.begin() + a);
	cout << "Мотоцикл успішно видалено\n";
}
else { cout << "Мотоцикла "<<nazv<<" "<<word_fn<<" немає в базі даних\n";}
//Вивід вектора у файл
	ofstream Motoout(Motof, ios::out, ios::trunc);
	for (int i = 0; i <motodb.size(); i++)
	{
		Motoout << motodb[i] << endl;
	}
	Motoout.close();
		system("pause");
}