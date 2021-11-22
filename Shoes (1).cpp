#include "Shoes.h"

Shoes::Shoes()
{
	type_of_shoes = "Unknown";
	gender = "Unknown";
	size = 0;
}

Shoes::Shoes(string new_type_of_shoes, string new_gender, int new_size)
{
	type_of_shoes = new_type_of_shoes;
	gender = new_gender;
	size = new_size;
}

string Shoes::GetType_of_shoes() const
{
	return type_of_shoes;
}

string Shoes::GetGender() const
{
	return gender;
}

int Shoes::GetSize() const
{
	return size;
}

istream& operator >> (istream& input, Shoes& obj)
{
	cout << "Введіть тип взуття (літнє/зимове): ";
	input >> obj.type_of_shoes;
	cout << "Введіть тип взуття (чоловіче/жіноче): ";
	input >> obj.gender;
	cout << "Введіть розмір взуття: ";
	input >> obj.size;

	while (input.fail())
	{
		Clear_stream(input);
		input >> obj.size;
	}

	return input;
}
