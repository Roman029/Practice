#include "Employee.h"

Employee::Employee()
{
	name = "Unknown";
	surname = "Unknown";
	position = "Unknown";
}

Employee::Employee(string new_name, string new_surname, string new_position)
{
	name = new_name;
	surname = new_surname;
	position = new_position;
}

string Employee::GetName() const
{
	return name;
}

string Employee::GetSurname() const
{
	return surname;
}

string Employee::GetPosition() const
{
	return position;
}
