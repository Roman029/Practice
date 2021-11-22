#pragma once
#include <string>
using namespace std;

class Material
{
public:
	Material();
	
	Material(string new_name_of_material, int new_quantity);
	
	string GetName_of_material() const;
	
	int GetQuantity() const;

	friend Material operator+(const Material& obj, int value);

	friend Material operator-(const Material& obj, int value);

	friend bool operator >= (const Material& obj, int value);
	
private:
	string name_of_material;
	int quantity;
};

