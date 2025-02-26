#include <iostream>
#include <string>
using namespace std;

//creating struct
struct Course {
	string courseName;
	float midtermMark = 0;
	float examMark = 0;
	float projectMark = 0;
};

//declaring custom methods
void display(const Course& prompt);
int readArraySize();
string ValidateString(const string& prompt);
int ValidateMark(const string& prompt);

int main() {
	int size = readArraySize();
	Course* courses = new Course[size];

	for (int i = 0; i < size; i++) {
		cout << "Details of the course number " << i + 1 << ": " << endl;
		courses[i].courseName = ValidateString("Enter Course Name: ");
		courses[i].midtermMark = ValidateMark("Enter Midterm Mark (0-100): ");
		courses[i].projectMark = ValidateMark("Enter Project Mark (0-100): ");
		courses[i].examMark = ValidateMark("Enter Exam Mark (0-100): ");
	}

	//DISPLAY
	cout << "Total grades for your courses: " << endl;
	for (int i = 0; i < size; i++) {
		display(courses[i]);
	}

	//Freeing the memory
	delete[] courses;
	return 0;
}

//filling custom methods
void display(const Course& prompt) {
	cout << "---------------------------" << endl;
	cout << "Course:" << prompt.courseName << endl;
	cout << "Midterm:" << prompt.midtermMark << endl;
	cout << "Exam:" << prompt.examMark << endl;
	cout << "Project:" << prompt.projectMark << endl;
	cout << "----------------------------" << endl;
}

int readArraySize() {
	int size;
	do {
		cout << "What is the size of array?: " << endl;
		cin >> size;

		if (cin.fail()) {                //check integer or strings input for errors. (is numeric or non-numeric)
			cin.clear();                //clear error flag
			cin.ignore(1000, '\n');     //ignore invalid input
			cout << "Error! Please enter a valid number." << endl;
		}
		else if (size <= 0) {
			cout << "Enter a positive number!" << endl;
		}

	} while (size <= 0);

	cin.ignore(1000, '\n');  // Clear the leftover newline character after reading the size

	return size;
}

//filling validating methods
string ValidateString(const string& prompt) {
	string input;

	while (true) {
		cout << prompt; //prompt from main
		getline(cin, input); //this will allow spaces in course names

		if (input.empty()) {
			cout << "Input cant be empty." << endl;
		}
		else {
			break;  // If valid exit loop
		}
	}
	return input;
}

int ValidateMark(const string& prompt) {
	int input;

	while (true) {
		cout << prompt; //prompt from main
		cin >> input;

		if (cin.fail() || input < 0 || input > 100) { //input > 100 because marks are only 0-100
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "number is invalid." << endl;
		}
		else {
			cin.ignore(1000, '\n');  // Clear buffer to avoid issues
			break;  // If valid exit loop
		}
	}
	return input;
}