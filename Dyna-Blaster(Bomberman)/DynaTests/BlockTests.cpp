#include "pch.h"
#include "CppUnitTest.h"
#include "../Dyna-Blaster(Bomberman)/Block.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynaTests
{
	TEST_CLASS(BlockTests)
	{
	public:
		TEST_METHOD(Constructor)
		{
			Block block(Block::Type::HardBlock);
			Assert::IsTrue(block.GetType() == Block::Type::HardBlock);
		}

		TEST_METHOD(Print)
		{
			Block block(Block::Type::NoneBlock);
			std::stringstream stream;
			stream << block;
			Assert::AreEqual(std::string("   "), stream.str(), L"You see this message if the blocks are not the same");
		}
		
	};
}