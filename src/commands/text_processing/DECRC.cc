
#include <terminal/Terminal.hh>

namespace terminal {

// Restore Cursor
bool
Terminal::DECRC()
{
	bool handled = _DECRC();

	if (m_verbose || !handled)
		log("DECRC");

    return handled;
}

bool
Terminal::_DECRC()
{
	auto &b = s();

	b.restore_cursor();

	return false; //! @todo
}

}
