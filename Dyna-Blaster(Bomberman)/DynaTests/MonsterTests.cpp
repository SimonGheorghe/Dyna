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

		TEST_METHOD(MoveFunction)
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
			Assert::IsTrue(monster.GetCoordX()!= NULL);
		}
	};
}
