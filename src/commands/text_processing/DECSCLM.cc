
#include <terminal/Terminal.hh>

namespace terminal {

// Scrolling Mode
bool
Terminal::DECSCLM(bool set)
{
    bool handled = !set;

	if (m_verbose || !handled)
    	log("DECSCLM(%u)", set);

    return handled;
}

}
