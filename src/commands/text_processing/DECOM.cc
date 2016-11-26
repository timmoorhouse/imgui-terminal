
#include <terminal/Terminal.hh>

namespace terminal {

// Origin Mode
bool
Terminal::DECOM(bool set)
{
    bool handled = !set;

	if (m_verbose || !handled)
    	log("DECOM(%u)", set);

    return handled;
}

}
