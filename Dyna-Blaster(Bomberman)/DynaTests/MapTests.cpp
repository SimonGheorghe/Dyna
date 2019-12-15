#include "pch.h"
#include "CppUnitTest.h"

#include "../Dyna-Blaster(Bomberman)/Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynaTests
{
	TEST_CLASS(MapTests)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Map map (Map::Stage::TheWall, 0);
			Assert::IsTrue(map.GetStage() == Map::Stage::TheWall);
		}
		TEST_METHOD(Print)
		{
			Map map(Map::Stage::River, 2);
			std::stringstream stream;
			stream << map;
			Assert::AreEqual(std::string("River --- Round 2"), stream.str(), L"You see this message if the blocks are not the same");
		}

		TEST_METHOD(ClearMap)
		{
			uint16_t playerFire = 5;
			uint16_t playerNoOfBombs = 1;
			uint16_t playerHealth = 5;
			uint16_t playerScore = 0;
			uint16_t playerSpeed = 2;
			Player player(playerFire, playerNoOfBombs, playerHealth, playerScore, playerSpeed);

			Map map(Map::Stage::TheWall, 0);
			map.SetWidth(Map::Width::Narrow);
			map.SetLength(Map::Length::Short);
			map.Create();
			player.Place(map, 1, 1);
			player.PlaceBomb(map);
			player.ExplodeBomb(map, 0);
			map.ClearMap(1,1);

			Assert::IsTrue(dynamic_cast<Block*>(map[{1, 1}])->GetType() == Block::Type::NoneBlock);
		}
	};
}