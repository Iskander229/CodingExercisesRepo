#include "As1_Header.h"
//constructor with initialized values
UserAccount::UserAccount(int id, const std::string& name, const std::string& passw)
	: ID(id), userName(name), passWord(passw){}

//function init
bool UserAccount::login(const std::string& inputUserName, const std::string& inputPassword) const {
	return (inputUserName == userName && inputPassword == passWord);
}

//ID getter init.
int UserAccount::getId() const {
	return ID;
}