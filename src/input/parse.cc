
#include <terminal/Terminal.hh>
#include <terminal/attribute.hh>
#include "ascii.hh"
#include <cstring>
#include <cassert>

namespace terminal {

uint32_t
Terminal::p(uint32_t idx)
{
    return (idx < m_parse.m_parm.size())
        ? m_parse.m_parm[idx]
        : 0;
}

bool
Terminal::p_ignore(uint8_t c)
{
    return true;
}

bool
Terminal::p_control_string(uint8_t c)
{
    m_parse.m_parm_s.push_back(c);
    return true;
}

//! @todo combine with p_control_string
bool
Terminal::p_osc_put(uint8_t c)
{
    m_parse.m_parm_s.push_back(c);
    return true;
}

bool
Terminal::p_parameter(uint8_t c)
{

    switch (c) {

    case '0': // 0x30
    case '1': // 0x31
    case '2': // 0x32
    case '3': // 0x33
    case '4': // 0x34
    case '5': // 0x35
    case '6': // 0x36
    case '7': // 0x37
    case '8': // 0x38
    case '9': // 0x39
        if (m_parse.m_parm.empty())
            m_parse.m_parm.emplace_back();
        m_parse.m_parm.back() = m_parse.m_parm.back() * 10 + c - '0';
        return true;

    case ';': // 0x3B - separator
        m_parse.m_parm.emplace_back(0);
        return true;

#if 0
    case ':': // 0x3A - separator within parameter
    case '<': // 0x3C - for future expansion
    case '=': // 0x3D
    case '>': // 0x3E
    case '?': // 0x3F - used for DEC private parameters
            // ignore all of these at present
#endif
    }

    return true;
}

bool
Terminal::p_intermediate(uint8_t c)
{
    m_parse.m_int.push_back(c);
    return true;
}

bool
Terminal::p_print(uint8_t c)
{
    if (m_verbose) {
        auto flags = std::cout.flags();
        std::cout << "print 0x" << std::hex << (uint16_t)c;
        if (isprint(c))
            std::cout << " (" << c << ")";
        std::cout << std::endl;
        std::cout.flags(flags);
    }
    auto &b = s();
    if (b.m_wrap_pending && dec_mode(dec_mode_t::DECAWM)) {
        _CR();
        _LF();
    }
    uint32_t col = std::min(b.width(), b.col());
    uint32_t row = b.row();
    if (mode(mode_t::IRM))
        _ICH(1);
    b.buf(row, col) = c;
    b.attr(row, col) = b.attributes();
    b.m_wrap_pending = false;
    if (b.col() < b.width())
        b.set_col(b.col() + 1);
    else if (dec_mode(dec_mode_t::DECAWM))
        b.m_wrap_pending = true;

    return true;
}

void
Terminal::p_unhook()
{
    log("p_unhook str=[%s]", m_parse.m_parm_s.c_str());
    //! @todo call DCS, APC, etc
}

void
Terminal::p_clear_parms()
{
    m_parse.reset();
}

void
Terminal::p_hook()
{
    log("p_hook");
}

#if 0
void
Terminal::p_osc_start()
{
    log("p_osc_start");
}
#endif

void
Terminal::write(uint8_t c)
{
    if (m_verbose)
        log("write(0x%02X)", c);

    using state_t = ParseState::state_t;

    state_t prev_state = m_parse.m_state;
    state_t next_state = m_parse.m_state;

    using action_t = bool (Terminal::*)(uint8_t);

    action_t action = nullptr;

    // ANYWHERE
    /*
        0x18       => [:execute, transition_to(:GROUND)],
        0x1a       => [:execute, transition_to(:GROUND)],
        0x80..0x8f => [:execute, transition_to(:GROUND)],
        0x91..0x97 => [:execute, transition_to(:GROUND)],
        0x99       => [:execute, transition_to(:GROUND)],
        0x9a       => [:execute, transition_to(:GROUND)],
        0x9c       => [:execute, transition_to(:GROUND)],
        0x1b       => transition_to(:ESCAPE),
        0x98       => transition_to(:SOS_PM_APC_STRING),
        0x9e       => transition_to(:SOS_PM_APC_STRING),
        0x9f       => transition_to(:SOS_PM_APC_STRING),
        0x90       => transition_to(:DCS_ENTRY),
        0x9d       => transition_to(:OSC_STRING),
        0x9b       => transition_to(:CSI_ENTRY),
    */
    switch (c) {
    case 0x18:
    case 0x1A:
    case 0x80:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x84:
    case 0x85:
    case 0x86:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8A:
    case 0x8B:
    case 0x8C:
    case 0x8D:
    case 0x8E:
    case 0x8F:
    case 0x91:
    case 0x92:
    case 0x93:
    case 0x94:
    case 0x95:
    case 0x96:
    case 0x97:
    case 0x99:
    case 0x9A:
    case 0x9C:
        action = &Terminal::p_dispatch;
        next_state = state_t::GROUND;
        break;

    case 0x1B:
        next_state = state_t::ESCAPE;
        break;

    case 0x98:
    case 0x9E:
    case 0x9F:
        next_state = state_t::SOS_PM_APC_STRING;
        break;

    case 0x90:
        next_state = state_t::DCS_ENTRY;
        break;

    case 0x9D:
        next_state = state_t::OSC_STRING;
        break;

    case 0x9B:
        next_state = state_t::CSI_ENTRY;
        break;

    default:

        switch (m_parse.m_state) {

        case state_t::GROUND:
            /*
                0x00..0x17 => :execute,
                0x19       => :execute,
                0x1c..0x1f => :execute,
                0x20..0x7f => :print,
                0x80..0x8f => :execute,
                0x91..0x9a => :execute,
                0x9c       => :execute
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F)) ||
                ((c >= 0x80) && (c <= 0x8F)) ||
                ((c >= 0x91) && (c <= 0x9A)) ||
                (c == 0x9C)) {
                action = &Terminal::p_dispatch;
            } else if ((c >= 0x20) && (c <= 0x7F)) {
                action = &Terminal::p_print;
            }
            break;

        case state_t::ESCAPE:
            /*
                0x00..0x17 => :execute,
                0x19       => :execute,
                0x1c..0x1f => :execute,
                0x7f       => :ignore,
                0x20..0x2f => [:collect, transition_to(:ESCAPE_INTERMEDIATE)],
                0x30..0x4f => [:esc_dispatch, transition_to(:GROUND)],
                0x51..0x57 => [:esc_dispatch, transition_to(:GROUND)],
                0x59       => [:esc_dispatch, transition_to(:GROUND)],
                0x5a       => [:esc_dispatch, transition_to(:GROUND)],
                0x5c       => [:esc_dispatch, transition_to(:GROUND)],
                0x60..0x7e => [:esc_dispatch, transition_to(:GROUND)],
                0x5b       => transition_to(:CSI_ENTRY),
                0x5d       => transition_to(:OSC_STRING),
                0x50       => transition_to(:DCS_ENTRY),
                0x58       => transition_to(:SOS_PM_APC_STRING),
                0x5e       => transition_to(:SOS_PM_APC_STRING),
                0x5f       => transition_to(:SOS_PM_APC_STRING),
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F))) {
                action = &Terminal::p_dispatch;
            } else if (c == 0x7F) {
                action = &Terminal::p_ignore;
            } else if ((c >= 0x20) && (c <= 0x2F)) {
                action = &Terminal::p_intermediate;
                next_state = state_t::ESCAPE_INTERMEDIATE;
            } else if (((c >= 0x30) && (c <= 0x4F)) ||
                       ((c >= 0x51) && (c <= 0x57)) ||
                       (c == 0x59) ||
                       (c == 0x5A) ||
                       (c == 0x5C) ||
                       ((c >= 0x60) && (c <= 0x7E))) {
                action = &Terminal::p_dispatch_esc;
                next_state = state_t::GROUND;
            } else if (c == 0x5B) {
                next_state = state_t::CSI_ENTRY;
            } else if (c == 0x5D) {
                next_state = state_t::OSC_STRING;
            } else if (c == 0x50) {
                next_state = state_t::DCS_ENTRY;
            } else if ((c == 0x58) ||
                       (c == 0x5E) ||
                       (c == 0x5F)) {
                next_state = state_t::SOS_PM_APC_STRING;
            }
            break;

        case state_t::ESCAPE_INTERMEDIATE:
            /*
                0x00..0x17 => :execute,
                0x19       => :execute,
                0x1c..0x1f => :execute,
                0x20..0x2f => :collect,
                0x7f       => :ignore,
                0x30..0x7e => [:esc_dispatch, transition_to(:GROUND)]
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F))) {
                action = &Terminal::p_dispatch;
            } else if ((c >= 0x20) && (c <= 0x2F)) {
                action = &Terminal::p_intermediate;
            } else if (c == 0x7F) {
                action = &Terminal::p_ignore;
            } else if ((c >= 0x30) && (c <= 0x7E)) {
                action = &Terminal::p_dispatch_esc;
                next_state = state_t::GROUND;
            }
            break;

        case state_t::CSI_ENTRY:
            /*
                0x00..0x17 => :execute,
                0x19       => :execute,
                0x1c..0x1f => :execute,
                0x7f       => :ignore,
                0x20..0x2f => [:collect, transition_to(:CSI_INTERMEDIATE)],
                0x3a       => transition_to(:CSI_IGNORE),
                0x30..0x39 => [:param, transition_to(:CSI_PARAMETER)],
                0x3b       => [:param, transition_to(:CSI_PARAMETER)],
                0x3c..0x3f => [:collect, transition_to(:CSI_PARAMETER)],
                0x40..0x7e => [:csi_dispatch, transition_to(:GROUND)]
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F))) {
                action = &Terminal::p_dispatch;
            } else if (c == 0x7F) {
                action = &Terminal::p_ignore;
            } else if ((c >= 0x20) && (c <= 0x2F)) {
                action = &Terminal::p_intermediate;
                next_state = state_t::CSI_INTERMEDIATE;
            } else if (c == 0x3A) {
                next_state = state_t::CSI_IGNORE;
            } else if (((c >= 0x30) && (c <= 0x39)) ||
                       (c == 0x3B)) {
                action = &Terminal::p_parameter;
                next_state = state_t::CSI_PARAMETER;
            } else if ((c >= 0x3C) && (c <= 0x3F)) {
                action = &Terminal::p_intermediate;
                next_state = state_t::CSI_PARAMETER;
            } else if ((c >= 0x40) && (c <= 0x7E)) {
                action = &Terminal::p_dispatch_csi;
                next_state = state_t::GROUND;
            }
            break;

        case state_t::CSI_IGNORE:
            /*
                0x00..0x17 => :execute,
                0x19       => :execute,
                0x1c..0x1f => :execute,
                0x20..0x3f => :ignore,
                0x7f       => :ignore,
                0x40..0x7e => transition_to(:GROUND),
            */
             if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F))) {
                action = &Terminal::p_dispatch;
            } else if (((c >= 0x20) && (c <= 0x2F)) ||
                        (c == 0x7F)) {
                action = &Terminal::p_ignore;
            } else if ((c >= 0x40) && (c <= 0x7E)) {
                next_state = state_t::GROUND;
            }
            break;

        case state_t::CSI_PARAMETER:
            /*
                0x00..0x17 => :execute,
                0x19       => :execute,
                0x1c..0x1f => :execute,
                0x30..0x39 => :param,
                0x3b       => :param,
                0x7f       => :ignore,
                0x3a       => transition_to(:CSI_IGNORE),
                0x3c..0x3f => transition_to(:CSI_IGNORE),
                0x20..0x2f => [:collect, transition_to(:CSI_INTERMEDIATE)],
                0x40..0x7e => [:csi_dispatch, transition_to(:GROUND)]
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F))) {
                action = &Terminal::p_dispatch;
            } else if (((c >= 0x30) && (c <= 0x39)) ||
                        (c == 0x3B)) {
                action = &Terminal::p_parameter;
            } else if (c == 0x7F) {
                action = &Terminal::p_ignore;
            } else if ((c == 0x3A) ||
                       ((c >= 0x3C) && (c <= 0x3F))) {
                next_state = state_t::CSI_IGNORE;
            } else if ((c >= 0x20) && (c <= 0x2F)) {
                action = &Terminal::p_intermediate;
                next_state = state_t::CSI_INTERMEDIATE;
            } else if ((c >= 0x40) && (c <= 0x7E)) {
                action = &Terminal::p_dispatch_csi;
                next_state = state_t::GROUND;
            }
            break;

        case state_t::CSI_INTERMEDIATE:
            /*
                0x00..0x17 => :execute,
                0x19       => :execute,
                0x1c..0x1f => :execute,
                0x20..0x2f => :collect,
                0x7f       => :ignore,
                0x30..0x3f => transition_to(:CSI_IGNORE),
                0x40..0x7e => [:csi_dispatch, transition_to(:GROUND)],
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F))) {
                action = &Terminal::p_dispatch;
            } else if ((c >= 0x20) && (c <= 0x2F)) {
                action = &Terminal::p_intermediate;
            } else if (c == 0x7F) {
                action = &Terminal::p_ignore;
            } else if ((c >= 0x30) && (c <= 0x3F)) {
                next_state = state_t::CSI_IGNORE;
            } else if ((c >= 0x40) && (c <= 0x7E)) {
                action = &Terminal::p_dispatch_csi;
                next_state = state_t::GROUND;
            }
            break;

        case state_t::DCS_ENTRY:
            /*
                0x00..0x17 => :ignore,
                0x19       => :ignore,
                0x1c..0x1f => :ignore,
                0x7f       => :ignore,
                0x3a       => transition_to(:DCS_IGNORE),
                0x20..0x2f => [:collect, transition_to(:DCS_INTERMEDIATE)],
                0x30..0x39 => [:param, transition_to(:DCS_PARAMETER)],
                0x3b       => [:param, transition_to(:DCS_PARAMETER)],
                0x3c..0x3f => [:collect, transition_to(:DCS_PARAMETER)],
                0x40..0x7e => [transition_to(:DCS_PASSTHROUGH)]
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F)) ||
                (c == 0x7F)) {
                action = &Terminal::p_ignore;
            } else if (c == 0x3A) {
                next_state = state_t::DCS_IGNORE;
            } else if ((c >= 0x20) && (c <= 0x2F)) {
                action = &Terminal::p_intermediate;
                next_state = state_t::DCS_INTERMEDIATE;
            } else if (((c >= 0x30) && (c <= 0x39)) ||
                       (c == 0x3B)) {
                action = &Terminal::p_parameter;
                next_state = state_t::DCS_PARAMETER;
            } else if ((c >= 0x30) && (c <= 0x3F)) {
                action = &Terminal::p_intermediate;
                next_state = state_t::DCS_PARAMETER;
            } else if ((c >= 0x40) && (c <= 0x7E)) {
                next_state = state_t::DCS_PASSTHROUGH;
            }
            break;

        case state_t::DCS_INTERMEDIATE:
            /*
                0x00..0x17 => :ignore,
                0x19       => :ignore,
                0x1c..0x1f => :ignore,
                0x20..0x2f => :collect,
                0x7f       => :ignore,
                0x30..0x3f => transition_to(:DCS_IGNORE),
                0x40..0x7e => transition_to(:DCS_PASSTHROUGH)
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F))) {
                action = &Terminal::p_ignore;
            } else if ((c >= 0x20) && (c <= 0x2F)) {
                action = &Terminal::p_intermediate;
            } else if (c == 0x7F) {
                action = &Terminal::p_ignore;
            } else if ((c >= 0x30) && (c <= 0x3F)) {
                next_state = state_t::DCS_IGNORE;
            } else if ((c >= 0x40) && (c <= 0x7E)) {
                next_state = state_t::DCS_PASSTHROUGH;
            }
            break;

        case state_t::DCS_IGNORE:
            /*
                0x00..0x17 => :ignore,
                0x19       => :ignore,
                0x1c..0x1f => :ignore,
                0x20..0x7f => :ignore,
                0x9c       => transition_to(:GROUND)
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F)) ||
                ((c >= 0x20) && (c <= 0x7F))) {
                action = &Terminal::p_ignore;
            } else if (c == 0x9C) {
                next_state = state_t::GROUND;
            }
            break;

        case state_t::DCS_PARAMETER:
            /*
                0x00..0x17 => :ignore,
                0x19       => :ignore,
                0x1c..0x1f => :ignore,
                0x30..0x39 => :param,
                0x3b       => :param,
                0x7f       => :ignore,
                0x3a       => transition_to(:DCS_IGNORE),
                0x3c..0x3f => transition_to(:DCS_IGNORE),
                0x20..0x2f => [:collect, transition_to(:DCS_INTERMEDIATE)],
                0x40..0x7e => transition_to(:DCS_PASSTHROUGH)
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F))) {
                action = &Terminal::p_ignore;
            } else if (((c >= 0x30) && (c <= 0x39)) ||
                        (c == 0x3B)) {
                action = &Terminal::p_parameter;
            } else if (c == 0x7F) {
                action = &Terminal::p_ignore;
            } else if ((c == 0x3A) ||
                       ((c >= 0x3C) && (c <= 0x3F))) {
                next_state = state_t::DCS_IGNORE;
            } else if ((c >= 0x20) && (c <= 0x2F)) {
                action = &Terminal::p_intermediate;
                next_state = state_t::DCS_INTERMEDIATE;
            } else if ((c >= 0x40) && (c <= 0x7E)) {
                next_state = state_t::DCS_PASSTHROUGH;
            }
            break;

        case state_t::DCS_PASSTHROUGH:
            /*
                0x00..0x17 => :put,
                0x19       => :put,
                0x1c..0x1f => :put,
                0x20..0x7e => :put,
                0x7f       => :ignore,
                0x9c       => transition_to(:GROUND),
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F)) ||
                ((c >= 0x20) && (c <= 0x7E))) {
                action = &Terminal::p_control_string;
            } else if (c == 0x7F) {
                action = &Terminal::p_ignore;
            } else if (c == 0x9C) {
                next_state = state_t::GROUND;
            }
            break;

        case state_t::SOS_PM_APC_STRING: //! @todo combine with OSC_STRING???
            /*
                0x00..0x17 => :ignore,
                0x19       => :ignore,
                0x1c..0x1f => :ignore,
                0x20..0x7f => :ignore,
                0x9c       => transition_to(:GROUND)
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F)) ||
                ((c >= 0x20) && (c <= 0x7F))) {
                action = &Terminal::p_ignore;
            } else if (c == 0x9C) {
                next_state = state_t::GROUND;
            }
            break;

        case state_t::OSC_STRING:
            /*
                0x00..0x17 => :ignore,
                0x19       => :ignore,
                0x1c..0x1f => :ignore,
                0x20..0x7f => :osc_put,
                0x9c       => transition_to(:GROUND),
            */
            if ((c <= 0x17) ||
                (c == 0x19) ||
                ((c >= 0x1C) && (c <= 0x1F))) {
                action = &Terminal::p_ignore;
            } else if ((c >= 0x20) && (c <= 0x7F)) {
                action = &Terminal::p_osc_put;
            } else if (c == 0x9C) {
                next_state = state_t::GROUND;
            }
            break;

        }

    }

    bool handled = true;

    if (action)
        handled &= (this->*action)(c);

    if (next_state != prev_state) {
        // Actions on exiting state
        switch (m_parse.m_state) {

        case state_t::DCS_PASSTHROUGH:
            p_unhook();
            handled &= p_dispatch_dcs();
            break;

        case state_t::OSC_STRING:
            handled &= p_dispatch_osc();
            break;

        }

        m_parse.m_state = next_state;

        // Actions on entering state
        switch (m_parse.m_state) {
        case state_t::ESCAPE:
            p_clear_parms();
            break;

        case state_t::CSI_ENTRY:
            p_clear_parms();
            break;

        case state_t::DCS_PASSTHROUGH:
            p_hook();
            break;

#if 0
        case state_t::OSC_STRING:
            p_osc_start();
            break;
#endif
        }
    }

    if (!handled) {

        auto flags = std::cout.flags();
        // extra newline to separate log entries a bit ...
        log("PARSE: state=%d c=0x%02X(%c) int=[%s] str=[%s] #p=%u\n",
            static_cast<int>(prev_state),
            c,
            isprint(c) ? c : '?',
            m_parse.m_int.c_str(),
            m_parse.m_parm_s.c_str(),
            m_parse.m_parm.size());

    }

}

}
