#ifndef ITEM
#define ITEM

#include <iostream>
#include <string>
using namespace std;

class Item {
public:
	Item(string iid, string iname, string ilabel, float iprice, int iquant);
	~Item();
	string getItemID(void);
	string getItemName(void);
	string getItemLabel(void); 
	float getItemPrice(void);
	int getItemNum(void);
	Item* getItemNext(void);
	int getItemTotalNum(void);

	bool setItemNext(Item* item);
	bool addItemNum(int addnum);
	bool delItemNum(int delnum);
	bool setItemNum(int newnum);
private:
	string id;
	string name;
	string label;
	float price;
	int num;
	Item* next;
};

class Bill:public Item {
public:
	Bill(string iid, string iname, string ilabel, float iprice, int iquant, string iuser) :Item(iid, iname, ilabel, iprice, iquant) {
		user = iuser;
	}
	string getBillUser(void);
	Bill* getBillNext(void);
	int getBillTotalNum(void);
	bool setBillNext(Bill* bill);
private:
	string user;
	Bill* next;
};

#endif
