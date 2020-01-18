#include "Powers.h"

Powers::Powers(Type power, const float x, const float y, std::map<std::string, sf::Texture>& textures):
	m_power(power)
{
	SetPosition(x, y);
	//SetTexture(textures);
}

void Powers::Render(sf::RenderTarget& target)
{
	if(m_powersIsHidden==1)
		target.draw(m_sprites[0]);
	target.draw(m_sprites[(uint16_t)m_power]);
}

bool Powers::GetPowerStatus()
{
	return m_powersIsHidden;
}

Powers::Type Powers::GetPowerType() const
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
		case Powers::Type::BombDown:
			out << "BD";
			break;

		case Powers::Type::BombPass:
			out << "BP";
			break;
		case Powers::Type::FireDown:
			out << "FD";
			break;
		case Powers::Type::FireUp:
			out << "FU";
			break;
		case Powers::Type::BombUp:
			out << "BU";
			break;
		case Powers::Type::Heart:
			out << "HP";
			break;
		case Powers::Type::RemoteControl:
			out << "RC";
			break;
		case Powers::Type::SkateDown:
			out << "SD";
			break;
		case Powers::Type::SkateUp:
			out << "SU";
			break;
		case Powers::Type::SoftBlockPass:
			out << "SP";
			break;
		case Powers::Type::Vest:
			out << "VE";
			break;
		default:
			break;
		}
	return out;
}
