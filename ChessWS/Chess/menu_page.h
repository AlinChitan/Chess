#ifndef MENU_PAGE
#define MENU_PAGE

#include <string>
#include "menu.h"

namespace GUI
{

class Menu;

class MenuPage
{
	friend class Menu;

public:
	MenuPage(Menu& refMenu, const string& name);
	virtual ~MenuPage();
	
protected:
	inline const string& GetName(){return m_Name;}
	bool SwitchToPage(const string& pageName);
	
private:
	string m_Name;
	Menu&  m_RefMenu;

};

}

#endif // MENU_PAGE
