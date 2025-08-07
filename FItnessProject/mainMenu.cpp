#include <iostream>
#include <vector>
#include "User.h"
#include "FitnessProfile.h"
#include "coachDashboard.h"
using namespace std;  

vector <User> users;

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
		
		//else if (choice == 

		/*else*/ if (choice == 3) {
			string username, password;

			FitnessProfile coachProfile{ 0.0,0.0,0.0,0,"", "" };
			User demoCoach("demoCoach", "123", coachProfile);

			cout << "------Login------" << endl;
			cout << "Username: ";
			cin >> username;
			cout << "\nPassword: ";
			cin >> password;
			if (username == demoCoach.getUsername() && password == demoCoach.getPassword()) {
				coachDashboard dashboard(demoCoach);
				dashboard.run();
			}
			else {
				cout << "Incorrect username or password";
				continue;
			}
		}

	} while (choice != 4);

	return (0);
}