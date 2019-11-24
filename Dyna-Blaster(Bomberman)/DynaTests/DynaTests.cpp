#include "pch.h"
#include "CppUnitTest.h"
#include "../Dyna-Blaster(Bomberman)/Monster.h"
#include "../Dyna-Blaster(Bomberman)/Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynaTests
{
	TEST_CLASS(MonsterTest)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			Monster monster(Monster::Type::Ballom);
			Assert::IsTrue(monster.GetType() == Monster::Type::Ballom);
		}
	};
}
