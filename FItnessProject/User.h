#ifndef USER_H
#define USER_H

#include "FitnessProfile.h"
#include <string>
#include <vector>
using namespace std;

struct DailyLog {

	string foodItem;
	int calories;
	double weight;
	bool workoutComplete;
};

class User {
private: 
	string username;
	string password;
	FitnessProfile profile; 
	vector <DailyLog> logs;
	string feedback;
	vector <string> workoutPlan;

public: 
	User (string uName, string pWord, FitnessProfile fp);

	//Getters
	string getUsername();
	string getPassword();
	FitnessProfile getProfile();
	vector <DailyLog> getLogs();
	string getFeedback();
	vector <string> getWorkoutPlan();

	// setters 
	void setPassword(string& pWord);
	void setProfile(FitnessProfile& fp);
	void setFeedBack(string& fb);
	void setWorkoutPlan(vector <string>& plan);

	void addLog(DailyLog& log);
	void updateCurrentWeight(double weight);

};

#endif // !USER_H


