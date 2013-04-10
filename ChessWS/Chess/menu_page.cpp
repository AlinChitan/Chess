#include "menu_page.h"

namespace GUI
{

MenuPage::MenuPage(Menu& refMenu, const string& name) :
m_RefMenu(refMenu)
{
	m_Name = name;
}

MenuPage::~MenuPage()
{
}

bool MenuPage::SwitchToPage(const string& pageName)
{
	try
	{
		m_RefMenu.SwitchToPage(pageName);
	}
	catch (PageNotFoundException& ex)
	{
		m_RefMenu.SwitchToPage(m_Name);
		return false;
	}
	
	return true;
}
}

