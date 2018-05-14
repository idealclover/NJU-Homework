#ifndef USERCTRL
#define USERCTRL

//#include "../Model/user.h"
//#include "../Model/file.h"

#include <iostream>
#include <string>
using namespace std;

#include "../const.h"
#include "../setting.h"
#include "../Model/user.h"
#include "filectrl.h"

class UserCtrl {
public:
	UserCtrl();
	int authUser(string username, string password);
	int authAdmin(string username, string password);
	string getName(void);
	USERTYPE getUserType(void);
	bool addNewUser(string username, string password);
private:
	int searchUserInFile(string username, string file);
	bool matchUserPassword(string username, string password, string file);
	User* user;
	USERTYPE usertype;
};

#endif