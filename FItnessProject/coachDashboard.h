#include "User.h"
#include <string>
#include <vector>
using namespace std;

class coachDashboard {
public:
	coachDashboard(const User& loggedInCoach);
	void run();
	void addClientFromUser(User& user);

private:
	

	User loggedInCoach;

	//This is handles all workout stuff
	class Workout {
	private:
		string Workouts[7];
	public:
		Workout();
		void viewWorkout();
		void update(int day, string& newWorkout);
	};

	//This handles the progress display
	class Progress {
	public:
		void viewProgress();

	};

	//This handles the actual viewing of specific client progress
	class Client {
	private:
		string name;
		Workout workoutPlan;
		Progress progress;
		User* user; // pointer to the actual user object
	public:
		Client(const string& name, User* userPtr); // updated constructor
		string getName();
		void viewClientProgress();
		void viewClientWorkouts();
		void editWorkouts();
	};
	vector<Client> clients;
	void mainMenu();
	void clientMenu(Client& client);

};
