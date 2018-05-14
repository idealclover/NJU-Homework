#ifndef ITEMCTRL
#define ITEMCTRL

#include "../const.h"
#include "../setting.h"
#include "../Model/item.h"
#include "filectrl.h"

#include <iostream>
#include <string>
using namespace std;

class ItemCtrl {
public:
	ItemCtrl();
	ItemCtrl(string nfilename);
	ItemCtrl* searchItem(string itemname);
	string searchItem(string itemname, string label);
	int getItemTotalNum(void);
	string getItemID(string id);
	string getItemID(int num);
	string getItemName(string id);
	string getItemName(int num);
	string getItemLabel(string id);
	string getItemLabel(int num);
	float getItemPrice(string id);
	float getItemPrice(int num);
	int getItemNum(string id);
	int getItemNum(int num);
	float getTotalPrice(void);
	int readItemFromFile(int num,string filename);
	bool clearFile(string filename);
	
	Item* getItem(int num);

	bool addNewItem(string name, string label, float price, int num);
	bool addNewItem(string id, string name, string label, float price, int num);
	bool addVirtualItem(string id, string name, string label, float price, int num);
	bool addItemNum(string id, int addquant);
	bool delItemNum(string id, int addnum);
	bool delItem(string id);

	bool hasMoreItem(string id, int num);
	bool hasTheItem(string id);

private:
	string filename;
	bool isItemEmpty(void);
	Item* getItem(string id);

	int itemNum;
	Item* item;
};

#endif