#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

set<int> idCheck;

bool checkUserName(string name);
bool checkUserYOB(int yearOfBirth);
bool employeeNumberCheck(string number);
map<string, string> StudentAccountData;
class User {
private:
	int id, yearOfBirth;
	string name, email, password;
public:
	User() {};
	User(int id, int yearOfBirth, string name, string email, string password) {
		this->id = id;
		this->yearOfBirth = yearOfBirth;
		this->name = name;
		this->email = email;
		this->password = password;
	}
	friend istream& operator >> (istream& in, User& x) {
		int number = rand() % 900000 + 100000;
		while (idCheck.find(number) != idCheck.end()) {
			number = rand() % 900000 + 100000;
		}
		x.id = number;
		cout << "1.ID : " << x.id << endl;
		cout << "2.Name : ";
		getline(in, x.name);
		while (checkUserName(x.name) == false) {
			cout << "Invalid name. Please enter again: ";
			getline(in, x.name);
		}
		cout << "3. Email : ";
		getline(in, x.email);
		cout << "4. Password : ";
		getline(in, x.password);
		cout << "5. Year Of Birth : ";
		in >> x.yearOfBirth;
		while (checkUserYOB(x.yearOfBirth) == false) {
			cout << "Invalid year of birth. Please enter again: ";
			in >> x.yearOfBirth;
		}
		in.ignore();
		cout << "6. Select T to register as a Teacher : " << endl;
		cout << "   Select S to register as a Student : " << endl;
		cout << "	Press 1 to confirm information and log in" << endl;
		cout << "	Press 2 to log in" << endl;
		cout << "	Press 3 to exit" << endl;
		idCheck.insert(x.id);
		return in;
	}
	void printInformation() {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Email: " << email << endl;
		cout << "Password: " << password << endl;
		cout << "Year Of Birth: " << yearOfBirth << endl;
	}
	int getID() {
		return id;
	}
	int getYearOfBirth() {
		return yearOfBirth;
	}
	string getName() {
		return name;
	}
	string getEmail() {
		return email;
	}
	string getPassword() {
		return password;
	}
	void setID(int id) {
		this->id = id;
	}
	void setYearOfBirth(int yearOfBirth) {
		this->yearOfBirth = yearOfBirth;
	}
	void setName(string name) {
		this->name = name;
	}
	void setEmail(string email) {
		this->email = email;
	}
	void setPassword(string password) {
		this->password = password;
	}
};


class Teacher : public User {
private:
	int employeeNumber;
	string department, degree;
public:
	Teacher() {};
	Teacher(int id, int yearOfBirth, string name, string email, string password, int employeeNumber, string department, string degree)
		: User(id, yearOfBirth, name, email, password) {
		this->employeeNumber = employeeNumber;
		this->department = department;
		this->degree = degree;
	}
	friend istream& operator >> (istream& in, Teacher& x) {
		cout << "1. Employee Number : ";
		string tmp;
		getline(in, tmp);
		while (!employeeNumberCheck(tmp)) {
			cout << "Employee Number Invalid, please enter again : ";
			getline(in, tmp);
		}
		x.employeeNumber = stoi(tmp);
		cout << "2. Degree : ";
		getline(in, x.degree);
		cout << "3. Department : ";
		getline(in, x.department);
		return in;
	}
	void printInformation() {
		cout << "ID: " << getID() << endl;
		cout << "Name: " << getName() << endl;
		cout << "Email: " << getEmail() << endl;
		cout << "Password: " << getPassword() << endl;
		cout << "Year Of Birth: " << getYearOfBirth() << endl;
		cout << "Employee Number : " << employeeNumber << endl;
		cout << "Degree : " << degree << endl;
		cout << "Department : " << department << endl;
	}
	void setDegree(string degree) {
		this->degree = degree;
	}
	void setEmployeeNumber(int employeeNumber) {
		this->employeeNumber = employeeNumber;
	}
	void setDepartment(string department) {
		this->department = department;
	}
};

class Student : public User {
private:
	int studentNumber, year;
	string major, studentAnswer;
public:
	Student() {};
	Student(int id, int yearOfBirth, string name, string email, string password, int studentNumber, string major,
		int year) : User(id, yearOfBirth, name, email, password) {
		this->studentNumber = studentNumber;
		this->major = major;
		this->year = year;
	}
	friend istream& operator >> (istream& in, Student x) {
		cout << "Student Number : ";
		string tmp;
		getline(in, tmp);
		while (!employeeNumberCheck(tmp)) {
			cout << "Invalid Student Number, please enter again : ";
			getline(in, tmp);
		}
		x.studentNumber = stoi(tmp);
		cout << "Major (if exist, if don't, type ""nothing"" ";
		getline(in, x.major);
		cout << " Year : ";
		in >> x.year;
		while (checkUserYOB(x.year) == false) {
			cout << "Year invalid, please enter again : ";
			cin >> x.year;
		}
		in.ignore();
		return in;
	}
};
int main()
{
	srand(time(NULL));
}

void chuanHoaNS(string& birth) {
	if (birth[0] == '/') {
		birth = "0" + birth;
	}
	if (birth[3] == '/') {
		birth.insert(0, "3");
	}
}
bool checkUserName(string name) {
	for (char c : name) {
		if (!isalpha(c) && c != ' ') {
			return false;
		}
	}
	return true;
}
bool checkUserYOB(int yearOfBirth) {
	if (yearOfBirth < 1900 || yearOfBirth > 2026) {
		return false;
	}
	return true;
}
bool employeeNumberCheck(string number) {
	for (int i = 0; i < number.size(); i++) {
		if (!isdigit(number[i])) {
			return false;
		}
	}
	return true;
}