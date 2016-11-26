
#ifndef TERMINAL_PARSE_STATE_HH
#define TERMINAL_PARSE_STATE_HH

#include <vector>
#include <string>
#include <cstdint>

namespace terminal {

struct ParseState
{
	enum class state_t {
		GROUND,

		ESCAPE,
		ESCAPE_INTERMEDIATE,

		CSI_ENTRY,
		CSI_IGNORE,
		CSI_PARAMETER,
		CSI_INTERMEDIATE,

		DCS_ENTRY,
		DCS_INTERMEDIATE,
		DCS_IGNORE,
		DCS_PARAMETER,
		DCS_PASSTHROUGH,

		SOS_PM_APC_STRING,

		OSC_STRING
	} m_state = state_t::GROUND;

	std::vector<uint8_t>  m_cseq_s;
	std::string           m_int;
	std::string           m_parm_s;
	std::vector<uint32_t> m_parm;

	void reset()
	{
		m_cseq_s.clear();
		m_int.clear();
		m_parm_s.clear();
		m_parm.clear();
	}

};

}

#endif
