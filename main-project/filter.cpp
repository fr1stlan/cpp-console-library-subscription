#include "filter.h"
#include <cstring>
#include <iostream>

phone_subscription** filter(phone_subscription* array[], int size, bool (*check)(phone_subscription* element), int& result_size)
{
	phone_subscription** result = new phone_subscription * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_phone_subscription_by_traffic(phone_subscription* element)
{
	return strcmp(element->callInfo.name, "mobile") == 0;
}

bool check_phone_subscription_by_date(phone_subscription* element)
{
	return element->startDate.month == 11 && element->startDate.year == 2021;
}
