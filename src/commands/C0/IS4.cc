
#include <terminal/Terminal.hh>

namespace terminal {

// Information Separator Four (FS - File Separator)
// ECMA-48 8.3.72
bool
Terminal::IS4()
{
    if (m_verbose)
        log("IS4");

    // noop

    return true;
}


}
