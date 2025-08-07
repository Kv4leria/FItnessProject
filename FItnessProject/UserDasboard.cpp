#include "User.h"
#include "FitnessProfile.h"
#include <iostream>
using namespace std;

void userMenu(User& user) {
    int choice;

    do {
        cout << "\n--- User Dashboard ---\n";
        cout << "1. View Profile\n";
        cout << "2. View Workout Plan\n";
        cout << "3. Log Daily Info (Calories, Weight, Workout)\n";
        cout << "4. View Progress Logs\n";
        cout << "5. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                FitnessProfile p = user.getProfile();
                cout << "\n--- Your Profile ---\n";
                cout << "Current Weight: " << p.currentweight << " kg\n";
                cout << "Goal Weight: " << p.goalWeight << " kg\n";
                cout << "Height: " << p.height << " cm\n";
                cout << "Age: " << p.age << "\n";
                cout << "Gender: " << p.gender << "\n";
                cout << "Activity Level: " << p.activityLevel << "\n";
                break;
            }

            case 2: {
                cout << "\n--- Your Workout Plan ---\n";
                vector<string> plan = user.getWorkoutPlan();
                string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
                for (int i = 0; i < 7; i++) {
                    cout << days[i] << ": " << plan[i] << endl;
                }
                break;
            }

            case 3: {
                DailyLog log;
                cout << "\n--- Log Daily Info ---\n";
                cout << "Food Item: ";
                getline(cin, log.foodItem);

                cout << "Calories: ";
                cin >> log.calories;

                cout << "Weight: ";
                cin >> log.weight;

                cout << "Workout Completed? (1 = Yes, 0 = No): ";
                cin >> log.workoutComplete;
                cin.ignore(); 

                user.addLog(log);
                user.updateCurrentWeight(log.weight);
                cout << "Log saved!\n";
                break;
            }

            case 4: {
                cout << "\n--- Progress Logs ---\n";
                vector<DailyLog> logs = user.getLogs();
                for (int i = 0; i < logs.size(); i++) {
                    cout << "Log #" << i + 1 << ":\n";
                    cout << "Food Item: " << logs[i].foodItem << "\n";
                    cout << "Calories: " << logs[i].calories << "\n";
                    cout << "Weight: " << logs[i].weight << "\n";
                    cout << "Workout Completed: " << (logs[i].workoutComplete ? "Yes" : "No") << "\n\n";
                }
                if (logs.empty()) {
                    cout << "No logs yet.\n";
                }
                break;
            }

            case 5:
                cout << "Logging out...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);
}
