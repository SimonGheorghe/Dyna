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
	};
}