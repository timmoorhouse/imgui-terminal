
#ifndef TERMINAL_SCREEN_STATE_HH
#define TERMINAL_SCREEN_STATE_HH

#include <vector>
#include <terminal/CursorState.hh>

namespace terminal {

class ScreenState
{

public:

	ScreenState();

	using predicate_t = bool(*)(uint32_t r, uint32_t c,
	                            uint8_t byte, uint64_t attr);

	void resize(uint32_t width, uint32_t height);

	void fill_rect(uint32_t t, uint32_t l, uint32_t b, uint32_t r,
	               uint8_t fill = ' ', bool overall = false);

	void fill_rect_if(uint32_t t, uint32_t l, uint32_t b, uint32_t r,
	                  predicate_t,
	                  uint8_t fill = ' ', bool overall = false);

	void copy_rect(uint32_t st, uint32_t sl, uint32_t sb, uint32_t sr,
	               uint32_t dt, uint32_t dl, bool overall = false);

	uint32_t width(bool overall = false) const;

	uint32_t height(bool overall = false) const;

	uint32_t row(bool overall = false) const;
	void set_row(uint32_t r, bool overall = false);

	uint32_t col(bool overall = false) const;
	void set_col(uint32_t c, bool overall = false);

	uint32_t index(uint32_t r, uint32_t c, bool overall = false) const;

	uint32_t row_of(uint32_t index, bool overall = false) const;

	uint32_t col_of(uint32_t index, bool overall = false) const;

	uint8_t *bufp(uint32_t r, uint32_t c, bool overall = false);
	uint8_t &buf(uint32_t r, uint32_t c, bool overall = false);

	uint64_t &attr(uint32_t r, uint32_t c, bool overall = false);

	uint8_t &tab(uint32_t c, bool overall = false);

	uint64_t attributes() const;
	void attributes(uint64_t);

	void save_cursor();

	void restore_cursor();

private:

	uint32_t m_height;
	uint32_t m_width;

	CursorState m_cursor;
	CursorState m_saved_cursor;

public: //! @todo private

	struct {
		uint32_t m_top;
		uint32_t m_bottom;
		uint32_t m_left;
		uint32_t m_right;
	} m_margin;
	bool m_wrap_pending;

private:

	std::vector<uint8_t> m_screen;
	std::vector<uint64_t> m_attributes;
	std::vector<uint8_t> m_tab;

};

}

#endif
