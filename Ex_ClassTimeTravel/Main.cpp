

#include <iostream>
#include <string>
using namespace std;

class TimeTravel {
private:
	int currentYear;
	int destinationYear;
public:
	TimeTravel() { currentYear = 2025; destinationYear = 2025; } //set constructor

	void setDestinationYear(int input) { //validation and new set
		if (input < 1900 || input>2100) {
			cout << "invalid year for time travelling!" << endl;
		}
		else {
			destinationYear = input;
		}
	}

	string travel() {  // announcement
		if (destinationYear < currentYear) {
			return "Time travel to the past: " + to_string(destinationYear);
		}
		else if (destinationYear > currentYear) {
			return "Time travel to the future: " + to_string(destinationYear);
		}
	}

	string explore() {
		if (destinationYear == 1969) {
			return "1969: Humans landed on the Moon!";
		}
		else if (destinationYear == 2024) {
			return "2024: The present year! The future is unwritten.";
		}
		else {
			return "Exploring the unknown year: " + to_string(destinationYear) + "...";
		}
	}
};

int main() {
	TimeTravel instance; //class instance
	int year;

	cout << "Enter the destination year: ";
	cin >> year;

	instance.setDestinationYear(year); //checking if time is valid
	cout << instance.travel() << endl; //giving results
	
	cout << instance.explore() << endl;

	return 0;
}