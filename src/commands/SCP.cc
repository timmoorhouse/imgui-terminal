
#include <terminal/Terminal.hh>

namespace terminal {

// Select Character Path
// ECMA-48 8.3.111
bool
Terminal::SCP(uint32_t p1, uint32_t p2)
{
	// no default

    log("SCP(%u,%u)", p1, p2);

    //! @todo

    return false;
}

}
