
#include <terminal/Terminal.hh>
#include <type_traits>

namespace terminal {

bool
Terminal::mode(mode_t m)
{
	auto e = m_mode.find(static_cast<std::underlying_type_t<mode_t>>(m));
	if (e != m_mode.end())
		return e->second;
	else
		return false;
}

void
Terminal::mode(mode_t m, bool set)
{
	m_mode[static_cast<std::underlying_type_t<mode_t>>(m)] = set;
}

bool
Terminal::dec_mode(dec_mode_t m)
{
	auto e = m_dec_mode.find(static_cast<std::underlying_type_t<dec_mode_t>>(m));
	if (e != m_dec_mode.end())
		return e->second;
	else
		return false;
}

void
Terminal::dec_mode(dec_mode_t m, bool set)
{
	m_dec_mode[static_cast<std::underlying_type_t<dec_mode_t>>(m)] = set;
}

}
