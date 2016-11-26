
#include <terminal/Terminal.hh>

namespace terminal {

bool
Terminal::DECSET(uint32_t p)
{
    bool handled = _DECSET(p, true);

    if (m_verbose || !handled)
        log("DECSET(%u)", p);

    return handled;
}

bool
Terminal::_DECSET(uint32_t p, bool value)
{
    // no default

	dec_mode_t m = static_cast<dec_mode_t>(p);

    bool old = dec_mode(m);

    dec_mode(m, value);

    //case dec_mode_t::// 9 - xterm: don't send mouse X & Y on button press
    //case dec_mode_t::// 40 - xterm: disallow 80/132 mode
    //case dec_mode_t::// 41 - xterm: no more(1) fix
    //case dec_mode_t::// 44 - xterm: turn off margin bell
    //case dec_mode_t::// 45 - xterm: no reverse wraparound mode
    //case dec_mode_t::// 46 - xterm: stop logging
    //case dec_mode_t::// 47 - xterm: use normal screen buffer

	switch(m) {

    case dec_mode_t::DECARM:
        return DECARM(value);

    case dec_mode_t::DECAWM:
        return DECAWM(value);

    case dec_mode_t::DECCKM:
        return DECCKM(value);

    case dec_mode_t::DECCOLM:
        return DECCOLM(value);

    case dec_mode_t::DECOM:
        return DECOM(value);

    case dec_mode_t::DECSCLM:
        return DECSCLM(value);

    case dec_mode_t::DECSCNM:
        return DECSCNM(value);

    case dec_mode_t::DECTCEM:
        return DECTCEM(value);

    // ******************************************

#if 0
    case dec_mode_t::DECAAM:
    case dec_mode_t::DECANM:
    case dec_mode_t::DECARSM:
    case dec_mode_t::DECATCBM:
    case dec_mode_t::DECATCUM:
    case dec_mode_t::DECBBSM:
    case dec_mode_t::DECBKM:
    case dec_mode_t::DECCANSM:
    case dec_mode_t::DECCAPSLK:
    case dec_mode_t::DECCRTSM:
    case dec_mode_t::DECECM:
    case dec_mode_t::DECESKM:
    case dec_mode_t::DECFWM:
    case dec_mode_t::DECHDPXM:
    case dec_mode_t::DECHEBM:
    case dec_mode_t::DECHEM:
    case dec_mode_t::DECHWUM:
    case dec_mode_t::DECIPEM:
    case dec_mode_t::DECKBUM:
    case dec_mode_t::DECKLHIM:
    case dec_mode_t::DECKPM:
    case dec_mode_t::DECLRMM:
    case dec_mode_t::DECMCM:
    case dec_mode_t::DECNAKB:
    case dec_mode_t::DECNCSM:
    case dec_mode_t::DECNKM:
    case dec_mode_t::DECNRCM:
    case dec_mode_t::DECNULM:
    case dec_mode_t::DECNUMLK:
    case dec_mode_t::DECOSCNM:
    case dec_mode_t::DECPCCM:
    case dec_mode_t::DECRLCM:
    case dec_mode_t::DECRLM:
    case dec_mode_t::DECRPL:
    case dec_mode_t::DECVCCM:
    case dec_mode_t::DECXRLM:
#endif
	}

    return false;
}

}
