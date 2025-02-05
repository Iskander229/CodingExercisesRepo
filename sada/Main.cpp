#include <iostream>
#include <string>
using namespace std;


struct Course {
	string courseName;
	float midtermMark;
	float examMark;
	float projectMark;
};

//declaring custom method
void display(const Course& prompt);

int main() {
	Course firstCourse = { "OOP", 61, 61, 61 };
	Course secondCourse = { "Knowledge", 15, 31, 65 };
	Course thirdCourse = { "Game Engine", 75, 85, 100 };

	cout << "Total grades for courses: "<< endl;
	display(firstCourse);
	display(secondCourse);
	display(thirdCourse);

	return 0;
}

//filled custom method
void display(const Course& prompt) {
	cout << "---------------------------" << endl;
	cout << "Course:" << prompt.courseName << endl;
	cout << "Midterm:" << prompt.midtermMark << endl;
	cout << "Exam:" << prompt.examMark << endl;
	cout << "Project:" << prompt.projectMark << endl;
	cout << "----------------------------" << endl;
}
