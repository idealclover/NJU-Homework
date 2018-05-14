#ifndef CARTCTRL
#define CARTCTRL

#include <iostream>
#include <string>
using namespace std;
#include "itemctrl.h"
#include "filectrl.h"

class CartCtrl {
public:
	CartCtrl(string filename);
	void buyItem(ItemCtrl* itemctrl, string user);
	ItemCtrl* cart;
private:
	void clearCart(void);
	string filename;
};

#endif