#ifndef MENU
#define MENU

#include "../setting.h"
#include "../const.h"

#include "../Controller/userctrl.h"
#include "../Controller/itemctrl.h"
#include "../Controller/cartctrl.h"

#include <iostream>
#include <string>
using namespace std;

class Menu{
public:
	Menu();
	void showWelcome(void);
    bool loginMenu(void);
	bool mainMenu(void);
	
private:
    void showUserLoginMainMenu(void);
    int requestInput(void);

	void theUserRegisterMenu(void);
	void theUserLoginMenu(void);
	void theAdminLoginMenu(void);

	void showUsernameUsedMenu(void);
	void showUsernameUnusedMenu(void);
	void showPasswordUnvalidMenu(void);
	void showUserWelcome(void);

	bool userMainMenu(void);
	bool adminMainMenu(void);

	void showItemsList(void);
	void showItemsList(ItemCtrl* tarItem);
	void showUserMainMenu(void);
	void showAdminMainMenu(void);

	string getUserName(void);
	string getUserPassword(void);

	void searchItemMenu(void);
	string requestItemID(void);
	string requestItemName(void);
	string requestItemLabel(void);
	float requestItemPrice(void);
	int requestItemNum(void);

	void showSoldMenu(void);

	void addItemMenu(void);
	void delItemMenu(void);
	void addItemNumMenu(void);
	void showAddItemNumMenu(void);

	void addItemToCartMenu(void);
	void delItemFromCartMenu(void);
	void showItemCartMenu(void);
	void buyItemMenu(void);

	void showItemNotFoundMenu(void);
	

	bool reloadItemCtrl(void);
	ItemCtrl* itemctrl;
	UserCtrl* userctrl;
	CartCtrl* cartctrl;
	int cmd;
};

#endif
