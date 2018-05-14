#ifndef MYUSER
#define MYUSER

#include <iostream>
#include <string>
using namespace std;

class User {
public:
	User(int nusernum, string nusername);
	int getUserNum(void);
	string getUsername(void);
	void changeUser(int nusernum, string nusername);
private:
	int usernum;
	string username;
};


#endif