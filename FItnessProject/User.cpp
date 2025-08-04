#include "User.h"
#include <iostream>
using namespace std;

User::User(string uName, string pWord, FitnessProfile fp)
	:username(uName), password(pWord), profile(fp) {
	workoutPlan.resize(7, "Rest");
}

//Getters
string User::getUsername() {

	return username;
}

string User::getPassword() {

	return password;
}

FitnessProfile User::getProfile() {

	return profile;
}

vector <DailyLog> User::getLogs() {

	return logs;
}

string User::getFeedback() {

	return feedback;
}

vector <string> User::getWorkoutPlan() {

	return workoutPlan;
}

//setters 
void User::setPassword(string& pWord) {

	password = pWord;
}

void User::setProfile(FitnessProfile& fp) {

	profile = fp;
}

void User::setFeedBack(string& fb) {

	feedback = fb;
}

void User::setWorkoutPlan(vector<string>& plan) {

	if (plan.size() == 7) {

		workoutPlan = plan;
	}
	else cout << "Not enough workouts added" << endl;
}

void User::addLog(DailyLog& log) {
	logs.push_back(log);
}

void User::updateCurrentWeight(double weight) {

	profile.currentweight = weight;
}