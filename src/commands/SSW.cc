
#include <terminal/Terminal.hh>

namespace terminal {

// Set Space Width
// ECMA-48 8.3.140
bool
Terminal::SSW(uint32_t p)
{
	// no default

    log("SSW(%u)", p);

    //! @todo

    return false;
}

}
