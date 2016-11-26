
#include <terminal/Terminal.hh>

namespace terminal {

// Auto Wrap Mode
bool
Terminal::DECAWM(bool set)
{
    bool handled = true;

	if (m_verbose || !handled)
    	log("DECAWM(%u)", set);

    return handled;
}

}
