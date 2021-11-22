#include "FunctionsMainMenu.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	vector<Material> my_materials;
	vector<Shoes> my_shoes;

	while (true)
	{
		system("cls");
		cout << "Клавiша 1 - Переглянути працівників фабрики" << endl;
		cout << "Клавiша 2 - Купити матеріали для виготовлення взуття" << endl;
		cout << "Клавiша 3 - Переглянути куплені матеріали" << endl;
		cout << "Клавiша 4 - Зробити взуття" << endl;
		cout << "Клавiша 5 - Переглянути зроблене взуття" << endl;
		cout << "Клавiша 6 - Переглянути замовників фабрики" << endl;
		cout << "Клавiша 7 - Вихід з програми" << endl;

		char choice;
		cin >> choice;

		if (choice == '1' && cin.peek() == '\n')
		{
			ShowEmployee();
		}
		else if (choice == '2' && cin.peek() == '\n')
		{
			MenuMaterials(my_materials);
		}
		else if (choice == '3' && cin.peek() == '\n')
		{
			ShowMaterials(my_materials);
		}
		else if (choice == '4' && cin.peek() == '\n')
		{
			MakeShoes(my_shoes, my_materials);
		}
		else if (choice == '5' && cin.peek() == '\n')
		{
			ShowShoes(my_shoes);
		}
		else if (choice == '6' && cin.peek() == '\n')
		{
			ShowCustomer();
     	}
		else if (choice == '7' && cin.peek() == '\n')
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
	return 0;
}