#include "pch.h"
#include "CppUnitTest.h"
#include "../Dyna-Blaster(Bomberman)/Monster.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace DynaTests
{
	TEST_CLASS(MonsterTests)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			Monster monster(Monster::Type::Ballom);
			Assert::IsTrue(monster.GetType() == Monster::Type::Ballom);
		}

		TEST_METHOD(Print)
		{
			Monster monster(Monster::Type::Ekutopu);
			std::stringstream stream;
			stream << monster;
			Assert::AreEqual(std::string("Ek"), stream.str(), L"You see this message if name is  not the same");
		}

		TEST_METHOD(PlaceFunction)
		{
			std::vector<Monster*> enemies;
			enemies.push_back(new Monster(Monster::Type::Ballom));

			Map map(Map::Stage::TheWall, 0);
			map.SetWidth(Map::Width::Narrow);
			map.SetLength(Map::Length::Short);
			map.Create();

			enemies[0]->Place(map, enemies);

			Assert::IsTrue(enemies[0]->GetCoordX() != NULL);
		}
		TEST_METHOD(Move)
		{
			std::vector<Monster*> enemies;
			enemies.push_back(new Monster(Monster::Type::Ballom));

			Map map(Map::Stage::TheWall, 0);
			map.SetWidth(Map::Width::Narrow);
			map.SetLength(Map::Length::Short);
			map.Create();

			enemies[0]->Place(map, enemies);

			Player player(1, 1, 3, 0, 2);

			if (dynamic_cast<Block*>(map[{enemies[0]->GetCoordX() - 1, enemies[0]->GetCoordY()}]))
				map.SetBlock(Block::Type::NoneBlock, enemies[0]->GetCoordX() - 1, enemies[0]->GetCoordY());
			else
				if (dynamic_cast<Block*>(map[{enemies[0]->GetCoordX() + 1, enemies[0]->GetCoordY()}]))
					map.SetBlock(Block::Type::NoneBlock, enemies[0]->GetCoordX() + 1, enemies[0]->GetCoordY());
				else
					if (dynamic_cast<Block*>(map[{enemies[0]->GetCoordX(), enemies[0]->GetCoordY()}]) - 1)
						map.SetBlock(Block::Type::NoneBlock, enemies[0]->GetCoordX(), enemies[0]->GetCoordY() - 1);

			enemies[0]->Move(map, player);
			Assert::IsTrue(enemies[0]->GetCoordX()!=enemies[0]->GetLastX() || enemies[0]->GetCoordY()!=enemies[0]->GetLastY());
		}

	};
}
