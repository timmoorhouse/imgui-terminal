
#include <terminal/Terminal.hh>

namespace terminal {

bool
Terminal::DECDC(uint32_t p)
{
	bool handled = false;

	if (m_verbose || !handled)
		log("DECDC(%u)", p);

	return handled;
}

}
