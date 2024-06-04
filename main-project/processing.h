#ifndef PROCESSING_H
#define PROCESSING_H

#include "phone_subscription.h"

int phone_duration(phone_subscription* subscription);

bool compare_conversation_by_duration(phone_subscription* a, phone_subscription* b);

int phone_number(phone_subscription* subscription);

bool compare_conversation_by_number(phone_subscription* a, phone_subscription* b);

void swap(phone_subscription* array[], int i, int j);

void heapify(phone_subscription* array[], int size, int index, bool (*compare)(phone_subscription*, phone_subscription*));

void heap_sort(phone_subscription* array[], int size, bool (*compare)(phone_subscription*, phone_subscription*));

void quickSort(phone_subscription* numbers[], int left, int right, bool (*compare)(phone_subscription*, phone_subscription*));

double process(phone_subscription* array[], int size);

#endif