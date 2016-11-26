
#include <terminal/Terminal.hh>

namespace terminal {

// Auto Repeat Mode
bool
Terminal::DECARM(bool set)
{
    bool handled = set;

	if (m_verbose || !handled)
    	log("DECARM(%u)", set);

    return handled;
}

}
