#include<iostream>
#include<windows.h>
#include "Option 4.h"
#include "Option 3.h"
#include "Option 2.h"
#include "Option 1.h"

using namespace std;
int main()
{
		while (1) {
			system("cls");
			system("color E");
			cout <<"\n\t\t\t\t\t\t *Welcome to our project! * \t\t\n\n";
			cout << "1-implement stack using queue " << endl;
			cout << "2-implement queue using stack " << endl;
			cout << "3-reverse linked list items using stack " << endl;
			cout << "4-level order of BST traverse using using queue " << endl;
			cout << "5-Exit " << endl;
			cout << "Please enter your choice :  ";
			int choice;
			cin >> choice;
			system("cls");
			switch (choice) {
			case 1:
				Option1();
				break;
			case 2:
				Option2();
				break;
			case 3:
				Option3();
				break;
			case 4:
				Option4();
				break;
			case 5:
				cout << "\a\a\a\a\n\t\t\t\t\tThanks for visiting our program ! \t\t\t\t\t\n\n\n\n\n";
				return 0;
			default:
				cout << "This Option is invalid.\n Please select one of the 5 existed options." << endl;
				break;
 
			}
			system("pause");
		}

}
