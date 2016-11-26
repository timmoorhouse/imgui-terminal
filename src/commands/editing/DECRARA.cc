
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>

namespace terminal {

// Reverse Attributes in Rectangular Area
bool
Terminal::DECRARA(uint32_t pt, uint32_t pl, uint32_t pb, uint32_t pr, uint32_t ps)
{
	bool handled = _DECRARA(pt, pl, pb, pr, ps);

    if (m_verbose || !handled)
        log("DECRARA(%u,%u,%u,%u,%u)", pt, pl, pb, pr, ps);

    return handled;
}

bool
Terminal::_DECRARA(uint32_t pt, uint32_t pl, uint32_t pb, uint32_t pr, uint32_t ps)
{
	//! @todo defaults

	//! @todo

	return false;
}

}
