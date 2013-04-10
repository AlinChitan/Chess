#include "menu.h"
#include "menu_page.h"

namespace GUI
{

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::SwitchToPage(const string& pageName) throw (PageNotFoundException)
{
	vector<MenuPage*>::const_iterator iter;
	vector<MenuPage*>::const_iterator stop_pos = m_Pages.end();
	m_ActivePage = stop_pos;
	
	for (iter = m_Pages.begin(); iter != stop_pos; ++iter)
	{
		if ((*iter)->GetName() == pageName)
			break;
	}
	
	if (iter == stop_pos)
	{
		throw PageNotFoundException(pageName);
	}
	
	m_ActivePage = iter;
}
}

