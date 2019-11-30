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
			Monster monster(Monster::Type::Ballom);
			Map map;
			monster.Place(map);
			Assert::IsTrue(monster.GetCoordX() != NULL);
		}
		TEST_METHOD(Move)
		{
			Monster monster(Monster::Type::Ballom);
			Map map;
			Player player(1, 1, 3, 0, 2);
			monster.Place(map);
			if (dynamic_cast<Block*>(map[{monster.GetCoordX() - 1, monster.GetCoordY()}]))
				map.SetBlock(Block::Type::NoneBlock, monster.GetCoordX() - 1, monster.GetCoordY());
			else
				if (dynamic_cast<Block*>(map[{monster.GetCoordX() + 1, monster.GetCoordY()}]))
					map.SetBlock(Block::Type::NoneBlock, monster.GetCoordX() + 1, monster.GetCoordY());
				else
					if (dynamic_cast<Block*>(map[{monster.GetCoordX(), monster.GetCoordY()}]) - 1)
						map.SetBlock(Block::Type::NoneBlock, monster.GetCoordX(), monster.GetCoordY() - 1);

			monster.Move(map, player);
			Assert::IsTrue(monster.GetCoordX()!=monster.GetLastX() || monster.GetCoordY()!=monster.GetLastY());
		}

	};
}
