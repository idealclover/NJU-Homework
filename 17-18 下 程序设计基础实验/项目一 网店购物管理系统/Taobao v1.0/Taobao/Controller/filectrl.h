#pragma once
#ifndef FILECTRL
#define FIELCTRL

#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
using namespace std;

#include "../const.h"
#include "../Model/item.h"


class FileCtrl{
public:
	FileCtrl(string fin, string fout);

	Item* getAllItems(void);
	Bill* getAllBills(void);
	Item* getItems(int itemnum);
	string getNextItemID(void);
	bool putNewItem(Item* item);
	bool putNewItem(Item* item, string id);
	bool saveItems(Item* item);
	bool putNewBill(Item* bill, string user);

	int searchUserInFile(string username);
	bool matchUserPassword(string iusername, string ipassword);
	int getNextUserNum(void);
	bool addUser(string username, string password);

	bool clearFile(void);
private:
	string getLastItemID(void);
	int getLastUserNum(void);
	string in;
	string out;
};

#endif