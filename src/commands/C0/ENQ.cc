
#include <terminal/Terminal.hh>

namespace terminal {

// Enquiry
// ECMA-48 8.3.44
bool
Terminal::ENQ()
{
    //if (m_verbose)
    log("ENQ");

    // noop
    //! @todo DEC sends answerback message

    return false;
}

}
