
#include <terminal/Terminal.hh>

namespace terminal {

// Data Link Escape
// ECMA-48 8.3.33
bool
Terminal::DLE()
{
    if (m_verbose)
        log("DLE");

    // noop

    return true;
}

}
