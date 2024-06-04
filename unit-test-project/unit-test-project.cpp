#include "pch.h"
#include "CppUnitTest.h"

#include "../main-project/phone_subscription.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	phone_subscription* build_subscription(int hour, int minute, int second, double cost)
	{
		phone_subscription* subscription = new phone_subscription;
		subscription->duration.hour = hour;
		subscription->duration.minute = minute;
		subscription->duration.second = second;
		subscription->callInfo.cost = cost;
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
			subscriptions[0] = build_subscription(1, 1, 1, 0.6); // 5 
			subscriptions[1] = build_subscription(1, 1, 1, 0.8); // 7 
			subscriptions[2] = build_subscription(1, 1, 1, 0.7); // 4 
			Assert::AreEqual(0.7, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod2) //        
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 1, 1, 0.6); // 5 
			subscriptions[1] = build_subscription(1, 1, 1, 0.8); // 7 
			subscriptions[2] = build_subscription(1, 1, 1, 0.7); // 4 
			Assert::AreEqual(0.7, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod3) //         
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 1, 1, 0.6); // 5 
			subscriptions[1] = build_subscription(1, 1, 1, 0.8); // 7 
			subscriptions[2] = build_subscription(1, 1, 1, 0.7); // 4 
			Assert::AreEqual(0.7, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod4) //         
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 1, 1, 0.6); // 5 
			subscriptions[1] = build_subscription(1, 1, 1, 0.8); // 7 
			subscriptions[2] = build_subscription(1, 1, 1, 0.7); // 4 
			Assert::AreEqual(0.7, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod5) //          (2)
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 1, 1, 0.6); // 5 
			subscriptions[1] = build_subscription(1, 1, 1, 0.8); // 7 
			subscriptions[2] = build_subscription(1, 1, 1, 0.7); // 4 
			Assert::AreEqual(0.7, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod6) //          (2)
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 1, 1, 0.6); // 5 
			subscriptions[1] = build_subscription(1, 1, 1, 0.8); // 7 
			subscriptions[2] = build_subscription(1, 1, 1, 0.7); // 4 
			Assert::AreEqual(0.7, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod7) //     
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 1, 1, 0.6); // 5 
			subscriptions[1] = build_subscription(1, 1, 1, 0.8); // 7 
			subscriptions[2] = build_subscription(1, 1, 1, 0.7); // 4 
			Assert::AreEqual(0.7, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod8) //    ,     
		{
			phone_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 1, 1, 0.6); // 5 
			subscriptions[1] = build_subscription(1, 1, 1, 0.8); // 7 
			subscriptions[2] = build_subscription(1, 1, 1, 0.7); // 4 
			Assert::AreEqual(0.7, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}
	};
}
