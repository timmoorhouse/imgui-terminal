
#include <terminal/Terminal.hh>

namespace terminal {

// Set Line Limit
// ECMA-48 8.3.123
bool
Terminal::SLL(uint32_t p)
{
	// no default

    log("SLL(%u)", p);

    //! @todo

    return false;
}

}
