
#include <terminal/Terminal.hh>

namespace terminal {

// Cursor Key Mode
bool
Terminal::DECCKM(bool set)
{
    bool handled = !set;

	if (m_verbose || !handled)
    	log("DECCKM(%u)", set);

    return handled;
}

}
