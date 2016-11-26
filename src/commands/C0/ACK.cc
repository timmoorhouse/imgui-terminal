
#include <terminal/Terminal.hh>

namespace terminal {

// Acknowledge
// ECMA-48 8.3.1
bool
Terminal::ACK()
{
    if (m_verbose)
        log("ACK");

    // noop

    return true;
}

}
