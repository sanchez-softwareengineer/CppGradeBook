#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
public:

	Student() : studentName(""), studentGrade(0) {}

	Student(const string& name, int grade)
		:studentName(name), studentGrade(grade) {}

	void setStudentName(const string& name) {
		studentName = name;
	}

	void setStudentGrade(int grade) {
		studentGrade = grade;
	}

	string getStudentName()const {
		return studentName;
	}

	int getStudentGrade()const {
		return studentGrade;
	}

private:
	string studentName;
	int studentGrade;
};
