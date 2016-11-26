
#include <terminal/Terminal.hh>

namespace terminal {

// Set Page Limit
// ECMA-48 8.3.133
bool
Terminal::SPL(uint32_t p)
{
	// no default

    log("SPL(%u)", p);

    //! @todo

    return false;
}

}
