
#include <terminal/Terminal.hh>
#include <algorithm>
#include <cstdarg>

namespace terminal {

void
Terminal::output(uint8_t c)
{
	m_output.push_back(c);
}

void
Terminal::output(const char *fmt, ...)
{
	//! @todo
	char buf[256];
	va_list args;
	va_start(args, fmt);
	int size = vsnprintf(buf, sizeof(buf), fmt, args);
	va_end(args);
	for (int i=0; i < size; i++)
		output(buf[i]);
}

int
Terminal::read(char *buf, int len)
{
	int navail = m_output.size();
	int nread = std::min(len, navail);
	//! @todo slow, but good enough for now
	for (int i=0; i < nread; i++)
		buf[i] = m_output[i];
	//! @todo generally assume everything will get read, so this should be OK
	int nunread = navail - nread;
	for (int i = 0; i < nunread; i++)
		m_output[i] = m_output[i+nread];
	m_output.resize(nunread);
	return nread;
}

}
