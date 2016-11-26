
#include <terminal/Terminal.hh>

namespace terminal {

// Set Page Home
// ECMA-48 8.3.131
bool
Terminal::SPH(uint32_t p)
{
	// no default

    log("SPH(%u)", p);

    //! @todo

    return false;
}

}
