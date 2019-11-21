#include "Powers.h"

Powers::Powers(Power power):
	m_power(power)
{
	//empty
}


bool Powers::isBlock()
{
	return false;
}

bool Powers::GetPowerStatus()
{
	return m_powersIsHidden;
}

Powers::Power Powers::GetPowerType() const
{
	return m_power;
}

void Powers::SetPowerStatus(bool value)
{
	m_powersIsHidden = value;
}

std::ostream& operator<<(std::ostream& out, const Powers& power)
{
	if (power.m_powersIsHidden == 1)
		out << char(176) << char(175);
	else
		switch (power.m_power)
		{
		case Powers::Power::BombDown:
			out << "BD";
			break;

		case Powers::Power::BombPass:
			out << "BP";
			break;
		case Powers::Power::FireDown:
			out << "FD";
			break;
		case Powers::Power::FireUp:
			out << "FU";
			break;
		case Powers::Power::BombUp:
			out << "BU";
			break;
		case Powers::Power::Heart:
			out << "HP";
			break;
		case Powers::Power::RemoteControl:
			out << "RC";
			break;
		case Powers::Power::SkateDown:
			out << "SD";
			break;
		case Powers::Power::SkateUp:
			out << "SU";
			break;
		case Powers::Power::SoftBlockPass:
			out << "SP";
			break;
		case Powers::Power::Vest:
			out << "VE";
			break;
		default:
			break;
		}
	return out;
}
