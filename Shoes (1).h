#pragma once
#include <string>
#include <iostream>
#include "Clear.h"
using namespace std;

class Shoes
{
public:
	Shoes();
	
	Shoes(string new_type_of_shoes, string new_gender, int new_size);
	
	string GetType_of_shoes() const;
	
	string GetGender() const;
	
	int GetSize() const;
	
	friend istream& operator >> (istream& input, Shoes& obj);

private:
	string type_of_shoes, gender;
	int size;
};

