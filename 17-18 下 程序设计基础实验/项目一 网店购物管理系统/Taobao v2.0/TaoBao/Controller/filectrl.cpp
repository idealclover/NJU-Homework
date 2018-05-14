#include "filectrl.h"

FileCtrl::FileCtrl(string fin, string fout) {
	in = fin;
	out = fout;
}

Item* FileCtrl::getAllItems(void) {
	ifstream ifile(in, ios::in);
	if (ifile.peek() == EOF) return NULL;
	int num;
	float price;
	string id, name, label;
	ifile >> id >> name >> label >> price >> num;
	Item* rst = new Item(id, name, label, price, num);
	Item* temp = rst;
	Item* pre = rst;
	while(ifile >> id){
		ifile >> name >> label >> price >> num;
		temp = new Item(id, name, label, price, num);
		pre->setItemNext(temp);
		pre = temp;
	}
	ifile.close();
	return rst;
}
Bill* FileCtrl::getAllBills(void) {
	ifstream ifile(in, ios::in);
	if (ifile.peek() == EOF) return NULL;
	int num;
	float price;
	string id, name, label, user;
	ifile >> id >> name >> label >> price >> num >> user;
	Bill* rst = new Bill(id, name, label, price, num, user);

	Bill* temp = rst;
	Bill* pre = rst;
	while (ifile >> id) {
		ifile >> name >> label >> price >> num >> user;
		temp = new Bill(id, name, label, price, num, user);
		pre->setBillNext(temp);
		pre = temp;
	}
	ifile.close();
	return rst;
}
string FileCtrl::getNextItemID(void) {
	string lastID = getLastItemID();
	char rst[6];
	rst[0] = lastID[0];
	string tmpstr(lastID, 2);
	int tmpint = stoi(tmpstr);
	tmpint++;
	snprintf(&rst[1], 5, "%04d", tmpint);
	return rst;
}
Item* FileCtrl::getItems(int itemnum) {
	ifstream ifile(in, ios::in);
	int num;
	float price;
	string id, name, label;
	ifile >> num >> name >> label >> price >> num;
	Item* rst = new Item(id, name, label, price, num);
	Item* temp = rst;
	Item* pre = rst;
	for (int i = 0; i < itemnum-1; i++) {
		if (!(ifile.peek() == EOF)) break;
		ifile >> id >> name >> label >> price >> num;
		temp = new Item(id, name, label, price, num);
		pre->setItemNext(temp);
		pre = temp;
	}
	return rst;
}
bool FileCtrl::putNewItem(Item* item) {
	ofstream ofile(out, ios::app);
	ofile << getNextItemID() << "\t"
		<< item->getItemName() << "\t"
		<< item->getItemLabel() << "\t"
		<< item->getItemPrice() << "\t"
		<< item->getItemNum() << "\n";
	return true;
}
bool FileCtrl::putNewItem(Item* item, string id) {
	ofstream ofile(out, ios::app);
	ofile << id << "\t"
		<< item->getItemName() << "\t"
		<< item->getItemLabel() << "\t"
		<< item->getItemPrice() << "\t"
		<< item->getItemNum() << "\n";
	ofile.close();
	return true;
}
bool FileCtrl::saveItems(Item* item) {
	ofstream ofile(out, ios::trunc);
	Item* now = item;
	//while (now->getItemNext() != NULL) {
    while (now != NULL) {
		ofile << now->getItemID() << "\t"
			<< now->getItemName() << "\t"
			<< now->getItemLabel() << "\t"
			<< now->getItemPrice() << "\t"
			<< now->getItemNum() << "\n";
		now = now->getItemNext();
	}
	//ofile << now->getItemID() << "\t"
	//	<< now->getItemName() << "\t"
	//	<< now->getItemLabel() << "\t"
	//	<< now->getItemPrice() << "\t"
	//	<< now->getItemNum();
	return true;
}
string FileCtrl::getLastItemID(void) {
	ifstream ifile(in, ios::in);
	int num;
	float price;
	string id, name, label;
	ifile >> id >> name >> label >> price >> num;
	while (!ifile.eof()) {
		ifile >> id >> name >> label >> price >> num;
	}
	ifile.close();
	return id;
}
bool FileCtrl::putNewBill(Item* bill, string user) {
	ofstream ofile(out, ios::app);
	Item* now = bill;
	while (now != NULL) {
		ofile << now->getItemID() << "\t"
			<< now->getItemName() << "\t"
			<< now->getItemLabel() << "\t"
			<< now->getItemPrice() << "\t"
			<< now->getItemNum() << "\t"
			<< user <<"\n";
		now = now->getItemNext();
	}
	return true;
}

int FileCtrl::searchUserInFile(string iusername) {
    ifstream ifile(in, ios::in);
	int usernum;
	string username;
	string password;
	bool isactive;
    if(!ifile.fail()){
        while (!ifile.eof()) {
            ifile >> usernum >> username >> password >> isactive;
            if (username == iusername)return usernum;
        }
    }
	ifile.close();
	return USERNAME_UNUSED;
}
bool FileCtrl::matchUserPassword(string iusername, string ipassword) {
	ifstream ifile(in, ios::in);
	int usernum;
	string username;
	string password;
	bool isactive;
	while (!ifile.eof()) {
		ifile >> usernum >> username >> password >> isactive;
		if (username == iusername && password == ipassword && isactive == true)
			return true;
	}
	ifile.close();
	return false;
}
bool FileCtrl::addUser(string username, string password) {
	ofstream ofile(out, ios::app);
	ofile << "\n"
		<< getNextUserNum() << "\t"
		<< username << "\t"
		<< password << "\t"
		<< true << "\t";
	ofile.close();
	string filename = username + ".txt";
	ofile.open(filename);
	ofile.close();
	return true;
}
int FileCtrl::getNextUserNum(void) {
	return getLastUserNum() + 1;
}
int FileCtrl::getLastUserNum(void) {
	ifstream ifile(in, ios::in);
	int usernum;
	string username;
	string password;
	bool isactive;
	while (!ifile.eof()) {
		ifile >> usernum >> username >> password >> isactive;
	}
	ifile.close();
	return usernum;
}

bool FileCtrl::clearFile(void) {
	ofstream ofile(out, ios::trunc);
	ofile.clear();
	ofile.close();
	return true;
}
