
#include <terminal/Terminal.hh>

namespace terminal {

// Forward Index
bool
Terminal::DECFI()
{
    bool handled = _DECFI();

    if (m_verbose || !handled)
        log("DECFI");

    return handled;
}

bool
Terminal::_DECFI()
{
    auto &b = s();

    if (b.col() < b.width())
        b.set_col(b.col() + 1);
    else
    	_SL(1);

    return true;
}

}
