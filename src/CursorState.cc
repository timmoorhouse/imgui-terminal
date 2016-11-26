
#include <terminal/CursorState.hh>

namespace terminal {

CursorState::CursorState()
	: m_r(1)
	, m_c(1)
	, m_attributes(0)
{
}

}
