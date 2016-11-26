
#include <terminal/Terminal.hh>

namespace terminal {

bool
Terminal::IND()
{
    bool handled = _IND();

    if (m_verbose || !handled)
        log("IND");

    return handled;
}

bool
Terminal::_IND()
{
    auto &b = s();

    //! @todo this is just LF???
    if (b.row() < b.height())
        b.set_row(b.row() + 1);
    else
        _SU(1);

    return true;
}

}
