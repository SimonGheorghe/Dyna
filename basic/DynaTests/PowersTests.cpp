#include "pch.h"
#include "CppUnitTest.h"
#include "../Dyna-Blaster(Bomberman)/Powers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace DynaTests
{
	TEST_CLASS(PowersTests)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Powers power(Powers::Type::BombDown);
			Assert::IsTrue(power.GetPowerType() == Powers::Type::BombDown);
		}

		TEST_METHOD(Print)
		{
			Powers power(Powers::Type::BombPass);
			std::stringstream stream;
			power.SetPowerStatus(0);
			stream << power;
			Assert::AreEqual(std::string("BP"), stream.str(), L"You see this message if name is  not the same");
		}
	};
}