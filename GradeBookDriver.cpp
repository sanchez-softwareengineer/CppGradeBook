#include<iostream>
#include<string>
#include"GradeBook.h"
#include"Student.h"
#include<array>
using namespace std;

int main() {
    string courseName;
    string studentName;
    int studentGrade;
    array<Student, 10> studentGrades;

    bool stillGrading = true;
    while (stillGrading) {
        cout << "============================================================================\n";
        cout << "Enter course name: ";
        getline(cin, courseName);
        cout << "=======================Entering Students' Information=============================\n";
        cout << "Enter the name and grade for 10 students\n";
        // cin.ignore();
        for (int i = 0; i < 10; i++) {
            cout << "Student #" << i + 1 << " name: ";
            getline(cin, studentName);
            cout << "Student #" << i + 1 << " grade: ";
            cin >> studentGrade;
            cin.ignore();

            studentGrades[i] = Student(studentName, studentGrade);
        }
        GradeBook myGradeBook(courseName, studentGrades);
        myGradeBook.setCourseName(courseName);

        cout << "============================================================================\n";
        cout << "Welcome to the grade book for\n" << myGradeBook.getCourseName() << "!\n\n";
        cout << "============================================================================\n";

        myGradeBook.processGrades();
        cout << "Press any key to continue grading, or 'n' to end:  ";
        char input;
        cin >> input;
        cin.ignore();
        if (input == 'n') {
            stillGrading = false;
            break;
        }
    }
    return 0;
}