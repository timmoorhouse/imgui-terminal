
#include <terminal/Terminal.hh>

namespace terminal {

// Insertion Replacement Mode
// ECMA-48 7.2.10
bool
Terminal::IRM(bool set)
{
    bool handled = true;

	if (m_verbose || !handled)
    	log("IRM(%u)", set);

    return handled;
}

}
