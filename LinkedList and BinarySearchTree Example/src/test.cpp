

#include <iostream>
#include "LinkedList.hpp"

using namespace std;
int main()
{
	system("cls");

	LinkedList *list = new LinkedList();
	int choice = 0;
	string number;

	cout << "Enter Number:";
	cin >> number;

	for (int i = 0; i < number.length(); i++)
	{
		int x = (int)number[i] - 48;
		list->Add(x);
	}

	do
	{
		system("cls");

		cout << "1.Delet MAX value from Trees" << endl;
		cout << "2.Delet MIN value from Trees" << endl;
		cout << "3.Lever Order print" << endl;
		cout << "0.Exit" << endl;
		cout << "[Entered Number : " << number << "]" << endl;
		cout << "\nChoice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			list->DeleteMaxNode();
			break;
		case 2:
			list->DeleteMinNode();
			break;
		case 3:

			list->printNodes();
			break;

		case 0:

			break;
		default:
			cout << endl
				 << "Wrong Choice...!" << endl;

			break;
		}
		cin.ignore();
		cin.get();
		system("cls");

	} while (choice != 0);

	delete list;
}