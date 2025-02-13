#ifndef AS1_HEADER_H
#define AS1_HEADER_H

#include <string>

class UserAccount {

private:
	//secured vars
	int ID;
	std::string userName;
	std::string passWord; // I made W uppercase to understand the code


public:

	//creating new acc object (constructor)
	UserAccount(int id, const std::string& name, const std::string& passw);

	//function for login
	bool login(const std::string& inputUserName, const std::string& inputPassword) const;

	// ID getterw
	int getId() const;

};

#endif