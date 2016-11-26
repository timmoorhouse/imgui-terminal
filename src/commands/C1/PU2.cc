
#include <terminal/Terminal.hh>

namespace terminal {

// Private Use Two
// ECMA-48 8.3.101
bool
Terminal::PU2()
{
    if (m_verbose)
        log("PU2");

    // noop

    return true;
}

}
