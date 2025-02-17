
#include "As1_Header.h"
#include <iostream>
#include <string>

//custom validation functions (declarated only for easy reading other code)
std::string ValidateString(const std::string& prompt);
int ValidateID(const std::string& prompt);

//main function
int main() {

	//local main vars not related to header's private vars. (for me)
	int newID;
	std::string newUsername;
	std::string newPassword;

	//output + custom check
	newID = ValidateID("Enter ID: ");
	newUsername = ValidateString("Enter user name: ");
	newPassword = ValidateString("Enter password: ");

	//OUTPUT ENDED.

	//GETTING USER INPUT:

	//create new user's object account (from class)
	UserAccount theirAccount(newID, newUsername, newPassword); //passed new vars into class constructor (i guess))

	//Ask user to re-enter his input
	std::cout << "\n Re-enter Login: \n";
	std::string inputUserName = ValidateString("Username check: ");
	std::string inputPassword = ValidateString("Password check: ");

	//Check function
	if (theirAccount.login(inputUserName, inputPassword)) { //checking input using object's "login" bool from class
		std::cout << "Login is successful\n";
		std::cout << "Account Id: " << theirAccount.getId() << std::endl; //using getId getter to show returned ID from class
	}
	else {
		std::cout << "invalid username or password re-entered. \n"; //error handling
	}
	return 0;
}
//main ended

//custom functions declarated before.
std::string ValidateString(const std::string& prompt) {
	//var
	std::string input;

	//func
	while (true) {
		std::cout << prompt;                 //custom output to ask user to input
		std::getline(std::cin, input);       //getting whole line of user's input

		if (std::cin.fail()) {				 //check integer or strings input for errors. (is numeric or non-numeric)
			std::cin.clear();				 //clear error flag
			std::cin.ignore(1000, '\n');     //ingore invalid input
			std::cout << "username or password are invalid \n"; //error msg
		}
		else { break; } //if valid strings
	} return input;
}
int ValidateID(const std::string& prompt) {
	//var
	int input;

	//func
	while (true) {
		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid ID.\n";
		}
		else {
			std::cin.ignore();
			break; // if Valid ID
		}
	}return input;
}

// feedback on this assignment: Had big difficulties with traditional guards - Issues with directories, 
// didn't know Header file's guards should be uppercase and only with under score instead of a dot before 'h' identificator
// Also a bit of a hard time with naming conventions as using "module" practice confuses me a bit with all those inheritances, but we did it!
// Thank you for this assignment and perfect preparation for it (checked on keywords a lot to understand basics, really cool use of constants instead of hardcoding). 
// Happy to practice on this module assignment! Seems very solid for future coding.