
#include <terminal/Terminal.hh>

namespace terminal {

// Set Line Spacing
// ECMA-48 8.3.124
bool
Terminal::SLS(uint32_t p)
{
	// no default

    log("SLS(%u)", p);

    //! @todo

    return false;
}

}
