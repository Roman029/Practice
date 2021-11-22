#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>


#include "Clear.h"
#include "Employee.h"
#include "Material.h"
#include "Shoes.h"
#include "Customer.h"
using namespace std;

const string path_file_employee = "database_employee.txt";
const string path_file_material = "database_material.txt";
const string path_file_customer = "database_customer.txt";

void ShowEmployee();
void MenuMaterials(vector<Material>& my_materials);
void ShowMaterials(const vector<Material>& my_materials);
string BuyNewMaterials(const vector<string>& all_material);
void MakeShoes(vector<Shoes>& my_shoes, vector<Material>& my_materials);
void ShowShoes(const vector<Shoes>& my_shoes);
void ShowCustomer();