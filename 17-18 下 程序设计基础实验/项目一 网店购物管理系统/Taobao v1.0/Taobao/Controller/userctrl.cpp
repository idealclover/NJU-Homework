#include "userctrl.h"

UserCtrl::UserCtrl() {
	usertype = ANOMY;
	user = NULL;
}

int UserCtrl::authUser(string username, string password) {

///*  Version 0.01
// *  Auth: idealclover
// *  Time: 04/08/2018
// *  a total fake authuser function
// */
//	if(username == "clover" && password == "clover") return 1;
//	else if (username == "clover" && password != "clover") return PASSWORD_NOTVALID;
//	else return USERNAME_UNUSED;
//

	int userNum = searchUserInFile(username, string(USERFILENAME));
	if (userNum == USERNAME_UNUSED) {
		return USERNAME_UNUSED;
	}
	else if (matchUserPassword(username, password, string(USERFILENAME))) {
		usertype = USER;
		user = new User(userNum, username);
		return userNum;
	}
	else return PASSWORD_NOTVALID;

}
int UserCtrl::authAdmin(string username, string password) {
	int userNum = searchUserInFile(username, string(ADMINFILENAME));
	if (userNum == USERNAME_UNUSED) {
		return USERNAME_UNUSED;
	}
	if (matchUserPassword(username, password, string(ADMINFILENAME))) {
		usertype = ADMIN;
		user = new User(userNum, username);
		return userNum;
	}
	else return PASSWORD_NOTVALID;
}

string UserCtrl::getName(void) {
	return user->getUsername();
}
USERTYPE UserCtrl::getUserType(void) {
	return usertype;
}

int UserCtrl::searchUserInFile(string username, string file) {
	//if (username == "clover") return 1;
	//else return USERNAME_UNUSED;
	FileCtrl ifile(file, file);
	return ifile.searchUserInFile(username);
}
bool UserCtrl::matchUserPassword(string username, string password, string file) {
	FileCtrl ifile(file, file);
	return ifile.matchUserPassword(username, password);
}

bool UserCtrl::addNewUser(string username, string password) {
	if (searchUserInFile(username, USERFILENAME) != USERNAME_UNUSED) return false;
	FileCtrl ifile(string(USERFILENAME), string(USERFILENAME));
	ifile.addUser(username, password);
	return true;
}