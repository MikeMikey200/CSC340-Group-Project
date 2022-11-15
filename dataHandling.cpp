#include "dataHandling.h"

Data::Data() {}

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

	//scanning line by line
	while (getline(inFile, str)) {
		sstr.clear();
		sstr.str(str);

		//getting items by ',' delimiter individually in the line
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
		schoolsup.push_back(convertBinary(token));
		getline(sstr, token, ',');
		famsup.push_back(convertBinary(token));
		getline(sstr, token, ',');
		paid.push_back(convertBinary(token));
		getline(sstr, token, ',');
		activities.push_back(convertBinary(token));
		getline(sstr, token, ',');
		nursery.push_back(convertBinary(token));
		getline(sstr, token, ',');
		higher.push_back(convertBinary(token));
		getline(sstr, token, ',');
		internet.push_back(convertBinary(token));
		getline(sstr, token, ',');
		romantic.push_back(convertBinary(token));
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

int Data::convertBinary(std::string str) {
	if (str == "yes")
		return 1;
	else
		return 0;
}

void Data::printData() const {
	for (unsigned int i = 0; i < school.size(); i++) {
		std::cout << std::left
			<< std::setw(3) << school[i] 
			<< std::setw(2) << sex[i] 
			<< std::setw(3) << age[i] 
			<< std::setw(2) << address[i] 
			<< std::setw(4) << famsize[i] 
			<< std::setw(2) << Pstatus[i] 
			<< std::setw(2) << Medu[i] 
			<< std::setw(2) << Fedu[i] 
			<< std::setw(10) << Mjob[i] 
			<< std::setw(10) << Fjob[i] 
			<< std::setw(11) << reason[i] 
			<< std::setw(7) << guardian[i] 
			<< std::setw(2) << traveltime[i] 
			<< std::setw(2) << studytime[i] 
			<< std::setw(2) << failures[i] 
			<< std::setw(2) << schoolsup[i] 
			<< std::setw(2) << famsup[i] 
			<< std::setw(2) << paid[i] 
			<< std::setw(2) << activities[i] 
			<< std::setw(2) << nursery[i] 
			<< std::setw(2) << higher[i] 
			<< std::setw(2) << internet[i] 
			<< std::setw(2) << romantic[i] 
			<< std::setw(2) << famrel[i] 
			<< std::setw(2) << freetime[i] 
			<< std::setw(2) << goout[i] 
			<< std::setw(2) << Dalc[i] 
			<< std::setw(2) << Walc[i] 
			<< std::setw(2) << health[i] 
			<< std::setw(3) << absences[i] 
			<< std::setw(3) << G1[i] 
			<< std::setw(3) << G2[i] 
			<< std::setw(3) << G3[i]  << std::endl;
	}			
}

void Data::printDataPartial(unsigned int top, unsigned int bottom) const {
	for (unsigned int i = 0; i < school.size() && top > 0; i++, top--) {
		std::cout << std::left
			<< std::setw(3) << school[i]
			<< std::setw(2) << sex[i]
			<< std::setw(3) << age[i]
			<< std::setw(2) << address[i]
			<< std::setw(4) << famsize[i]
			<< std::setw(2) << Pstatus[i]
			<< std::setw(2) << Medu[i]
			<< std::setw(2) << Fedu[i]
			<< std::setw(10) << Mjob[i]
			<< std::setw(10) << Fjob[i]
			<< std::setw(11) << reason[i]
			<< std::setw(7) << guardian[i]
			<< std::setw(2) << traveltime[i]
			<< std::setw(2) << studytime[i]
			<< std::setw(2) << failures[i]
			<< std::setw(2) << schoolsup[i]
			<< std::setw(2) << famsup[i]
			<< std::setw(2) << paid[i]
			<< std::setw(2) << activities[i]
			<< std::setw(2) << nursery[i]
			<< std::setw(2) << higher[i]
			<< std::setw(2) << internet[i]
			<< std::setw(2) << romantic[i]
			<< std::setw(2) << famrel[i]
			<< std::setw(2) << freetime[i]
			<< std::setw(2) << goout[i]
			<< std::setw(2) << Dalc[i]
			<< std::setw(2) << Walc[i]
			<< std::setw(2) << health[i]
			<< std::setw(3) << absences[i]
			<< std::setw(3) << G1[i]
			<< std::setw(3) << G2[i]
			<< std::setw(3) << G3[i] << std::endl;
	}

	for (unsigned int i = school.size() - 1; i >= 0 && bottom > 0; i--, bottom--) {
		std::cout << std::left
			<< std::setw(3) << school[i]
			<< std::setw(2) << sex[i]
			<< std::setw(3) << age[i]
			<< std::setw(2) << address[i]
			<< std::setw(4) << famsize[i]
			<< std::setw(2) << Pstatus[i]
			<< std::setw(2) << Medu[i]
			<< std::setw(2) << Fedu[i]
			<< std::setw(10) << Mjob[i]
			<< std::setw(10) << Fjob[i]
			<< std::setw(11) << reason[i]
			<< std::setw(7) << guardian[i]
			<< std::setw(2) << traveltime[i]
			<< std::setw(2) << studytime[i]
			<< std::setw(2) << failures[i]
			<< std::setw(2) << schoolsup[i]
			<< std::setw(2) << famsup[i]
			<< std::setw(2) << paid[i]
			<< std::setw(2) << activities[i]
			<< std::setw(2) << nursery[i]
			<< std::setw(2) << higher[i]
			<< std::setw(2) << internet[i]
			<< std::setw(2) << romantic[i]
			<< std::setw(2) << famrel[i]
			<< std::setw(2) << freetime[i]
			<< std::setw(2) << goout[i]
			<< std::setw(2) << Dalc[i]
			<< std::setw(2) << Walc[i]
			<< std::setw(2) << health[i]
			<< std::setw(3) << absences[i]
			<< std::setw(3) << G1[i]
			<< std::setw(3) << G2[i]
			<< std::setw(3) << G3[i] << std::endl;
	}
}

std::vector<std::string> Data::getSchool() const {
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

std::vector<int> Data::getSchoolsup() const
{
	return schoolsup;
}

std::vector<int> Data::getFamsup() const
{
	return famsup;
}

std::vector<int> Data::getPaid() const
{
	return paid;
}

std::vector<int> Data::getActivities() const
{
	return activities;
}

std::vector<int> Data::getNursery() const
{
	return nursery;
}

std::vector<int> Data::getHigher() const
{
	return higher;
}

std::vector<int> Data::getInternet() const
{
	return internet;
}

std::vector<int> Data::getRomantic() const
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