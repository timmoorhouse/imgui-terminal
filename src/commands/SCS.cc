
#include <terminal/Terminal.hh>

namespace terminal {

// Set Character Spacing
// ECMA-48 8.3.112
bool
Terminal::SCS(uint32_t p)
{
	// no default

    log("SCS(%u)", p);

    //! @todo

    return false;
}

}
