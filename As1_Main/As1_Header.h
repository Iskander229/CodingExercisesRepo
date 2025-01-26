#ifndef As1_Header.h
#define As1_Header.h

#include <string>

class UserAccount {

private:

	int ID;
	std::string userName;
	std::string password;


public:

	//cosntructor
	UserAccount(int id, const std::string& username, const std::string& password);

	//function for login
	bool login(const std::string& inputUserName, const std::string& inputPassword) const;

	// ID getterw
	int getID() const;

};

#endif
