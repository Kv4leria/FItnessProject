
#include <iostream>
#include <fstream>
#include <vector>
#include "User.h"
#include "FitnessProfile.h"
#include "coachDashboard.h"
using namespace std;

vector<User> users;

void saveUsersToFile() {
    ofstream outFile("users.txt");
    for (User& user : users) {
        FitnessProfile p = user.getProfile();
        outFile << user.getUsername() << " " << user.getPassword() << " "
                << p.currentweight << " " << p.goalWeight << " " << p.height << " "
                << p.age << " " << p.gender << " " << p.activityLevel << endl;
    }
    outFile.close();
}

void loadUsersFromFile(coachDashboard& dashboard) {
    ifstream inFile("users.txt");
    string username, password, gender, activity;
    double currentWeight, goalWeight, height;
    int age;
    while (inFile >> username >> password >> currentWeight >> goalWeight >> height >> age >> gender >> activity) {
        FitnessProfile profile{ currentWeight, goalWeight, height, age, gender, activity };
        User loadedUser(username, password, profile);
        users.push_back(loadedUser);
        dashboard.addClientFromUser(users.back());
    }
    inFile.close();
}

void userDashboard(User& user) {
    int choice;
    do {
        cout << "\n--- User Dashboard ---\n";
        cout << "1. View Workout Plan\n";
        cout << "2. View Feedback\n";
        cout << "3. Logout\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            vector<string> plan = user.getWorkoutPlan();
            string days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
            for (int i = 0; i < 7; i++) {
                cout << days[i] << ": " << plan[i] << endl;
            }
        }
        else if (choice == 2) {
            cout << "Feedback: " << user.getFeedback() << endl;
        }

    } while (choice != 3);
}

void registerUser(coachDashboard& dashboard) {
    string username, password;
    FitnessProfile profile;

    cout << "--- Registration ---" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    cout << "Current weight: ";
    cin >> profile.currentweight;
    cout << "Goal weight: ";
    cin >> profile.goalWeight;
    cout << "Height in cm: ";
    cin >> profile.height;
    cout << "Age: ";
    cin >> profile.age;
    cout << "Gender: ";
    cin >> profile.gender;
    cout << "Activity Level (Light / Moderate / Heavy (Athlete)): ";
    cin >> profile.activityLevel;

    User newUser(username, password, profile);
    users.push_back(newUser);
    dashboard.addClientFromUser(users.back());

    saveUsersToFile();

    cout << "Registration successful! You've been assigned to a coach!" << endl;
}

int main() {
    FitnessProfile coachProfile{ 0.0,0.0,0.0,0,"", "" };
    User demoCoach("demoCoach", "123", coachProfile);
    coachDashboard dashboard(demoCoach);

    loadUsersFromFile(dashboard); // Load users from file

    int choice;
    do {
        cout << "\n -- Fitness Menu-- \n";
        cout << "1. Register" << endl;
        cout << "2. Login as User" << endl;
        cout << "3. Login as a Coach" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        if (choice == 1) {
            registerUser(dashboard);
        }
        else if (choice == 2) {

            string username, password;
            bool loggedIn = false;

            cout << "------ User Login ------" << endl;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            for (User& user : users) {
                cout << "[DEBUG] Checking user: " << user.getUsername() << endl;
                if (user.getUsername() == username && user.getPassword() == password) {
                    cout << "Welcome, " << user.getUsername() << "!" << endl;
                    userDashboard(user);
                    loggedIn = true;
                    break;
                }
            }

            if (!loggedIn) {
                cout << "Incorrect username or password." << endl;
            }
        }
        else if (choice == 3) {
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
    } while (choice != 4);

    return 0;
}
