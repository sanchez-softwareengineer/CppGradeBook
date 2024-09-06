#pragma once
#include <iostream>
#include <string>
#include <array>
using namespace std;

class GradeBook {
public:
	//making a constructor using my variables above.
	//"&" means it is a refrence, an alias for another variable.
	GradeBook(const string& cName, const array<Student, 10>& sStudents) :
		courseName(cName), studentGrades(sStudents) {
		//This is called an initializer list, the member varaibles are initialized directly.
		//Imagine you’re setting up a room with a chair and a table:
		/*Initializer List :
			You put the chair and table directly where they need to go the moment you bring
			them into the room.
		Constructor Body :
			You first put the chair and table in the room somewhere randomly,
			then you move them to their proper places.*/
	}

	//Const variables cannot be changed, they are made as "read only".
	string getCourseName()const {
		return courseName;
	}
	/*This function updates the courseName member variable of the class with the value passed
		to it through the cName parameter.*/
		/*The use of const string& for the parameter ensures that the function does not modify
			the passed string, and it also makes the function more efficient by avoiding
			copying the string.*/
	void setCourseName(const string& cName) {
		courseName = cName;
	}

	void processGrades()const {
		outputGrades();
		cout << "\nClass average is " << getAverage() << endl;
		cout << "Lowest grade is " << getMinimum() << endl;
		cout << "Highest grade is " << getMaximum() << endl;

		outputBarChart();

	}
	//returns the highest grade.
	int getMaximum()const {
		//The lowest grade you can have is a 0, this will be used to compare with other grades.
		int highGrade{ 0 };

		//range based for loop
		for (const Student& student : studentGrades) {
			int grade = student.getStudentGrade();
			if (highGrade < grade) {
				highGrade = grade;
			}
		}

		return highGrade;
	}

	int getMinimum()const {
		//The highest grade you can have is 100, so you will then compare it to other grades.
		int lowGrade{ 100 };

		for (const Student& student : studentGrades) {
			int grade = student.getStudentGrade();
			if (lowGrade > grade) {
				lowGrade = grade;
			}
		}

		return lowGrade;
	}

	double getAverage()const {
		int sum{ 0 };

		for (const Student& student : studentGrades) {
			int grade = student.getStudentGrade();
			sum += grade;
		}

		return static_cast<double>(sum) / studentGrades.size();
		/*How static_cast Works:
		Syntax: static_cast<new_type>(expression)
			new_type: The type you want to convert expression to.
			expression: The variable or value you want to cast.*/
	}

	void outputGrades()const {
		cout << "\nThe grades are:\n\n";

		for (size_t i{ 0 }; i < studentGrades.size(); ++i) {
			cout << studentGrades.at(i).getStudentName() << ": " << studentGrades.at(i).getStudentGrade() << endl;
		}
	}

	void outputBarChart()const {
		cout << "\nGrade distribution:\n";
		/*frequency{}: This is brace initialization (or uniform initialization). The empty braces {}
		mean that all elements of the array are initialized to 0. In other words, frequency{}
		initializes all 11 integers in the array to zero*/
		array<int, 11> frequency{};

		for (const Student& student : studentGrades) {
			int grade = student.getStudentGrade();
			++frequency[grade / 10];
		}

		for (size_t i{ 0 }; i < frequency.size(); ++i) {
			if (i == 0) {
				cout << " 0-9:";
			}
			else if (i >= 10) {
				cout << " 100:";
			}
			else {
				cout << i * 10 << "-" << (i * 10) + 9 << ":";
			}
			for (unsigned stars{ 0 }; stars < frequency[i]; ++stars) {
				cout << '*';
			}

			cout << endl;
		}

	}

private:
	string courseName;
	array<Student, 10> studentGrades;

};
