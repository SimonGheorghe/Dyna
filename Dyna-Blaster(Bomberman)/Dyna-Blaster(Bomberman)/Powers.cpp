#include "Powers.h"

Powers::Powers(Power power):
	m_power(power)
{
	//empty
}

void Powers::UpdatePlayerPower(Player player, Power power)
{
	switch (power)
	{
	case Powers::Power::FireUp:
	{   
		player.SetFire(player.GetFire() + 1);
	}
		break;
	case Powers::Power::FireDown:
	{
		if(player.GetFire()>1)
			player.SetFire(player.GetFire() - 1);
	}
		break;
	case Powers::Power::BombUp:
		player.SetNoOfBombs(player.GetNoOfBombs() + 1);
		break;
	case Powers::Power::BombDown:
		if (player.GetNoOfBombs() > 1)
			player.SetNoOfBombs(player.GetNoOfBombs() - 1);
		break;
	case Powers::Power::SkateUp:
		if(player.GetSpeed()<4)
			player.SetSpeed(player.GetSpeed() + 1);
		break;
	case Powers::Power::SkateDown:
		if (player.GetSpeed() > 1)
			player.SetSpeed(player.GetSpeed() - 1); 
		break;
	case Powers::Power::SoftBlockPass:
		player.SetSoftBlockPass(true);
		break;
	case Powers::Power::BombPass:
		player.SetBombPass(true);
		break;
	case Powers::Power::Heart:
		player.SetHealth(player.GetHealth() + 1);
		break;
	case Powers::Power::Vest:
		player.SetVest(true);
		break;
	case Powers::Power::RemoteControl:
		player.SetRemoteControl(true);
		break;
	default:
		break;
	}
}
