#include "Material.h"

Material::Material()
{
	name_of_material = "Unknown";
	quantity = 0;
}

Material::Material(string new_name_of_material, int new_quantity)
{
	name_of_material = new_name_of_material;
	quantity = new_quantity;
}

string Material::GetName_of_material() const
{
	return name_of_material;
}

int Material::GetQuantity() const
{
	return quantity;
}

Material operator+(const Material& obj, int value)
{
	return Material(obj.GetName_of_material(), obj.GetQuantity() + value);
}

Material operator-(const Material& obj, int value)
{
	return Material(obj.GetName_of_material(), obj.GetQuantity() - value);
}

bool operator>=(const Material& obj, int value)
{
	if (obj.GetQuantity() >= value)
	{
		return true;
	}
	return false;
}

