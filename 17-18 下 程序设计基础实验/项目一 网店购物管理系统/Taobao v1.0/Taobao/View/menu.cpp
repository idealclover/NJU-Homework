#include "menu.h"

Menu::Menu() {
	cmd = -1;
	itemctrl = NULL;
	userctrl = new UserCtrl();
	cartctrl = NULL;
}
void Menu::showWelcome(void) {
	cout << endl;
	cout << "************************************************************" << endl;
	cout << "Welcome to CuiCuiJiang's shopping system!" << endl;
	cout << "************************************************************" << endl;
	cout << endl;
}
bool Menu::loginMenu(void){
    showUserLoginMainMenu();
    cmd = requestInput();
	switch (cmd){
	case 1:
		theUserRegisterMenu();
		break;
	case 2:
		theUserLoginMenu();
		break;
	case 3:
		theAdminLoginMenu();
		break;
	case 0:
		return DIRECTEXIT;
	}
	showUserWelcome();
	return BACKTOLASTMENU;
}
bool Menu::mainMenu(void) {
	if (userctrl->getUserType() == USER) return userMainMenu();
	else if (userctrl->getUserType() == ADMIN) return adminMainMenu();
	return DIRECTEXIT;
}



//private***************************************

//user login
void Menu::showUserLoginMainMenu(void){
	cout << endl;
    cout << "************************************************************" << endl;
    cout << "1. User register 2. User login 3. Admin login" << endl;
	if (ISALLOWANOMY) cout << "4. Blowse in anomy" << endl;
	cout << "************************************************************" << endl;
	cout << endl;
}

void Menu::theUserRegisterMenu() {
	string username = getUserName();
	string password = getUserPassword();
	if (userctrl->addNewUser(username, password) == false) {
		showUsernameUsedMenu();
	}
	else cout << "OK" << endl;
	userctrl->authUser(username, password);
}
void Menu::showUsernameUsedMenu(void) {
	cout << "There is such a user!" << endl;
}
void Menu::theUserLoginMenu(void) {
	int rst = USERNAME_ISEMPTY;
	cout << endl;
	string username, password;
	while (rst < 0) {
		cout << endl;
		username = getUserName();
		password = getUserPassword();
		rst = userctrl->authUser(username, password);
		switch (rst) {
		case USERNAME_UNUSED:
			showUsernameUnusedMenu();
			break;
		case PASSWORD_NOTVALID:
			showPasswordUnvalidMenu();
			break;
		}
		cout << endl;
	}
	cartctrl = new CartCtrl(username + string(".txt"));
}
void Menu::theAdminLoginMenu(void) {
	userctrl = new UserCtrl();
	int rst = USERNAME_ISEMPTY;
	cout << endl;
	while (rst < 0) {
		cout << endl;
		string username = getUserName();
		string password = getUserPassword();
		rst = userctrl->authAdmin(username, password);
		switch (rst) {
		case USERNAME_UNUSED:
			showUsernameUnusedMenu();
			break;
		case PASSWORD_NOTVALID:
			showPasswordUnvalidMenu();
			break;
		}
		cout << endl;
	}
}

void Menu::showUsernameUnusedMenu(void) {
	cout << "No such user!" << endl;
}
void Menu::showPasswordUnvalidMenu(void) {
	cout << "Password unvalid!" << endl;
}
void Menu::showUserWelcome(void) {
	cout << endl;
	cout << "************************************************************" << endl;
	cout << "Welcome, " << userctrl->getName() << "!" << endl;
	cout << "************************************************************" << endl;
	cout << endl;
}

string Menu::getUserName(void) {
	cout << "Username: ";
	string input;
	cin >> input;
	return input;
}
string Menu::getUserPassword(void) {
	cout << "Password: ";
	string input;
	cin >> input;
	return input;
}

//main menu
bool Menu::userMainMenu(void) {
	itemctrl = new ItemCtrl();
	itemctrl->readItemFromFile(MAXSHOWITEM,string(ITEMFILENAME));
	showItemsList(itemctrl);
	cmd = -1;
	while (cmd != 0) {
		showUserMainMenu();
		cmd = requestInput();
		switch (cmd) {
		case 1:
			showItemsList(itemctrl);
			break;
		case 2:
			searchItemMenu();
			break;
		case 3:
			addItemToCartMenu();
			break;
		case 4:
			delItemFromCartMenu();
			break;
		case 5:
			showItemCartMenu();
			break;
		case 6:
			buyItemMenu();
			break;
		case 7:
			return BACKTOLASTMENU;
			break;
		case 0:
			return DIRECTEXIT;
		}
	}
	return DIRECTEXIT;
}
bool Menu::adminMainMenu(void) {
	itemctrl = new ItemCtrl();
	itemctrl->readItemFromFile(MAXSHOWITEM, string(ITEMFILENAME));
	showItemsList(itemctrl);
	cmd = -1;
	while (cmd != 0) {
		showAdminMainMenu();
		cmd = requestInput();
		switch (cmd) {
		case 1:
			showItemsList(itemctrl);
			break;
		case 2:
			searchItemMenu();
			break;
		case 3:
			addItemMenu();
			break;
		case 4:
			delItemMenu();
			break;
		case 5:
			addItemNumMenu();
			break;
		case 6:
			showSoldMenu();
			break;
		case 7:
			return BACKTOLASTMENU;
			break;
		case 0:
			return DIRECTEXIT;
		}
	}
	return DIRECTEXIT;
}

void Menu::showItemsList(void) {
	cout << endl;
	cout << "************************************************************" << endl;
	cout << "ITEM LIST" << endl;
	cout << "0" << "\t" << "CuiCui" << "\t" << 5.20 << endl;
	cout << "************************************************************" << endl;
	cout << endl;
}
void Menu::showItemsList(ItemCtrl* tarItem) {
	cout << endl;
	cout << "************************************************************" << endl;
	cout << "ITEM LIST" << endl;
	cout << "ID" << "\t" << "Name" << "\t" << "Label" << "\t" << "Price" << "\t" << "Number" << endl;
	for (int i = 0; i < tarItem->getItemTotalNum(); i++) {
		if (userctrl->getUserType() == ADMIN) {
			if (tarItem->getItemNum(i) != -1) {
				cout << tarItem->getItemID(i) << "\t"
					<< tarItem->getItemName(i) << "\t"
					<< tarItem->getItemLabel(i) << "\t"
					<< tarItem->getItemPrice(i) << "\t"
					<< tarItem->getItemNum(i) << endl;
			}
		}
		else if (userctrl->getUserType() == USER) {
			if (tarItem->getItemNum(i) != -1 && tarItem->getItemNum(i) != 0) {
				cout << tarItem->getItemID(i) << "\t"
					<< tarItem->getItemName(i) << "\t"
					<< tarItem->getItemLabel(i) << "\t"
					<< tarItem->getItemPrice(i) << "\t"
					<< tarItem->getItemNum(i) << endl;
			}
		}

	}
	cout << "************************************************************" << endl;
	cout << endl;
}

void Menu::showUserMainMenu(void) {
	cout << endl;
	cout << "************************************************************" << endl;
	cout << "1. Show items 2. Search items 3. Add items to cart 4.Remove items from cart 5. Show cart 6. Buy items 7. Logout 0. exit" << endl;
	cout << "************************************************************" << endl;
	cout << endl;
}
void Menu::showAdminMainMenu(void) {
	cout << endl;
	cout << "************************************************************" << endl;
	cout << "1. show items 2. Search items 3.Add new item 4. Delete item 5. Add item number 6. Show list 7. Logout 0. exit" << endl;
	cout << "************************************************************" << endl;
	cout << endl;
}


//search item
void Menu::searchItemMenu(void) {
	string targetItem;
	targetItem = requestItemName();
	//if (reloadItemCtrl() == false) exit(-1);
	ItemCtrl* rst = itemctrl->searchItem(targetItem);
	if (rst->getItemTotalNum() == 0) showItemNotFoundMenu();
	else showItemsList(rst);
	delete(rst);
}
void Menu::showItemNotFoundMenu(void) {
	cout << endl;
	cout << "No such item QAQ" << endl;
	cout << endl;
}

//add item
void Menu::addItemMenu(void) {
	string itemname = requestItemName();
	string itemlabel = requestItemLabel();
	if (itemctrl->searchItem(itemname, itemlabel) != "NOSUCHITEM") {
		int itemnum = requestItemNum();
		itemctrl->addItemNum(itemctrl->searchItem(itemname, itemlabel), itemnum);
	}
	else {
		float itemprice = requestItemPrice();
		int itemnum = requestItemNum();
		itemctrl->addNewItem(itemname, itemlabel, itemprice, itemnum);
	}
}

//del item
void Menu::delItemMenu(void) {
	string itemid = requestItemID();
	if (!itemctrl->hasTheItem(itemid)) {
		cout << "NO SUCH ITEM" << endl;
		return;
	}
	itemctrl->delItem(itemid);
	cout << "OK" << endl;
}

//change item num
void Menu::addItemNumMenu(void) {
	string itemnum = requestItemID();
	if (!itemctrl->hasTheItem(itemnum)) {
		cout << "NO SUCH ITEM" << endl;
		return;
	}
	int addquant = requestItemNum();
	itemctrl->addItemNum(itemnum, addquant);
	cout << "OK" << endl;
}
void Menu::showAddItemNumMenu(void) {
	
}

//add to cart
void Menu::addItemToCartMenu(void) {
	string targetID;
	targetID = requestItemID();
	if (!itemctrl->hasTheItem(targetID)) {
		cout << "NO SUCH ITEM" << endl;
		return;
	}
	int num;
	num = requestItemNum();
	if (!itemctrl->hasMoreItem(targetID, num)) {
		cout << "You put more items into your cart!" << endl;
		return;
	}
	cartctrl->cart->addNewItem(targetID,itemctrl->getItemName(targetID), itemctrl->getItemLabel(targetID), itemctrl->getItemPrice(targetID), num);
	cout << "OK" << endl;
}
void Menu::delItemFromCartMenu(void) {
	string targetID;
	targetID = requestItemID();
	if (!cartctrl->cart->hasTheItem(targetID)) {
		cout << "NO SUCH ITEM" << endl;
		return;
	}
	cartctrl->cart->delItem(targetID);
	cout << "OK" << endl;
}
void Menu::showItemCartMenu(void) {
	showItemsList(cartctrl->cart);
}

void Menu::showSoldMenu(void) {
	FileCtrl* file = new FileCtrl(string(LISTFILENAME), string(LISTFILENAME));
	Bill* bill = file->getAllBills();
	cout << endl;
	cout << "************************************************************" << endl;
	cout << "ID" << "\t" << "Name" << "\t" << "Label" << "\t" << "Price" << "\t" << "Number" << "\t" << "User" << endl;
	for (int i = 0; i < bill->getBillTotalNum(); i++) {
		if (bill != NULL) {
			cout << bill->getItemID() << "\t"
				<< bill->getItemName() << "\t"
				<< bill->getItemLabel() << "\t"
				<< bill->getItemPrice() << "\t"
				<< bill->getItemNum() << "\t"
				<< bill->getBillUser() << endl;
			bill = bill->getBillNext();
		}
	}
	cout << "************************************************************" << endl;
	cout << endl;
}

//buy item
void Menu::buyItemMenu(void) {
	showItemCartMenu();
	cout << "Total cost: " << cartctrl->cart->getTotalPrice() << ". Sure?" << endl;
	string cmd;
	cin >> cmd;
	if (cmd == string("Y") || cmd == string("y")) {
		cartctrl->buyItem(itemctrl,userctrl->getName());
		cout << "OK" << endl;
	}
}

//requests
int Menu::requestInput(void) {
	cout << endl;
	cout << "Please input your command: ";
	int input;
	cin >> input;
	return input;
}
string Menu::requestItemID(void) {
	cout << endl;
	cout << "Please input the id of the item: ";
	string input;
	cin >> input;
	return input;
}
string Menu::requestItemName(void) {
	cout << endl;
	cout << "Please input the name of the item: ";
	string input;
	cin >> input;
	return input;
}
string Menu::requestItemLabel(void) {
	cout << endl;
	cout << "Please input the label of the item: ";
	string input;
	cin >> input;
	return input;
}
float Menu::requestItemPrice(void) {
	cout << endl;
	cout << "Please input the price of the item: ";
	float input;
	cin >> input;
	return input;
}
int Menu::requestItemNum(void) {
	cout << endl;
	cout << "Please input the number of the item: ";
	int input;
	cin >> input;
	return input;
}

bool Menu::reloadItemCtrl(void) {
	if (itemctrl != NULL) delete(itemctrl);
	itemctrl = new ItemCtrl();
	return true;
}
