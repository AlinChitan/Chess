#ifndef MENU
#define MENU

#include <string>
#include <vector>
#include "MenuExceptions.h"

using namespace std;

namespace GUI
{

class MenuPage;

class Menu
{
	friend class MenuPage;
	
public:
	Menu();
	virtual ~Menu();
	
private:
	vector<MenuPage*> m_Pages;
	vector<MenuPage*>::const_iterator m_ActivePage;

	void SwitchToPage(const string& pageName) throw (PageNotFoundException);
};

}

#endif // MENU
