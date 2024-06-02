#ifndef FILTER_H
#define FILTER_H

#include "phone_subscription.h"

phone_subscription** filter(phone_subscription* array[], int size, bool (*check)(phone_subscription* element), int& result_size);

bool check_phone_subscription_by_traffic(phone_subscription* element);

bool check_phone_subscription_by_date(phone_subscription* element);

#endif