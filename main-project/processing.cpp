#include <stdio.h>
#include <stdlib.h>

#include "processing.h"
#include "phone_subscription.h"

int phone_duration(phone_subscription* element) {
    return (element->duration.hour * 1200 + element->duration.minute * 60 + element->duration.second);
}

bool compare_conversation_by_duration(phone_subscription* a, phone_subscription* b) {
    return phone_duration(a) > phone_duration(b);
}

int phone_number(phone_subscription* element) {
    return element->number;
}

bool compare_conversation_by_number(phone_subscription* a, phone_subscription* b) {
    return phone_number(a) < phone_number(b);
}

void swap(phone_subscription* array[], int i, int j) {
    phone_subscription* temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void heapify(phone_subscription* array[], int size, int index, bool (*compare)(phone_subscription*, phone_subscription*)) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;


    if (left < size && compare(array[left], array[largest]) == false)
        largest = left;

    if (right < size&& compare(array[right], array[largest]) == false)
        largest = right;

    if (largest != index) {
        swap(array, index, largest);
        heapify(array, size, largest, compare);
    }
}

void heap_sort(phone_subscription** array, int size, bool (*compare)(phone_subscription*, phone_subscription*)) {
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(array, size, i, compare);

    for (int i = size - 1; i > 0; --i) {
        swap(array, 0, i);

        heapify(array, i, 0, compare);
    }
}

void quickSort(phone_subscription** numbers, int left, int right, bool (*compare)(phone_subscription*, phone_subscription*))
{
    phone_subscription* pivot; // ����������� �������
    int index; // ������ ������������ ��������
    int l_hold = left; //����� �������
    int r_hold = right; // ������ �������
    pivot = numbers[left]; // �������� �������� ������������ ��������
    while (left < right) // ���� ������� �� ���������
    {
        while ((*compare)(numbers[right], pivot) && (left < right))
            right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
        if (left != right) // ���� ������� �� ����������
        {
            numbers[left] = numbers[right]; // ���������� ��������� �� ������� [right] �� ����� ������������
            left++; // �������� ����� ������� ������
        }
        while ((*compare)(numbers[left], pivot) < 0 && (left < right))
            left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
        if (left != right) // ���� ������� �� ����������
        {
            numbers[right] = numbers[left]; // ���������� ��������� �� ������� [left] �� ����� [right]
            right--; // �������� ������ ������� �����
        }
    }
    numbers[left] = pivot; // ������ ��������� �� ����������� ������� �� �����
    index = left;
    left = l_hold;
    right = r_hold;
    if (left < index) // ���������� �������� ���������� ��� ����� � ������ ����� �������
        quickSort(numbers, left, index - 1, compare);
    if (right > index)
        quickSort(numbers, index + 1, right, compare);
}
