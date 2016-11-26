
#include <terminal/Terminal.hh>

namespace terminal {

// Identify Graphic Subrepertoire
// ECMA-48 8.3.66
bool
Terminal::IGS(uint32_t p)
{
	// no default

    log("IGS(%u)", p);

    //! @todo

    return false;
}

}
