
#include <terminal/Terminal.hh>

namespace terminal {

// Set Mode
// ECMA-48 8.3.125
bool
Terminal::SM(uint32_t p)
{
    bool handled = _SM(p, true);

    if (m_verbose || !handled)
        log("SM(%u)", p);

    return handled;
}

bool
Terminal::_SM(uint32_t p, bool value)
{
	// no default

	mode_t m = static_cast<mode_t>(p);

	bool old = mode(m);
    mode(m, value);

	//case mode_t::EBM:

	switch (m) {

	case mode_t::IRM:
		return IRM(value);

	case mode_t::LNM:
		return LNM(value);

    // ******************************************

#if 0
	case mode_t::BDSM:
	case mode_t::CRM:
	case mode_t::DCSM:
	case mode_t::ERM:
	case mode_t::FEAM:
	case mode_t::FETM:
	case mode_t::GATM:
	case mode_t::GRCM:
	case mode_t::HEM:
	case mode_t::KAM:
	case mode_t::MATM:
	case mode_t::PUM:
	case mode_t::SATM:
	case mode_t::SRM:
	case mode_t::SRTM:
	case mode_t::TSM:
	case mode_t::TTM:
	case mode_t::VEM:
	case mode_t::ZDM:
#endif

	}

    //! @todo check mode valid?
    return false;
}

}
