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
			UnorderedList list;
			Assert::IsTrue(list.get_size() == 0);
			list.push_back(0);
			Assert::IsTrue(list.get_size() == 1);
			for (int i = 0; i < 100; i++)
				list.push_back(0);

			Assert::IsTrue(list.get_size() == 101);


			for (int i = 0; i < 100; i++)
				list.pop_back();
			Assert::IsTrue(list.get_size() == 1);
		}

		TEST_METHOD(atTest) {
			UnorderedList list(5);
			list.push_front(4);
			list.push_front(3);
			list.push_front(2);
			list.push_front(1);
			list.push_front(0);
			Assert::IsTrue(list.at(0) == 0);
			Assert::IsTrue(list.at(1) == 1);
			Assert::IsTrue(list.at(2) == 2);
			Assert::IsTrue(list.at(3) == 3);
			Assert::IsTrue(list.at(4) == 4);
			Assert::IsTrue(list.at(5) == 5);
		}

		TEST_METHOD(push_backTest) {
			UnorderedList list(0);
			list.push_back(1);
			Assert::IsTrue(list.get_size() == 2);
			list.push_back(2);
			Assert::IsTrue(list.get_size() == 3);
			list.push_back(3);
			Assert::IsTrue(list.get_size() == 4);
			list.push_back(4);
			Assert::IsTrue(list.get_size() == 5);
			list.push_back(5);
			Assert::IsTrue(list.get_size() == 6);
			Assert::IsTrue(list.at(0) == 0);
			Assert::IsTrue(list.at(1) == 1);
			Assert::IsTrue(list.at(2) == 2);
			Assert::IsTrue(list.at(3) == 3);
			Assert::IsTrue(list.at(4) == 4);
			Assert::IsTrue(list.at(5) == 5);

		}
		TEST_METHOD(push_frontTest) {
			UnorderedList list(5);
			list.push_front(4);
			Assert::IsTrue(list.get_size() == 2);
			list.push_front(3);
			Assert::IsTrue(list.get_size() == 3);
			list.push_front(2);
			Assert::IsTrue(list.get_size() == 4);
			list.push_front(1);
			Assert::IsTrue(list.get_size() == 5);
			list.push_front(0);
			Assert::IsTrue(list.get_size() == 6);
			Assert::IsTrue(list.at(0) == 0);
			Assert::IsTrue(list.at(1) == 1);
			Assert::IsTrue(list.at(2) == 2);
			Assert::IsTrue(list.at(3) == 3);
			Assert::IsTrue(list.at(4) == 4);
			Assert::IsTrue(list.at(5) == 5);
		}
		TEST_METHOD(pop_frontTest) {
			UnorderedList list(5);
			list.push_front(4);
			list.push_front(3);
			list.push_front(2);
			list.push_front(1);
			list.push_front(0);
			Assert::IsTrue(list.at(0) == 0);
			list.pop_front();
			Assert::IsTrue(list.at(0) == 1);
			list.pop_front();
			Assert::IsTrue(list.at(0) == 2);
			list.pop_front();
			Assert::IsTrue(list.at(0) == 3);
			list.pop_front();
			Assert::IsTrue(list.at(0) == 4);
			list.pop_front();
			Assert::IsTrue(list.at(0) == 5);
			list.pop_front();
			Assert::IsTrue(list.get_size() == 0);
		}
		TEST_METHOD(pop_backTest) {
			UnorderedList list(0);
			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);
			list.push_back(5);
			Assert::IsTrue(list.get_size() == 6);
			list.pop_back();
			Assert::IsTrue(list.get_size() == 5);
			list.pop_back();
			Assert::IsTrue(list.get_size() == 4);
			list.pop_back();
			Assert::IsTrue(list.get_size() == 3);
			list.pop_back();
			Assert::IsTrue(list.get_size() == 2);
			Assert::IsTrue(list.at(0) == 0);
			Assert::IsTrue(list.at(1) == 1);
			list.pop_back();
			Assert::IsTrue(list.get_size() == 1);
			Assert::IsTrue(list.at(0) == 0);
			list.pop_back();
			Assert::IsTrue(list.get_size() == 0);
		}
		TEST_METHOD(insertTest) {
			UnorderedList list(5);
			Assert::IsTrue(list.get_size() == 1);

			list.insert(0, 10);
			Assert::IsTrue(list.get_size() == 2);
			Assert::IsTrue(list.at(0) == 10);
			Assert::IsTrue(list.at(1) == 5);
			list.insert(1, 20);
			Assert::IsTrue(list.get_size() == 3);
			Assert::IsTrue(list.at(0) == 10);
			Assert::IsTrue(list.at(1) == 20);
			Assert::IsTrue(list.at(2) == 5);
		}
		TEST_METHOD(setTest) {
			UnorderedList list(5);
			list.push_back(6);
			Assert::IsTrue(list.get_size() == 2);
			list.set(0, 10);
			Assert::IsTrue(list.get_size() == 2);
			Assert::IsTrue(list.at(0) == 10);
			Assert::IsTrue(list.at(1) == 6);
			list.set(1, 20);
			Assert::IsTrue(list.get_size() == 2);
			Assert::IsTrue(list.at(0) == 10);
			Assert::IsTrue(list.at(1) == 20);
		}
		TEST_METHOD(removeTest) {
			UnorderedList list(5);
			list.push_front(4);
			Assert::IsTrue(list.get_size() == 2);
			list.remove(1);
			Assert::IsTrue(list.get_size() == 1);
			Assert::IsTrue(list.at(0) == 4);
		}
		TEST_METHOD(isEmptyTest) {
			UnorderedList list1(5);
			Assert::IsTrue(!list1.isEmpty());
			list1.pop_front();
			Assert::IsTrue(list1.isEmpty());

			UnorderedList list2;
			Assert::IsTrue(list2.isEmpty());
		}
	};
}
