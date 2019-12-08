#include "pch.h"
#include "CppUnitTest.h"
#include "../Dyna-Blaster(Bomberman)/Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace DynaTests
{
	TEST_CLASS(PlayerTests)
	{
	public:
		TEST_METHOD(Constructor)
		{
			Player player(1, 1, 3, 0, 2);
			Assert::IsTrue(player.GetFire() == 1 && player.GetNoOfBombs()==1 && player.GetHealth()==3 && player.GetScore()==0 && player.GetSpeed()==2);
		}

		TEST_METHOD(Print)
		{
			Player player(1, 1, 3, 0, 2);
			std::stringstream stream;
			stream << player;
			Assert::AreEqual(std::string("[]"), stream.str(), L"You see this message if name is  not the same");
		}
		TEST_METHOD(UpdatePlayerPower)
		{
			Player player(1, 1, 3, 0, 2);
			uint16_t f = player.GetFire();
			player.UpdatePlayerPower(Powers::Type::FireUp);
			Assert::IsTrue(player.GetFire() == f + 1);

			f = player.GetFire();
			player.UpdatePlayerPower(Powers::Type::FireDown);
			Assert::IsTrue(player.GetFire() == f - 1);

			f = player.GetNoOfBombs();
			player.UpdatePlayerPower(Powers::Type::BombUp);
			Assert::IsTrue(player.GetNoOfBombs() == f + 1);

			f = player.GetNoOfBombs();
			player.UpdatePlayerPower(Powers::Type::BombDown);
			Assert::IsTrue(player.GetNoOfBombs() == f - 1);

			f = player.GetSpeed();
			player.UpdatePlayerPower(Powers::Type::SkateUp);
			Assert::IsTrue(player.GetSpeed() == f + 1);

			f = player.GetSpeed();
			player.UpdatePlayerPower(Powers::Type::SkateDown);
			Assert::IsTrue(player.GetSpeed() == f - 1);

			player.UpdatePlayerPower(Powers::Type::SoftBlockPass);
			Assert::IsTrue(player.GetHasSoftBlockPass() == true);

			player.UpdatePlayerPower(Powers::Type::BombPass);
			Assert::IsTrue(player.GetHasBombPass() == true);

			f = player.GetHealth();
			player.UpdatePlayerPower(Powers::Type::Heart);
			Assert::IsTrue(player.GetHealth() == f + 1);

			player.UpdatePlayerPower(Powers::Type::Vest);
			Assert::IsTrue(player.GetHasVest() == true);

			player.UpdatePlayerPower(Powers::Type::RemoteControl);
			Assert::IsTrue(player.GetHasRemoteControl() == true);
		}

		TEST_METHOD(Place)
		{
			Player player(1, 1, 3, 0, 2);

			Map map(Map::Stage::TheWall, 0);
			map.SetWidth(Map::Width::Narrow);
			map.SetLength(Map::Length::Short);
			map.Create();
			player.Place(map, 1, 1);
			Assert::IsTrue(player.GetCoordX() !=0 && player.GetCoordY() !=0);
		}

		TEST_METHOD(Move)
		{
			Player player(1, 1, 3, 0, 2);

			Map map(Map::Stage::TheWall, 0);
			map.SetWidth(Map::Width::Narrow);
			map.SetLength(Map::Length::Short);
			map.Create();

			player.Place(map, 1, 1);
			player.Move(map, 'W');
			Assert::IsTrue(player.GetCoordX()==1 && player.GetCoordY() == 1);
		}

		TEST_METHOD(PlaceBomb)
		{
			Player player(1, 1, 3, 0, 2);

			Map map(Map::Stage::TheWall, 0);
			map.SetWidth(Map::Width::Narrow);
			map.SetLength(Map::Length::Short);
			map.Create();

			player.Place(map, 1, 1);
			player.Move(map, 'W');
			player.PlaceBomb(map);
			Assert::IsTrue(player.GetCoordX() == 1 && player.GetCoordY() == 1);
		}


		TEST_METHOD(DeleteBomb)
		{
			Player player(1, 2, 3, 0, 2);

			Map map(Map::Stage::TheWall, 0);
			map.SetWidth(Map::Width::Narrow);
			map.SetLength(Map::Length::Short);
			map.Create();

			player.Place(map, 1, 1);
			player.PlaceBomb(map);
			Assert::IsTrue(player.GetCoordX() == 1 && player.GetCoordY()==1);
		}

		TEST_METHOD(AddScore)
		{
			Player player(1, 1, 3, 100, 2);
			uint32_t s = player.GetScore();
			player.AddScore(200);
			Assert::IsTrue(player.GetScore() == 300);
		}

		TEST_METHOD(IsOnBomb)
		{
			Player player(1, 1, 3, 100, 2);
			Map map(Map::Stage::TheWall, 0);
			map.SetWidth(Map::Width::Narrow);
			map.SetLength(Map::Length::Short);
			map.Create();

			player.Place(map, 1, 3);
			player.PlaceBomb(map);
			Assert::IsTrue(player.IsOnBomb());
		}
	};
}