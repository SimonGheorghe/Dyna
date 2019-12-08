#include "pch.h"
#include "CppUnitTest.h"
#include "../Dyna-Blaster(Bomberman)/Map.h"

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
	};
}