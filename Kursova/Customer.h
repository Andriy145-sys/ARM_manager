#pragma once
#include <string>
using namespace std;

class Customer{
    int ID;
    string lastname,name,surname,N_password;

    public:
    //get
    int getID(int ID) { return ID; };
    string getPIB(string PIB) { return PIB; }
    string getN_password(string N_password) {return N_password; }
    Customer();
    ~Customer();
    void CusParametrs(int ID_cust,string P,string I, string B, string N_p);
    void AddCustomer(string Customerf);
    void PrintCustomer(string Customerf);
    void SearchCustomer(string Customerf, string word_fn);
 

};
