#include <iostream>

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
    phone_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << subscriptions[i]->number << '\n';
            cout << subscriptions[i]->startDate << '\n';
            cout << subscriptions[i]->startTime << '\n';
            cout << subscriptions[i]->duration << ' ';
            cout << subscriptions[i]->callInfo.name << ' ';
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
