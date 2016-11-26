
#include <terminal/Terminal.hh>

namespace terminal {

// Null
// ECMA-48 8.3.88
bool
Terminal::NUL()
{
    if (m_verbose)
        log("NUL");

    // noop

    return true;
}

}
