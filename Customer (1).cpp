#include "Customer.h"

Customer::Customer()
{
	name_of_company = "Unknown";
	address = "Unknown";
	telephone = "+380xxxxxxx";
}

Customer::Customer(string new_name_of_company, string new_address, string new_telephone)
{
	name_of_company = new_name_of_company;
	address = new_address;
	telephone = new_telephone;
}

string Customer::GetName_of_company() const
{
	return name_of_company;
}

string Customer::GetAddress() const
{
	return address;
}

string Customer::GetTelephone() const
{
	return telephone;
}

ostream& operator << (ostream& output, const Customer& obj)
{
	output << setw(30) << obj.GetName_of_company()
		<< setw(30) << obj.GetAddress()
		<< setw(30) << obj.GetTelephone();

	return output;
}
