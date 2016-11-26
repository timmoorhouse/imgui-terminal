
#include <terminal/Terminal.hh>

namespace terminal {

// Line Position Backward
// ECMA-48 8.3.159
bool
Terminal::VPB(uint32_t p)
{
    bool handled = _CUU(p);

    if (m_verbose || !handled)
    	log("VPB");

    return handled;
}

}
