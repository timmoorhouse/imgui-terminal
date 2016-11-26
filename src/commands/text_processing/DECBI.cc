
#include <terminal/Terminal.hh>

namespace terminal {

// Back Index
bool
Terminal::DECBI()
{
    bool handled = _DECBI();

    if (m_verbose || !handled)
        log("DECBI");

    return handled;
}

bool
Terminal::_DECBI()
{
    auto &b = s();

    if (b.col() > 1)
        b.set_col(b.col() - 1);
    else
    	_SR(1);

    return true;
}

}
