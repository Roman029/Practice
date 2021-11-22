#pragma once
#include <string>
#include <iomanip>
using namespace std;

class Customer
{
public:
	Customer();
	
	Customer(string new_name_of_company, string new_address, string new_telephone);
	
	string GetName_of_company() const;
	
	string GetAddress() const;
	
	string GetTelephone() const;

	friend ostream& operator << (ostream& output, const Customer& obj);
	
private:
	string name_of_company, address, telephone;
};

