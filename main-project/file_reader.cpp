#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

date convertDate(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

Time convertTime(char* str)
{
    Time result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hour = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.minute = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.second = atoi(str_number);
    return result;
}

void read(const char* file_name, phone_subscription* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_NAME_SIZE];
        while (!file.eof())
        {
            phone_subscription* item = new phone_subscription;
            file.getline(item->number, MAX_NUMBER_SIZE);
            file >> tmp_buffer;
            item->startDate = convertDate(tmp_buffer);
            file >> tmp_buffer;
            item->startTime = convertTime(tmp_buffer);
            file >> tmp_buffer;
            item->duration = convertTime(tmp_buffer);
            file.getline(item->callInfo.name, MAX_NAME_SIZE);
            file >> item->callInfo.cost;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}