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
			Bomb bomb(coordX, coordY, id);
			Assert::IsTrue(bomb.GetCoordX == 3);
		}

		TEST_METHOD(Print)
		{
			uint16_t coordX = 0, coordY = 0, id = 0;
			Bomb bomb(coordX, coordY, id);
			std::stringstream stream;
			stream << bomb;
			Assert::AreEqual(std::string("*"), stream.str(), L"You see this message if name is  not the same");
		}
	};
}