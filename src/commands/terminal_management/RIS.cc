
#include <terminal/Terminal.hh>

namespace terminal {

// Reset to Initial State
// ECMA-48 8.3.105
bool
Terminal::RIS()
{
    bool handled = _RIS();

    if (m_verbose || !handled)
        log("RIS");

    return handled;
}

bool
Terminal::_RIS()
{
    m_parse.reset();

    //! @todo

    //! @todo clear tab stops

    //! @todo remove qualified areas

    _SGR(0);

    //! @todo put all character positions into the erased state

    //! @todo move the active presentation position to the first position of the first line in the presentation component

    //! @todo move the active data position to the first character position of the first line in the data component

    _CUP(1,1);

    resize(80, 24);
    _DECSTBM(1, 24);
    _DECSLRM(1, 80);

    _DECST8C();

    m_mode.clear();
    m_dec_mode.clear();
    dec_mode(dec_mode_t::DECAWM, true);
    dec_mode(dec_mode_t::DECARM, true);
    dec_mode(dec_mode_t::DECTCEM, true);

    return true;
}

}
