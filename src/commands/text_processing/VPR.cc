
#include <terminal/Terminal.hh>

namespace terminal {

// Line Position Forward
// ECMA-48 8.3.160
bool
Terminal::VPR(uint32_t p)
{
    bool handled = _CUD(p);

    if (m_verbose || !handled)
    	log("VPR");

    return handled;
}

}
