
#include <terminal/Terminal.hh>

namespace terminal {

// End of Transmission
// ECMA-48 8.3.45
bool
Terminal::EOT()
{
    if (m_verbose)
        log("EOT");

    // noop

    return true;
}

}
