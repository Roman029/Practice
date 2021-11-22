#include "FunctionsMainMenu.h"

void ShowEmployee() 
{
	while (true)
	{
		system("cls");
		ifstream fin_employee(path_file_employee);
		vector<Employee> all_emloyee;

		if (fin_employee)
		{
			string name, surname, position;
			while (fin_employee >> name >> surname >> position)
			{
				all_emloyee.push_back({ name, surname, position });
			}
		}
		else
		{
			cout << "Не можливо відкрити файл" << endl;
			Sleep(2000);
			break;
		}

		for (size_t i = 0; i < all_emloyee.size(); i++)
		{
			if (i == 0)
			{
				cout << setw(30) << "Surname" << setw(30) << "Name" << setw(30) << "Position" << endl;
			}

			cout << setw(30) << all_emloyee[i].GetSurname()
			<< setw(30) << all_emloyee[i].GetName()
			<< setw(30) << all_emloyee[i].GetPosition() << endl;
		}

		cout << "Клавiша 1 - Повернутись в головне меню" << endl;
		char choice;
		cin >> choice;
		if (choice == '1' && cin.peek() == '\n')
		{
			break;
		}
		else
		{
			cout << "Некоректна команда, повторiть ввiд" << endl;
			Sleep(2000);
			Clear_stream(cin);
		}
	}
}

void MenuMaterials(vector<Material>& my_materials)
{
	map<string, int> bought_materials;
	while (true)
	{
		system("cls");
		ifstream fin_material(path_file_material);
		vector<string> all_material;

		if (fin_material)
		{
			string line;
			while (getline(fin_material, line))
			{
				all_material.push_back(line);
			}
		}
		else
		{
			cout << "Не можливо відкрити файл" << endl;
			Sleep(2000);
			break;
		}

		for (size_t i = 0; i < all_material.size(); i++)
		{
			if (i == 0)
			{
				cout << setw(1) << "#" << setw(30) << "Name of material" << endl;
			}

			cout << setw(1) << i << setw(30) << all_material[i] << endl;
		}

		cout << "Клавiша 1 - Повернутись в головне меню" << endl;
		cout << "Клавiша 2 - Купити матеріал" << endl;
		char choice;
		cin >> choice;
		if (choice == '1' && cin.peek() == '\n')
		{
			for (auto iter : bought_materials)
			{
				auto res = find_if(my_materials.begin(), my_materials.end(), [iter](const Material& m)
					{
						return m.GetName_of_material() == iter.first;
					});

				if (res == my_materials.end())
				{
					my_materials.push_back({ iter.first, iter.second });
				}
				else
				{
					my_materials[res - my_materials.begin()] = Material(iter.first, iter.second + res->GetQuantity());
				}
			}

			break;
		}
		if (choice == '2' && cin.peek() == '\n')
		{
			bought_materials[BuyNewMaterials(all_material)]++;
		}
		else
		{
			cout << "Некоректна команда, повторiть ввiд" << endl;
			Sleep(2000);
			Clear_stream(cin);
		}

	}
}

string BuyNewMaterials(const vector<string>& all_material)
{
	while (true)
	{
		cout << "Введіть номер матеріла, який хочете купити" << endl;
		char choice;
		cin >> choice;

		if (choice == '0' && cin.peek() == '\n')
		{
			cout << "Куплено успішно" << endl;
			Sleep(2000);
			return all_material[0];
		}
		else if (choice == '1' && cin.peek() == '\n')
		{
			cout << "Куплено успішно" << endl;
			Sleep(2000);
			return all_material[1];
		}
		else if (choice == '2' && cin.peek() == '\n')
		{
			cout << "Куплено успішно" << endl;
			Sleep(2000);
			return all_material[2];
		}
		else
		{
			cout << "Некоректна команда, повторiть ввiд" << endl;
			Sleep(2000);
			Clear_stream(cin);
		}
	}
}

void ShowMaterials(const vector<Material>& my_materials)
{
	while (true)
	{
		system("cls");
		for (size_t i = 0; i < my_materials.size(); i++)
		{
			if (i == 0)
			{
				cout << setw(30) << "Name of material" << setw(30) << "Quantity" << endl;
			}

			cout << setw(30) << my_materials[i].GetName_of_material()
				<< setw(30) << my_materials[i].GetQuantity() << endl;
		}

		cout << "Клавiша 1 - Повернутись в головне меню" << endl;
		char choice;
		cin >> choice;
		if (choice == '1' && cin.peek() == '\n')
		{
			break;
		}
		else
		{
			cout << "Некоректна команда, повторiть ввiд" << endl;
			Sleep(2000);
			Clear_stream(cin);
		}
	}
}

void MakeShoes(vector<Shoes>& my_shoes, vector<Material>& my_materials)
{
	while (true)
	{
		system("cls");

		cout << "Для виробництва взуття потрібно: " << endl;
		cout << "Гума - 2 одиниці" << endl;
		cout << "Велюр - 1 одиниця" << endl;
		cout << "Деревина - 1 одиниця" << endl;


		cout << "Клавiша 1 - Повернутись в головне меню" << endl;
		cout << "Клавiша 2 - Зробити взуття" << endl;
		char choice;
		cin >> choice;
		if (choice == '1' && cin.peek() == '\n')
		{
			break;
		}
		else if (choice == '2' && cin.peek() == '\n')
		{
			auto rubber = find_if(my_materials.begin(), my_materials.end(), [](const Material& m)
				{
					return m.GetName_of_material() == "Natural rubber";
				});

			auto velour = find_if(my_materials.begin(), my_materials.end(), [](const Material& m)
				{
					return m.GetName_of_material() == "Velour";
				});

			auto wood = find_if(my_materials.begin(), my_materials.end(), [](const Material& m)
				{
					return m.GetName_of_material() == "Wood";
				});

			if (rubber != my_materials.end() && velour != my_materials.end() && wood != my_materials.end()
				&& *rubber >= 2 && *velour >= 1 && *wood >= 1)
			{
				Shoes obj;

				cin >> obj;

				/*
				string type_of_shoes, gender;
				int size;

				cout << "Введіть тип взуття (літнє/зимове): ";
				cin >> type_of_shoes;
				cout << "Введіть тип взуття (чоловіче/жіноче): ";
				cin >> gender;
				cout << "Введіть розмір взуття: ";
				cin >> size;

				while(cin.fail())
				{
					Clear_stream(cin);
					cin >> size;
				}

				my_shoes.push_back({ type_of_shoes, gender, size });
				*/

				my_shoes.push_back(obj);

				*rubber = *rubber - 2;
				*velour = *velour - 1;
				*wood = *wood - 1;

				cout << "Зроблено успішно" << endl;
				Sleep(2000);
			}
			else
			{
				cout << "Не достатньо матеріалів для виготовлення взуття" << endl;
				Sleep(2000);
			}

		}
		else
		{
			cout << "Некоректна команда, повторiть ввiд" << endl;
			Sleep(2000);
			Clear_stream(cin);
		}
	}
}

void ShowShoes(const vector<Shoes>& my_shoes)
{
	while (true)
	{
		system("cls");
		for (size_t i = 0; i < my_shoes.size(); i++)
		{
			if (i == 0)
			{
				cout << setw(20) << "Type of shoes" << setw(20) << "Gender" << setw(20) << "Size" << endl;
			}
			cout << setw(20) << my_shoes[i].GetType_of_shoes() << setw(20) << my_shoes[i].GetGender() 
				<< setw(20) << my_shoes[i].GetSize() << endl;
		}

		cout << "Клавiша 1 - Повернутись в головне меню" << endl;
		char choice;
		cin >> choice;
		if (choice == '1' && cin.peek() == '\n')
		{
			break;
		}
		else
		{
			cout << "Некоректна команда, повторiть ввiд" << endl;
			Sleep(2000);
			Clear_stream(cin);
		}
	}
}

void ShowCustomer()
{
	while (true)
	{
		system("cls");
		ifstream fin_customer(path_file_customer);
		vector<Customer> all_customer;

		if (fin_customer)
		{
			string name_of_company, address, telephone;
			while (fin_customer >> name_of_company >> address >> telephone)
			{
				all_customer.push_back({ name_of_company, address, telephone });
			}
		}
		else
		{
			cout << "Не можливо відкрити файл" << endl;
			Sleep(2000);
			break;
		}

		for (size_t i = 0; i < all_customer.size(); i++)
		{
			if (i == 0)
			{
				cout << setw(30) << "Name of company" << setw(30) << "Address" << setw(30) << "Telephone" << endl;
			}

			cout << all_customer[i] << endl;
		}

		cout << "Клавiша 1 - Повернутись в головне меню" << endl;
		char choice;
		cin >> choice;
		if (choice == '1' && cin.peek() == '\n')
		{
			break;
		}
		else
		{
			cout << "Некоректна команда, повторiть ввiд" << endl;
			Sleep(2000);
			Clear_stream(cin);
		}
	}
}