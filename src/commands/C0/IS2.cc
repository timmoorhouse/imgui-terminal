
#include <terminal/Terminal.hh>

namespace terminal {

// Information Separator Two (RS - Record Separator)
// ECMA-48 8.3.70
bool
Terminal::IS2()
{
    if (m_verbose)
        log("IS2");

    // noop

    return true;
}

}
