
#include <terminal/Terminal.hh>

namespace terminal {

// Set Line Home
// ECMA-48 8.3.122
bool
Terminal::SLH(uint32_t p)
{
	// no default

    log("SLH(%u)", p);

    //! @todo

    return false;
}

}
