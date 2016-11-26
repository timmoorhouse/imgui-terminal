
#include <terminal/Terminal.hh>

namespace terminal {

// Screen Mode Light or Dark
bool
Terminal::DECSCNM(bool set)
{
    bool handled = true;

	if (m_verbose || !handled)
    	log("DECSCNM(%u)", set);

    return handled;
}

}
