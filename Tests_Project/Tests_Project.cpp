#include "pch.h"
#include "CppUnitTest.h"
#include "../AaSD_1/UnorderedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsProject
{
	TEST_CLASS(TestsProject)
	{
	public:
		
	public:
		TEST_METHOD(ConstructorsTest) {
			UnorderedList emptyList;
			Assert::IsTrue(emptyList.get_size() == 0);
			UnorderedList listWithItem(1);
			Assert::IsTrue(listWithItem.get_size() == 1);
			Assert::IsTrue(listWithItem.at(0) == 1);
		}
		TEST_METHOD(get_sizeTest) {
			UnorderedList testList;
			Assert::IsTrue(testList.get_size() == 0);
			testList.push_back(0);
			Assert::IsTrue(testList.get_size() == 1);
			for (int i = 0; i < 100; i++)
				testList.push_back(0);

			Assert::IsTrue(testList.get_size() == 101);


			for (int i = 0; i < 100; i++)
				testList.pop_back();
			Assert::IsTrue(testList.get_size() == 1);
		}

		TEST_METHOD(atTest) {
			UnorderedList testList(5);
			testList.push_front(4);
			testList.push_front(3);
			testList.push_front(2);
			testList.push_front(1);
			testList.push_front(0);
			Assert::IsTrue(testList.at(0) == 0);
			Assert::IsTrue(testList.at(1) == 1);
			Assert::IsTrue(testList.at(2) == 2);
			Assert::IsTrue(testList.at(3) == 3);
			Assert::IsTrue(testList.at(4) == 4);
			Assert::IsTrue(testList.at(5) == 5);
		}

		TEST_METHOD(push_backTest) {
			UnorderedList testList(0);
			testList.push_back(1);
			Assert::IsTrue(testList.get_size() == 2);
			testList.push_back(2);
			Assert::IsTrue(testList.get_size() == 3);
			testList.push_back(3);
			Assert::IsTrue(testList.get_size() == 4);
			testList.push_back(4);
			Assert::IsTrue(testList.get_size() == 5);
			testList.push_back(5);
			Assert::IsTrue(testList.get_size() == 6);
			Assert::IsTrue(testList.at(0) == 0);
			Assert::IsTrue(testList.at(1) == 1);
			Assert::IsTrue(testList.at(2) == 2);
			Assert::IsTrue(testList.at(3) == 3);
			Assert::IsTrue(testList.at(4) == 4);
			Assert::IsTrue(testList.at(5) == 5);

		}
		TEST_METHOD(push_frontTest) {
			UnorderedList testList(5);
			testList.push_front(4);
			Assert::IsTrue(testList.get_size() == 2);
			testList.push_front(3);
			Assert::IsTrue(testList.get_size() == 3);
			testList.push_front(2);
			Assert::IsTrue(testList.get_size() == 4);
			testList.push_front(1);
			Assert::IsTrue(testList.get_size() == 5);
			testList.push_front(0);
			Assert::IsTrue(testList.get_size() == 6);
			Assert::IsTrue(testList.at(0) == 0);
			Assert::IsTrue(testList.at(1) == 1);
			Assert::IsTrue(testList.at(2) == 2);
			Assert::IsTrue(testList.at(3) == 3);
			Assert::IsTrue(testList.at(4) == 4);
			Assert::IsTrue(testList.at(5) == 5);
		}
		TEST_METHOD(pop_frontTest) {
			UnorderedList testList(5);
			testList.push_front(4);
			testList.push_front(3);
			testList.push_front(2);
			testList.push_front(1);
			testList.push_front(0);
			Assert::IsTrue(testList.at(0) == 0);
			testList.pop_front();
			Assert::IsTrue(testList.at(0) == 1);
			testList.pop_front();
			Assert::IsTrue(testList.at(0) == 2);
			testList.pop_front();
			Assert::IsTrue(testList.at(0) == 3);
			testList.pop_front();
			Assert::IsTrue(testList.at(0) == 4);
			testList.pop_front();
			Assert::IsTrue(testList.at(0) == 5);
			testList.pop_front();
			Assert::IsTrue(testList.get_size() == 0);
		}
		TEST_METHOD(pop_backTest) {
			UnorderedList testList(0);
			testList.push_back(1);
			testList.push_back(2);
			testList.push_back(3);
			testList.push_back(4);
			testList.push_back(5);
			Assert::IsTrue(testList.get_size() == 6);
			testList.pop_back();
			Assert::IsTrue(testList.get_size() == 5);
			testList.pop_back();
			Assert::IsTrue(testList.get_size() == 4);
			testList.pop_back();
			Assert::IsTrue(testList.get_size() == 3);
			testList.pop_back();
			Assert::IsTrue(testList.get_size() == 2);
			Assert::IsTrue(testList.at(0) == 0);
			Assert::IsTrue(testList.at(1) == 1);
			testList.pop_back();
			Assert::IsTrue(testList.get_size() == 1);
			Assert::IsTrue(testList.at(0) == 0);
			testList.pop_back();
			Assert::IsTrue(testList.get_size() == 0);
		}
		TEST_METHOD(insertTest) {
			UnorderedList testList(5);
			Assert::IsTrue(testList.get_size() == 1);

			testList.insert(0, 10);
			Assert::IsTrue(testList.get_size() == 2);
			Assert::IsTrue(testList.at(0) == 10);
			Assert::IsTrue(testList.at(1) == 5);
			testList.insert(1, 20);
			Assert::IsTrue(testList.get_size() == 3);
			Assert::IsTrue(testList.at(0) == 10);
			Assert::IsTrue(testList.at(1) == 20);
			Assert::IsTrue(testList.at(2) == 5);
		}
		TEST_METHOD(setTest) {
			UnorderedList testList(5);
			testList.push_back(6);
			Assert::IsTrue(testList.get_size() == 2);
			testList.set(0, 10);
			Assert::IsTrue(testList.get_size() == 2);
			Assert::IsTrue(testList.at(0) == 10);
			Assert::IsTrue(testList.at(1) == 6);
			testList.set(1, 20);
			Assert::IsTrue(testList.get_size() == 2);
			Assert::IsTrue(testList.at(0) == 10);
			Assert::IsTrue(testList.at(1) == 20);
		}
		TEST_METHOD(removeTest) {
			UnorderedList testList(5);
			testList.push_front(4);
			Assert::IsTrue(testList.get_size() == 2);
			testList.remove(1);
			Assert::IsTrue(testList.get_size() == 1);
			Assert::IsTrue(testList.at(0) == 4);
		}
		TEST_METHOD(isEmptyTest) {
			UnorderedList list1(5);
			Assert::IsTrue(!list1.isEmpty());
			list1.pop_front();
			Assert::IsTrue(list1.isEmpty());

			UnorderedList list2;
			Assert::IsTrue(list2.isEmpty());
		}
		TEST_METHOD(contains) {
			UnorderedList testList1(1);
			testList1.push_back(2);
			testList1.push_back(3);
			testList1.push_back(4);
			testList1.push_back(5);
			testList1.push_back(6);

			UnorderedList testList2(3);
			testList2.push_back(4);
			testList2.push_back(5);
			Assert::IsTrue(testList1.contains(testList2));

			testList2.clear();
			Assert::IsTrue(testList1.contains(testList2));

			testList2.push_back(46);
			testList2.push_back(5);
			testList2.push_back(6);
			Assert::IsFalse(testList1.contains(testList2));
		}
	};
}
