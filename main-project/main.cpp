#include <iostream>
#include <iomanip>

using namespace std;

#include "phone_subscription.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "");
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #9. Phone conversations\n";
    cout << "Author: Stanislav Sotnikov\n";
    cout << "Group: 23AI1d\n";
    phone_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** Phone call *****\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Number...............";
            cout << subscriptions[i]->number << '\n';
            cout << "Date.................";
            cout << setw(2) << setfill('0') << subscriptions[i]->startDate.day << '.';
            cout << setw(2) << setfill('0') << subscriptions[i]->startDate.month << '.';
            cout << setw(4) << setfill('0') << subscriptions[i]->startDate.year << '\n';
            cout << "Time.................";
            cout << setw(2) << setfill('0') << subscriptions[i]->startTime.hour << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->startTime.minute << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->startTime.second << '\n';
            cout << "Duration.............";
            cout << setw(2) << setfill('0') << subscriptions[i]->duration.hour << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->duration.minute << ':';
            cout << setw(2) << setfill('0') << subscriptions[i]->duration.second << '\n';
            cout << "Tariff...............";
            cout << subscriptions[i]->callInfo.name << '\n';
            cout << "Cost for a minute....";
            cout << subscriptions[i]->callInfo.cost << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
