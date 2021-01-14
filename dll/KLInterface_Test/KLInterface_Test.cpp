#include "pch.h"
#include "CppUnitTest.h"
#include "../Kinova Labview Interface/klinterface.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KLInterfaceTest
{
	TEST_CLASS(KLInterfaceTest)
	{
	public:
		
		TEST_METHOD(OpenTest)
		{
			Assert::AreEqual(1, open());
		}

	};
}
