#include <iostream>
#include <iomanip>

using namespace std;

#include "phone_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void output(phone_subscription* subscription) {
    cout << "Number...............";
    cout << subscription->number << '\n'; 
    cout << "Date.................";
    cout << setw(2) << setfill('0') << subscription->startDate.day << '.'; 
    cout << setw(2) << setfill('0') << subscription->startDate.month << '.'; 
    cout << setw(4) << setfill('0') << subscription->startDate.year << '\n'; 
    cout << "Time.................";
    cout << setw(2) << setfill('0') << subscription->startTime.hour << ':';
    cout << setw(2) << setfill('0') << subscription->startTime.minute << ':'; 
    cout << setw(2) << setfill('0') << subscription->startTime.second << '\n'; 
    cout << "Duration.............";
    cout << setw(2) << setfill('0') << subscription->duration.hour << ':'; 
    cout << setw(2) << setfill('0') << subscription->duration.minute << ':'; 
    cout << setw(2) << setfill('0') << subscription->duration.second << '\n';
    cout << "Tariff...............";
    cout << subscription->callInfo.name << '\n';
    cout << "Cost for a minute....";
    cout << subscription->callInfo.cost << '\n';
    cout << '\n';
}

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
            output(subscriptions[i]);
        }
        bool (*check_function)(phone_subscription*) = NULL; // check_function -    ,    bool,
        //        book_subscription*
        cout << "\nVariants of checking:\n";
        cout << "1)Check by traffic 'mobile'\n";
        cout << "2)Check by month '11'\n";
        cout << "\nEnter your variant: ";
        int item;
        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:
            check_function = check_phone_subscription_by_traffic;
            cout << "***** Mobile traffic *****\n\n";
            break;
        case 2:
            check_function = check_phone_subscription_by_date;
            cout << "***** November month *****\n\n";
            break;
        default:
            throw "Invalid variant";
        }
        if (check_function)
        {
            int new_size;
            phone_subscription** filtered = filter(subscriptions, size, check_function, new_size);
            for (int i = 0; i < new_size; i++)
            {
                output(filtered[i]);
            }
            delete[] filtered;
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
