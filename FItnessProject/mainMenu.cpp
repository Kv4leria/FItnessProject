#include <iostream>
#include "User.h"
using namespace std; 

int main() {
	 
	int choice;
	do {

		cout << "\n -- Fitness Menu-- \n";
		cout << "1. Register" << endl;
		cout << "2. Login as User" << endl;
		cout << "3. Login as a Coach" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;

		//if (choice == 1)

	} while (choice != 4);

	return (0);
}