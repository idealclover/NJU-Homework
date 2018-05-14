#include"View/menu.h"
#include "const.h"

int main(void){
    Menu* menu = new Menu;
	menu->showWelcome();
	while (menu->loginMenu() == BACKTOLASTMENU) {
		while (menu->mainMenu() == BACKTOLASTMENU) {
			break;
		}
	}
	system("pause");
    return 0;
}
