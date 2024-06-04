#include "pch.h"
#include "CppUnitTest.h"

#include "../main-project/phone_subscription.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	phone_subscription* build_subscription(int start_day, int start_month, int start_year)
	{
		phone_subscription* subscription = new phone_subscription;
		subscription->startDate.day = start_day;
		subscription->startDate.month = start_month;
		subscription->startDate.year = start_year;
		return subscription;
	}

	//       
	void delete_subscription(phone_subscription* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}


	TEST_CLASS(unittestproject)
	{
	public:
		TEST_METHOD(TestMethod1) //     
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 1, 2015); // 5 
			subscriptions[1] = build_subscription(2, 1, 2015); // 7 
			subscriptions[2] = build_subscription(3, 1, 2015); // 4 
			Assert::AreEqual(7, process(subscriptions, 7));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod2) //        
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(20, 1, 2015); // 15 
			subscriptions[1] = build_subscription(22, 1, 2015); // 19 
			subscriptions[2] = build_subscription(19, 1, 2015); // 14 
			Assert::AreEqual(19, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod3) //         
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(01, 10, 2021); // 11 
			subscriptions[1] = build_subscription(01, 10, 2021); // 11 
			subscriptions[2] = build_subscription(06, 10, 2021); // 10 
			Assert::AreEqual(11, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod4) //         
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(25, 1, 2016); // 11 
			subscriptions[1] = build_subscription(25, 2, 2016); // 12 
			subscriptions[2] = build_subscription(25, 4, 2016); // 10 
			Assert::AreEqual(12, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod5) //          (2)
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(25, 1, 1900); // 11 
			subscriptions[1] = build_subscription(25, 2, 1900); // 11 
			subscriptions[2] = build_subscription(25, 4, 1900); // 10 
			Assert::AreEqual(11, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod6) //          (2)
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(25, 1, 2000); // 11 
			subscriptions[1] = build_subscription(25, 2, 2000); // 12 
			subscriptions[2] = build_subscription(25, 4, 2000); // 10 
			Assert::AreEqual(12, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod7) //     
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(25, 12, 2014); // 11 
			subscriptions[1] = build_subscription(25, 12, 2014); // 45 
			subscriptions[2] = build_subscription(25, 12, 2014); // 70 
			Assert::AreEqual(70, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod8) //    ,     
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(25, 12, 2015); // 11 
			subscriptions[1] = build_subscription(25, 12, 2015); // 45 
			subscriptions[2] = build_subscription(25, 12, 2015); // 71 
			Assert::AreEqual(71, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}
	};
}
