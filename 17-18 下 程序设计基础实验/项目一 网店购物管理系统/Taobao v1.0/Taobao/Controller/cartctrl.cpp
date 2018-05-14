#include "cartctrl.h"

CartCtrl::CartCtrl(string ifilename) {
	cart = new ItemCtrl(ifilename);
	cart->readItemFromFile(MAXSHOWITEM,ifilename);
	filename = ifilename;
}

void CartCtrl::buyItem(ItemCtrl* itemctrl, string user) {
	for (int i = 0; i < cart->getItemTotalNum(); i++) {
		itemctrl->delItemNum(cart->getItemID(i), cart->getItemNum(i));
	}
	FileCtrl* filectrl = new FileCtrl(string(LISTFILENAME), string(LISTFILENAME));
	filectrl->putNewBill(cart->getItem(0), user);
	delete(filectrl);
	clearCart();
}

void CartCtrl::clearCart(void) {
	FileCtrl* filectrl = new FileCtrl(filename, filename);
	filectrl->clearFile();
	delete(filectrl);
	delete(cart);
	cart = new ItemCtrl(filename);
}