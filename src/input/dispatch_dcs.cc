
#include <terminal/Terminal.hh>
#include "ascii.hh"

namespace terminal {

// Device Control String
// ECMA-48 8.3.27
bool
Terminal::p_dispatch_dcs()
{
    log("DCS[%s]", m_parse.m_parm_s.c_str());

    //! @todo

    // DCS Ps $ p D..D ST    - DECRSTS restore terminal state

    // DCS $ q D..D ST       - DECRQSS request selection or setting

    // DCS Ps $ r D..D ST    - DECRPSS report selection or setting
    // DCS Ps r D..D ST      - DECLBAN load banner

    // DCS Ps $ t D..D ST    - DECRSPS restore presentation state

    // DCS Pn ! u Dscs ST    - DECAUPSS
    // DCS 1 $ u D..D ST     - DECCIR cursor information report
    // DCS 2 $ u D..D ST     - DECTABSR tab stop report

    // DCS Ps v D..D ST      - DECLANS load answerback

    // DCS " x D..D ST       - DECPFK print function key

    // DCS " y D..D ST       - DECPAK program alphanumeric key

    // DCS " z D..D ST       - DECCKD copy key default
    // DCS Pm ! z D..D ST    - DECDMAC define macro

    // DCS Pm { D..D ST      - DECDLD
    // DCS ! { D..D ST       - DECSTUI set terminal unit id

    // DCS ! | D..D ST       - DECRPTUI report terminal unit id
    // DCS Pm | D..D ST      - DECUDK user defined keys

    // DCS " } D..D ST       - DECRPFK report function key definition

    // DCS " ~ D..D ST       - DECRPAK report all modifiers/alphanumeric key state

    return false;
}

}

