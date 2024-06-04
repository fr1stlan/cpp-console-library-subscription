#ifndef SORTS_H
#define SORTS_H

int phone_duration(phone_subscription* subscription);

bool compare_conversation_by_duration(phone_subscription* a, phone_subscription* b);

int phone_number(phone_subscription* subscription);

bool compare_conversation_by_number(phone_subscription* a, phone_subscription* b);

void heap_sort(phone_subscription** array, int size, bool (*compare)(phone_subscription*, phone_subscription*));

void quickSort(phone_subscription** numbers, int left, int right, bool (*compare)(phone_subscription*, phone_subscription*));

#endif