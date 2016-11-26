
#include <terminal/Terminal.hh>

namespace terminal {

// Save Cursor
bool
Terminal::DECSC()
{
	bool handled = _DECSC();

	if (m_verbose || !handled)
		log("DECSC");

    return handled;
}

bool
Terminal::_DECSC()
{
	auto &b = s();

	b.save_cursor();

	return false; //! @todo
}

}
