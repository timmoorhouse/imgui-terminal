
#include <terminal/Terminal.hh>

namespace terminal {

// Synchronous Idle
// ECMA-48 8.3.150
bool
Terminal::SYN()
{
    if (m_verbose)
        log("SYN");

    // noop

    return true;
}

}
