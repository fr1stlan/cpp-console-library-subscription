#ifndef PHONE_SUBSCRIPTION_H
#define PHONE_SUBSCRIPTION_H

#include "constants.h"

struct date
{
    int day;
    int month;
    int year;
};

struct Time
{
    int hour;
    int minute;
    int second;
};

struct traffic
{
    char name[MAX_NAME_SIZE];
    int cost;
};

struct phone_subscription
{
    char number[MAX_NUMBER_SIZE];
    date startDate;
    Time startTime;
    Time duration;
    traffic callInfo;
};

#endif