
#include <terminal/Terminal.hh>

namespace terminal {

// Privacy Message
// ECMA-48 8.3.94
bool
Terminal::PM(const std::string &p)
{
    log("PM[%s]", p.c_str());

    //! @todo

    return false;
}

}
