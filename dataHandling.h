#ifndef DATAHANDLING_H
#define DATAHANDLING_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Data {
public:
	Data();
	Data(std::string inFile);

	//printing the whole data file
	void printData() const;
	//printing number of data on top and bottom
	void printDataPartial(unsigned int top, unsigned int bottom) const;

	//accessors
	std::vector<std::string> getSchool() const;
	std::vector<char> getSex() const;
	std::vector<int> getAge() const;
	std::vector<char> getAddress() const;
	std::vector<std::string> getFamsize() const;
	std::vector<char> getPStatus() const;
	std::vector<int> getMEdu() const;
	std::vector<int> getFEdu() const;
	std::vector<std::string> getMJob() const;
	std::vector<std::string> getFJob() const;
	std::vector<std::string> getReason() const;
	std::vector<std::string> getGuardian() const;
	std::vector<int> getTraveltime() const;
	std::vector<int> getStudytime() const;
	std::vector<int> getFailures() const;
	std::vector<int> getSchoolsup() const;
	std::vector<int> getFamsup() const;
	std::vector<int> getPaid() const;
	std::vector<int> getActivities() const;
	std::vector<int> getNursery() const;
	std::vector<int> getHigher() const;
	std::vector<int> getInternet() const;
	std::vector<int> getRomantic() const;
	std::vector<int> getFamrel() const;
	std::vector<int> getFreetime() const;
	std::vector<int> getGoout() const;
	std::vector<int> getDAlc() const;
	std::vector<int> getWAlc() const;
	std::vector<int> getHealth() const;
	std::vector<int> getAbsences() const;
	std::vector<int> getG1() const;
	std::vector<int> getG2() const;
	std::vector<int> getG3() const;

private:
	//functions
	//convert binaries from yes/or to 1/0
	int convertBinary(std::string str);

	//variables
	//student's school (binary: 'GP' - Gabriel Pereira or 'MS' - Mousinho da Silveira)
	std::vector<std::string> school;
	//student's sex (binary: 'F' - female or 'M' - male)
	std::vector<char> sex;
	//student's age (numeric: from 15 to 22)
	std::vector<int> age;
	//student's home address type (binary: 'U' - urban or 'R' - rural)
	std::vector<char> address;
	//family size (binary: 'LE3' - less or equal to 3 or 'GT3' - greater than 3)
	std::vector<std::string> famsize;
	//parent's cohabitation status (binary: 'T' - living together or 'A' - apart)
	std::vector<char> Pstatus;
	//mother's education (numeric: 0 - none, 1 - primary education (4th grade), 2 – 5th to 9th grade, 3 – secondary education or 4 – higher education)
	std::vector<int> Medu;
	//father's education (numeric: 0 - none, 1 - primary education (4th grade), 2 – 5th to 9th grade, 3 – secondary education or 4 – higher education)
	std::vector<int> Fedu;
	//mother's job (nominal: 'teacher', 'health' care related, civil 'services' (e.g. administrative or police), 'at_home' or 'other')
	std::vector<std::string> Mjob;
	//father's job (nominal: 'teacher', 'health' care related, civil 'services' (e.g. administrative or police), 'at_home' or 'other')
	std::vector<std::string> Fjob;
	//reason to choose this school (nominal: close to 'home', school 'reputation', 'course' preference or 'other')
	std::vector<std::string> reason;
	//student's guardian (nominal: 'mother', 'father' or 'other')
	std::vector<std::string> guardian;
	//home to school travel time (numeric: 1 - <15 min., 2 - 15 to 30 min., 3 - 30 min. to 1 hour, or 4 - >1 hour)
	std::vector<int> traveltime;
	//weekly study time (numeric: 1 - <2 hours, 2 - 2 to 5 hours, 3 - 5 to 10 hours, or 4 - >10 hours)
	std::vector<int> studytime;
	//number of past class failures (numeric: n if 1<=n<3, else 4)
	std::vector<int> failures;
	//extra educational support (binary: yes or no)
	std::vector<int> schoolsup;
	//family educational support (binary: yes or no)
	std::vector<int> famsup;
	//extra paid classes within the course subject (Math or Portuguese) (binary: yes or no)
	std::vector<int> paid;
	//extra-curricular activities (binary: yes or no)
	std::vector<int> activities;
	//attended nursery school (binary: yes or no)
	std::vector<int> nursery;
	//wants to take higher education (binary: yes or no)
	std::vector<int> higher;
	//Internet access at home (binary: yes or no)
	std::vector<int> internet;
	//with a romantic relationship (binary: yes or no)
	std::vector<int> romantic;
	//quality of family relationships (numeric: from 1 - very bad to 5 - excellent)
	std::vector<int> famrel;
	//free time after school (numeric: from 1 - very low to 5 - very high)
	std::vector<int> freetime;
	//going out with friends (numeric: from 1 - very low to 5 - very high)
	std::vector<int> goout;
	//workday alcohol consumption (numeric: from 1 - very low to 5 - very high)
	std::vector<int> Dalc;
	//weekend alcohol consumption (numeric: from 1 - very low to 5 - very high)
	std::vector<int> Walc;
	//current health status (numeric: from 1 - very bad to 5 - very good)
	std::vector<int> health;
	//number of school absences (numeric: from 0 to 93)
	std::vector<int> absences;
	//first period grade (numeric: from 0 to 20)
	std::vector<int> G1;
	//second period grade(numeric: from 0 to 20)
	std::vector<int> G2;
	//final grade (numeric: from 0 to 20, output target)
	std::vector<int> G3;
};

#endif // !DATAHANDLING_H
