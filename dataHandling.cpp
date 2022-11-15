#include "dataHandling.h"

Data::Data(){}

Data::Data(std::string fname) {
	std::string str, token;
	std::stringstream sstr;
	std::vector<std::string> vstr;
	std::ifstream inFile;
	
	inFile.open(fname);

	if (!inFile) {
		std::cout << "File unable to open!" << std::endl;
	}
	
	//ignoring first line
	getline(inFile, str);

	while (getline(inFile, str)) {
		sstr.clear();
		sstr.str(str);

		getline(sstr, token, ',');
		school.push_back(token);
		getline(sstr, token, ',');
		sex.push_back(token[0]);
		getline(sstr, token, ',');
		age.push_back(std::stoi(token));
		getline(sstr, token, ',');
		address.push_back(token[0]);
		getline(sstr, token, ',');
		famsize.push_back(token);
		getline(sstr, token, ',');
		Pstatus.push_back(token[0]);
		getline(sstr, token, ',');
		Medu.push_back(std::stoi(token));
		getline(sstr, token, ',');
		Fedu.push_back(std::stoi(token));
		getline(sstr, token, ',');
		Mjob.push_back(token);
		getline(sstr, token, ',');
		Fjob.push_back(token);
		getline(sstr, token, ',');
		reason.push_back(token);
		getline(sstr, token, ',');
		guardian.push_back(token);
		getline(sstr, token, ',');
		traveltime.push_back(std::stoi(token));
		getline(sstr, token, ',');
		studytime.push_back(std::stoi(token));
		getline(sstr, token, ',');
		failures.push_back(std::stoi(token));
		getline(sstr, token, ',');
		schoolsup.push_back(token);
		getline(sstr, token, ',');
		famsup.push_back(token);
		getline(sstr, token, ',');
		paid.push_back(token);
		getline(sstr, token, ',');
		activities.push_back(token);
		getline(sstr, token, ',');
		nursery.push_back(token);
		getline(sstr, token, ',');
		higher.push_back(token);
		getline(sstr, token, ',');
		internet.push_back(token);
		getline(sstr, token, ',');
		romantic.push_back(token);
		getline(sstr, token, ',');
		famrel.push_back(std::stoi(token));
		getline(sstr, token, ',');
		freetime.push_back(std::stoi(token));
		getline(sstr, token, ',');
		goout.push_back(std::stoi(token));
		getline(sstr, token, ',');
		Dalc.push_back(std::stoi(token));
		getline(sstr, token, ',');
		Walc.push_back(std::stoi(token));
		getline(sstr, token, ',');
		health.push_back(std::stoi(token));
		getline(sstr, token, ',');
		absences.push_back(std::stoi(token));
		getline(sstr, token, ',');
		G1.push_back(std::stoi(token));
		getline(sstr, token, ',');
		G2.push_back(std::stoi(token));
		getline(sstr, token, ',');
		G3.push_back(std::stoi(token));
	}
}

std::vector<std::string> Data::getSchool() const{
	return school;
}

std::vector<char> Data::getSex() const {
	return sex;
}

std::vector<int> Data::getAge() const {
	return age;
}

std::vector<char> Data::getAddress() const
{
	return address;
}

std::vector<std::string> Data::getFamsize() const
{
	return famsize;
}

std::vector<char> Data::getPStatus() const
{
	return Pstatus;
}

std::vector<int> Data::getMEdu() const
{
	return Medu;
}

std::vector<int> Data::getFEdu() const
{
	return Fedu;
}

std::vector<std::string> Data::getMJob() const
{
	return Mjob;
}

std::vector<std::string> Data::getFJob() const
{
	return Fjob;
}

std::vector<std::string> Data::getReason() const
{
	return reason;
}

std::vector<std::string> Data::getGuardian() const
{
	return guardian;
}

std::vector<int> Data::getTraveltime() const
{
	return traveltime;
}

std::vector<int> Data::getStudytime() const
{
	return studytime;
}

std::vector<int> Data::getFailures() const
{
	return failures;
}

std::vector<std::string> Data::getSchoolsup() const
{
	return schoolsup;
}

std::vector<std::string> Data::getFamsup() const
{
	return famsup;
}

std::vector<std::string> Data::getPaid() const
{
	return paid;
}

std::vector<std::string> Data::getActivities() const
{
	return activities;
}

std::vector<std::string> Data::getNursery() const
{
	return nursery;
}

std::vector<std::string> Data::getHigher() const
{
	return higher;
}

std::vector<std::string> Data::getInternet() const
{
	return internet;
}

std::vector<std::string> Data::getRomantic() const
{
	return romantic;
}

std::vector<int> Data::getFamrel() const
{
	return famrel;
}

std::vector<int> Data::getFreetime() const
{
	return freetime;
}

std::vector<int> Data::getGoout() const
{
	return goout;
}

std::vector<int> Data::getDAlc() const
{
	return Dalc;
}

std::vector<int> Data::getWAlc() const
{
	return Walc;
}

std::vector<int> Data::getHealth() const
{
	return health;
}

std::vector<int> Data::getAbsences() const
{
	return absences;
}

std::vector<int> Data::getG1() const
{
	return G1;
}

std::vector<int> Data::getG2() const
{
	return G2;
}

std::vector<int> Data::getG3() const
{
	return G3;
}
