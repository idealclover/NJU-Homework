#include "user.h"

User::User(int nusernum, string nusername) {
	usernum = nusernum;
	username = nusername;
}

int User::getUserNum(void) {
	return usernum;
}

string User::getUsername(void) {
	return username;
}

void User::changeUser(int nusernum, string nusername) {
	usernum = nusernum;
	username = nusernum;
}
