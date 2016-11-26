
#ifndef TERMINAL_CURSOR_STATE_HH
#define TERMINAL_CURSOR_STATE_HH

#include <cstdint>

namespace terminal {

class CursorState
{

public:

	CursorState();

	// cursor position
	uint32_t m_r; // [1,height]
	uint32_t m_c; // [1,width]

	// character attributes set by SGR
	uint64_t m_attributes;
	//! @todo selective erase attribute

	//! @todo character sets currently in GL, GR
	//! @todo wrap flag (DECAWM)
	//! @todo state of origin mode (DECOM)
	//! @todo any SS2 or SS3 functions sent

};

}

#endif
