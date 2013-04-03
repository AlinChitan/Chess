#ifndef WIDGET
#define WIDGET

#include <string>
#include "GUIBasics.h"

using namespace std;

namespace GUI
{

class Widget
{
public:
	Widget();
	virtual ~Widget();

	simple_signal 	OnReturn;
	simple_signal 	OnEscape;
	simple_signal	OnSpace;
	position_signal OnMouseOver;
	position_signal OnMouseClick;

private:
	string 			m_Text;
	string 			m_TextureFile;
	Bounds	 		m_Bounds;
	
	void SetBounds(const Bounds& Bounds) {
		this->m_Bounds = Bounds;
	}
	void SetText(const string& Text) {
		this->m_Text = Text;
	}
	void SetTextureFile(const string& TextureFile) {
		this->m_TextureFile = TextureFile;
	}
	const Bounds& GetBounds() const {
		return m_Bounds;
	}
	const string& GetText() const {
		return m_Text;
	}
	const string& GetTextureFile() const {
		return m_TextureFile;
	}
};

}

#endif // WIDGET
