#pragma once
#include <string>
using namespace std;

class Employee
{
public:
	Employee();
	
	Employee(string new_name, string new_surname, string new_position);
	
	string GetName() const;

	string GetSurname() const;
	
	string GetPosition() const;

private:
	string name, surname, position;
};

