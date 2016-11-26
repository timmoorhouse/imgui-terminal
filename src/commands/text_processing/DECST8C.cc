
#include <terminal/Terminal.hh>

namespace terminal {

// Set Tab at Every 8 Columns
bool
Terminal::DECST8C()
{
    bool handled = _DECST8C();

	if (m_verbose || !handled)
    	log("DECST8C");

    return handled;
}

bool
Terminal::_DECST8C()
{
    auto &b = s();

    for (int c=1; c <= b.width(true); c++)
        b.tab(c,true) = ((c > 1) && ((c-1)%8 == 0));

	return true;
}

}
