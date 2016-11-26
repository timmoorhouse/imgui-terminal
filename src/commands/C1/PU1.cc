
#include <terminal/Terminal.hh>

namespace terminal {

// Private Use One
// ECMA-48 8.3.100
bool
Terminal::PU1()
{
    if (m_verbose)
        log("PU1");

    // noop

    return true;
}

}
