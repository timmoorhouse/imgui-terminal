
#include <terminal/Terminal.hh>

namespace terminal {

// Text Cursor Enable MOde
bool
Terminal::DECTCEM(bool set)
{
    bool handled = true;

	if (m_verbose || !handled)
    	log("DECTCEM(%u)", set);

    return handled;
}

}
