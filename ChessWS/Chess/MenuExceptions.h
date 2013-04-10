#ifndef MENU_EXCEPTIONS
#define MENU_EXCEPTIONS

#include <string>
#include <exception>

using namespace std;

namespace GUI
{

class PageNotFoundException : public exception
{
public:
	PageNotFoundException(const string& pageName)
	{
		m_PageName = pageName;
	}
	
	~PageNotFoundException() throw (){};
	
	virtual const char* what() const throw()
    {
		string str = "Page " + m_PageName + " not found!";
		return str.c_str();
	}
	
private:
	string m_PageName;
};

}

#endif // MENU_EXCEPTIONS