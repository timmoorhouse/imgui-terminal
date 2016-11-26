
#include <terminal/Terminal.hh>

namespace terminal {

// End of Medium
// ECMA-48 8.3.42
bool
Terminal::EM()
{
   if (m_verbose)
        log("EM");

    // noop

    return true;
}

}
