#include "pch.h"
#include "CppUnitTest.h"
#include "../Dyna-Blaster(Bomberman)/Bomb.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynaTests
{
	TEST_CLASS(BombTests)
	{
	public:
		TEST_METHOD(Constructor)
		{
			uint16_t coordX = 3, coordY = 2, id = 2;
			Bomb bomm(coordX, coordY, id);
			Assert::IsTrue(bomm.GetCoordX == 3);
		}

	};
}