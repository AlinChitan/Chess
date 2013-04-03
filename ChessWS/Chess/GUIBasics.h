#ifndef GUI_BASICS
#define GUI_BASICS

#include <boost/signal.hpp>
#include <boost/bind.hpp>

namespace GUI
{
	
struct Bounds
{
	int left;
	int top;
	int width;
	int height;
};

typedef boost::signal<void ()>  simple_signal;
typedef boost::signal<void (int, int)> position_signal;
typedef boost::signals::connection  connection_t;

}

#endif // GUI_BASICS