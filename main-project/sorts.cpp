#include <stdio.h>
#include <stdlib.h>

#include "sorts.h"

void siftDown(int* numbers, int root, int bottom)
{
    int maxChild; // ������ ������������� �������
    int done = 0; // ���� ����, ��� ���� ������������
    // ���� �� ����� �� ���������� ����
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)    // ���� �� � ��������� ����,
            maxChild = root * 2;    // ���������� ����� �������
        // ����� ���������� ������� ������� �� ����
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // ���� ������� ������� ������ ������������� �������
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; // ������ �� �������
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else // �����
            done = 1; // �������� ������������
    }
}
// ������� ���������� �� ����
void heapSort(int* numbers, int array_size)
{
    // ��������� ������ ��� ��������
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    // ���������� ����� �������� ��������� ��������
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}

void quickSort(int* numbers, int left, int right)
{
    int pivot; // ����������� �������
    int index; // ������ ������������ ��������
    int l_hold = left; //����� �������
    int r_hold = right; // ������ �������
    pivot = numbers[left];
    while (left < right) // ���� ������� �� ���������
    {
        while ((numbers[right] > pivot) && (left < right))
            right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
        if (left != right) // ���� ������� �� ����������
        {
            numbers[left] = numbers[right]; // ���������� ������� [right] �� ����� ������������
            left++; // �������� ����� ������� ������
        }
        while ((numbers[left] < pivot) && (left < right))
            left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
        if (left != right) // ���� ������� �� ����������
        {
            numbers[right] = numbers[left]; // ���������� ������� [left] �� ����� [right]
            right--; // �������� ������ ������� �����
        }
    }
    numbers[left] = pivot; // ������ ����������� ������� �� �����
    index = left;
    left = l_hold;
    right = r_hold;
    if (left < index) // ���������� �������� ���������� ��� ����� � ������ ����� �������
        quickSort(numbers, left, index - 1);
    if (right > index)
        quickSort(numbers, index + 1, right);
}
