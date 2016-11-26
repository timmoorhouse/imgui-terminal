
#include <terminal/Terminal.hh>

namespace terminal {

// Start of Heading
// ECMA-48 8.3.127
bool
Terminal::SOH()
{
    if (m_verbose)
        log("SOH");

    // noop

    return false;
}

}
