#include "itemctrl.h"

ItemCtrl::ItemCtrl() {
	itemNum = 0;
	item = NULL;
	filename = ITEMFILENAME;
}
ItemCtrl::ItemCtrl(string nfilename) {
	itemNum = 0;
	item = NULL;
	filename = nfilename;
}

ItemCtrl* ItemCtrl::searchItem(string itemname) {
	//if (itemname == "CuiCui") {
	//	readItemFromFile(2);
	//	item = new Item(string("CuiCui"), string("QAQ"), 5.2, 10);
	//}
	//else return NULL;
	ItemCtrl* rst = new ItemCtrl();
	Item* now = item;
	while (now != NULL) {
		if (itemname == now->getItemName()) {
			rst->addVirtualItem(now->getItemID(), now->getItemName(), now->getItemLabel(), now->getItemPrice(), now->getItemNum());
		}
		now = now->getItemNext();
	}
	return rst;
}
string ItemCtrl::searchItem(string itemname, string label) {
	Item* now = item;
	while (now != NULL) {
		if (itemname == now->getItemName() && label == now->getItemLabel()) {
			return now->getItemID();
		}
		now = now->getItemNext();
	}
	return string("NOSUCHITEM");
}


int ItemCtrl::getItemTotalNum(void) {
	return itemNum;
}

string ItemCtrl::getItemID(string id) {
	/*if (!isItemEmpty()) {
		return item->getItemNum();
	}
	else return NULL;*/
	Item* temp = getItem(id);
	return temp->getItemID();
}
string ItemCtrl::getItemID(int num) {
	Item* temp = getItem(num);
	return temp->getItemID();
}

string ItemCtrl::getItemName(string id) {
	//if (!isItemEmpty()) {
	//	return item->getItemName();
	//}
	//else return NULL;
	if (isItemEmpty()) return NULL;
	Item* temp = getItem(id);
	return temp->getItemName();
}
string ItemCtrl::getItemName(int num) {
	Item* temp = getItem(num);
	return temp->getItemName();
}

string ItemCtrl::getItemLabel(string id) {
	//if (!isItemEmpty()) {
	//	return item->getItemLabel();
	//}
	//else return NULL;
	if (isItemEmpty()) return NULL;
	Item* temp = getItem(id);
	return temp->getItemLabel();
}
string ItemCtrl::getItemLabel(int num) {
	Item* temp = getItem(num);
	return temp->getItemLabel();
}

float ItemCtrl::getItemPrice(string id) {
	//if (!isItemEmpty()) {
	//	return item->getItemPrice();
	//}
	//else return NULL;
	if (isItemEmpty()) return NULL;
	Item* temp = getItem(id);
	return temp->getItemPrice();
}
float ItemCtrl::getItemPrice(int num) {
	Item* temp = getItem(num);
	return temp->getItemPrice();
}

int ItemCtrl::getItemNum(string id) {
	//if (!isItemEmpty()) {
	//	return item->getItemQuant();
	//}
	//else return NULL;
	if (isItemEmpty()) return NULL;
	Item* temp = getItem(id);
	return temp->getItemNum();
}
int ItemCtrl::getItemNum(int num) {
	Item* temp = getItem(num);
	return temp->getItemNum();
}

//num is how many items you want to read
int ItemCtrl::readItemFromFile(int num, string filename) {
	FileCtrl file(filename, filename);
	this->item = file.getAllItems();
	if (this->item == NULL) return 0;
	itemNum = item->getItemTotalNum();
	return itemNum;
}
bool ItemCtrl::clearFile(string filename) {
	FileCtrl file(filename, filename);
	return file.clearFile();
}

bool ItemCtrl::addNewItem(string name, string label, float price, int num) {
	FileCtrl file(string(ITEMFILENAME), filename);
	Item* temp = new Item(file.getNextItemID(), name, label, price, num);
	if (itemNum == 0) item = temp;
	else getItem(itemNum - 1)->setItemNext(temp);
	file.putNewItem(temp);
	itemNum++;
	return true;
}
bool ItemCtrl::addNewItem(string id, string name, string label, float price, int num) {
	FileCtrl file(string(ITEMFILENAME), filename);
	Item* temp = new Item(id, name, label, price, num);
	if (itemNum == 0) item = temp;
	else getItem(itemNum - 1)->setItemNext(temp);
	file.putNewItem(temp, id);
	itemNum++;
	return true;
}
bool ItemCtrl::addVirtualItem(string id, string name, string label, float price, int num) {
	Item* temp = new Item(id, name, label, price, num);
	if (itemNum == 0) item = temp;
	else getItem(itemNum - 1)->setItemNext(temp);
	itemNum++;
	return true;
}

bool ItemCtrl::delItem(string id) {
	getItem(id)->setItemNum(-1);
	FileCtrl file(filename, filename);
	file.saveItems(item);
	return true;
}

bool ItemCtrl::addItemNum(string id, int addnum) {
	getItem(id)->addItemNum(addnum);
	FileCtrl file(string(ITEMFILENAME), string(ITEMFILENAME));
	file.saveItems(item);
	return true;
}
bool ItemCtrl::delItemNum(string id, int addnum) {
	getItem(id)->delItemNum(addnum);
	FileCtrl file(string(ITEMFILENAME), string(ITEMFILENAME));
	file.saveItems(item);
	return true;
}

Item* ItemCtrl::getItem(string id) {
	Item* temp = item;
	for (int i = 0; i < itemNum; i++) {
		if (id == temp->getItemID()) break;
		temp = temp->getItemNext();
	}
	return temp;
}
Item* ItemCtrl::getItem(int num) {
	Item* temp = item;
	for (int i = 0; i < num; i++) {
		temp = temp->getItemNext();
	}
	return temp;
}

float ItemCtrl::getTotalPrice(void) {
	float rst = 0;
	for (int i = 0; i < itemNum; i++) {
		rst += getItemNum(i)*getItemPrice(i);
	}
	return rst;
}

bool ItemCtrl::isItemEmpty(void) {
	if (item == NULL) return true;
	else return false;
}

bool ItemCtrl::hasMoreItem(string id, int num) {
	Item* item = getItem(id);
	if (item->getItemNum() >= num) return true;
	else return false;
}
bool ItemCtrl::hasTheItem(string id) {
	if (getItem(id) == NULL) return false;
	else return true;
}