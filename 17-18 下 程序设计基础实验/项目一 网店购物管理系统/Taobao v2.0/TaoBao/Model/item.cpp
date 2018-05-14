#include "item.h"

Item::Item(string iid, string iname, string ilabel, float iprice, int inum) {
	id = iid;
	name = iname;
	label = ilabel;
	price = iprice;
	num = inum;
	next = NULL;
}
Item::~Item(){
	if (next == NULL) delete(this);
	else delete(next);
}

string Item::getItemID(void) {
	return id;
}
string Item::getItemName(void) {
	return name;
}
string Item::getItemLabel(void) {
	return label;
}
float Item::getItemPrice(void) {
	return price;
}
int Item::getItemNum(void) {
	return num;
}
Item* Item::getItemNext(void) {
	return next;
}
int Item::getItemTotalNum(void) {
	int totalNum = 1;
	Item* temp = next;
	while (temp != NULL) {
		totalNum++;
		temp = temp->next;
	}
	return totalNum;
}

bool Item::setItemNext(Item* item) {
	next = item;
	return true;
}
bool Item::addItemNum(int addnum) {
	setItemNum(num + addnum);
	return true;
}
bool Item::delItemNum(int delnum) {
	setItemNum(num - delnum);
	return true;
}

bool Item::setItemNum(int newnum) {
	num = newnum;
	return true;
}

string Bill::getBillUser(void) {
	return user;
}
int Bill::getBillTotalNum(void) {
	int totalNum = 1;
	Bill* temp = next;
	while (temp != NULL) {
		totalNum++;
		temp = temp->next;
	}
	return totalNum;
}
Bill* Bill::getBillNext(void) {
	return next;
}
bool Bill::setBillNext(Bill* bill) {
	next = bill;
	return true;
}
