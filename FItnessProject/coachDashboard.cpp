#include "coachDashboard.h"
#include "User.h"
#include <iostream>

coachDashboard::coachDashboard(const User& loggedInCoach)
	: loggedInCoach(loggedInCoach) {
}


//These 3 methods handle the viewing and updating of the workouts
coachDashboard::Workout::Workout() {
	for (int i = 0; i < 7; i++) {
		Workouts[i] = "Rest";
	}
}

void coachDashboard::Workout::viewWorkout() {
	string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	for (int i = 0; i < 7; i++) {
		cout << days[i] << ":" << Workouts[i] << endl;
	}
}

void coachDashboard::Workout::update(int day, string& newWorkout) {
	if (day >= 0 && day < 7) {
		Workouts[day] = newWorkout;
	}
	else {
		cout << "Invalid day" << endl;
	}
}


//This is for the progress page (not done yet, will have to grab from user)
void coachDashboard::Progress::viewProgress() {
	cout << "Not completed yet";
}

//The following methods take care of viewing specific clients and editing individual workouts
coachDashboard::Client::Client(const std::string& name) : name(name) {}

string coachDashboard::Client::Client::getName() {
	return name;
}

void coachDashboard::Client::viewClientProgress() {
	progress.viewProgress();
}

void coachDashboard::Client::viewClientWorkouts() {
	workoutPlan.viewWorkout();
}






void coachDashboard::Client::editWorkouts() {
	int day;
	string newWorkout;
	string daysofWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	cout << "Enter day number to edit workout for: \n 0 = Sunday \n 1 = Monday \n 2 = Tuesday \n 3 = Wednesday \n 4 = Thursday \n 5 = Friday \n 6 = Saturday" << endl;
	cin >> day;
	cout << endl;


	cout << "Enter workout for " << daysofWeek[day] << ":";
	cin.ignore();
	getline(cin, newWorkout);

	workoutPlan.update(day, newWorkout);
	cout << "Succesfully updated" << endl;
	cout << endl;
	
}

//These methods are the UI for the coach dashboard itself, we could move this to main)
void coachDashboard::mainMenu() {
	int choice;
	int clientNum;

	while (true) {
		cout << endl;
		cout << "\n |Coach Dashboard| \n";
		cout << "1. View Client List" << endl;
		cout << "2. Exit" << endl;
		cin >> choice;

		if (choice == 1) {
			cout << "Select client: " << endl;
			for (int i = 0; i < clients.size(); i++) {
				cout << i << " = " << clients[i].getName() << endl;
			}

			cout << endl;
			cout << "Enter client number: ";
			cin >> clientNum;
			clientMenu(clients[clientNum]);

		}
		else if (choice == 2) {
			cout << "Exiting dashboard...\n";
			break;
		}

	}

}

void coachDashboard::clientMenu(Client& client) {
	int choice;

	while (true) {
		cout << client.getName() << "\n ----------------" << endl;
		cout << "1. View Progress" << endl;
		cout << "2. View Workouts" << endl;
		cout << "3. Edit Workouts" << endl;
		cout << "4. Back" << endl;
		cout << endl;

		cin >> choice;
		if (choice == 1) {
			client.viewClientProgress();
		}
		else if (choice == 2) {
			client.viewClientWorkouts();
		}
		else if (choice == 3) {
			client.editWorkouts();
		}
		else {
			return;
		}
	}
}

//Put this method in registration to send it over to coach client list
void coachDashboard::addClientFromUser(User& user) {
	clients.push_back(Client(user.getUsername()));
}


void coachDashboard::run() {
	clients.push_back(Client("Matt Lien"));
	clients.push_back(Client("Bob Smith"));
	mainMenu();
}
