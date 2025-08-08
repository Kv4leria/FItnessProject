#include <iostream>
#include <vector>
#include "User.h"
#include "FitnessProfile.h"
#include "coachDashboard.h"
using namespace std; 

vector <User> users; // All registeres users 

void registerUser(coachDashboard& dashboard) {

	string username;
	string password;
	FitnessProfile profile;

	cout << "--- Registration ---" << endl; 
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	cout << "Current weight: ";
	cin >> profile.currentweight;

	cout << "Goal weight:  ";
	cin >> profile.goalWeight;

	cout << "Height in cm: ";
	cin >> profile.height;

	cout << "Age: ";
	cin >> profile.height;

	cout << "Gender: ";
	cin >> profile.gender;

	cout << "Activity Level (Light / Moderate / Heavy (Athlete) ): ";
	cin >> profile.activityLevel;

	User newUser(username, password, profile);
	users.push_back(newUser);
	dashboard.addClientFromUser(users.back());

	cout << "Registration successful! You've been assigned to a coach!" << endl;


}


int main() {

	FitnessProfile coachProfile{ 0.0,0.0,0.0,0,"", "" };
	User demoCoach("demoCoach", "123", coachProfile);
	coachDashboard dashboard(demoCoach);

	int choice;


	do {

		cout << "\n -- Fitness Menu-- \n";
		cout << "1. Register" << endl;
		cout << "2. Login as User" << endl;
		cout << "3. Login as a Coach" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;

		/*else*/ if (choice == 3) {
			string username, password;

			if (choice == 1) {

				registerUser(dashboard);

			}

			//else if

			else  if (choice == 3) {
				string username, password;



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

		}
		

		
	}
	while (choice != 4);
	return (0);
}