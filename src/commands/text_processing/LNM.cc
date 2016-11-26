
#include <terminal/Terminal.hh>

namespace terminal {

// Line Feed / New Line Mode
bool
Terminal::LNM(bool set)
{
    bool handled = !set;

	if (m_verbose || !handled)
    	log("LNM(%u)", set);

    return handled;
}

}
