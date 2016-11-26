
#include <terminal/Terminal.hh>

namespace terminal {

bool
Terminal::DECALN()
{
	if (m_verbose)
		log("DECALN");

	auto &b = s();
	b.fill_rect(1, 1, b.height(), b.width(), 'E');

	return true;
}

}
