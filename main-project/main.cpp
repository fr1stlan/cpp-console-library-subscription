#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Call {
public:
    string number;
    string date;
    string time;
    string duration;
    string tariff;
    double cost;

    Call(const string& number, const string& date, const string& time, const string& duration, const string& tariff, double cost)
        : number(number), date(date), time(time), duration(duration), tariff(tariff), cost(cost) {}
};

bool isMobileNumber(const Call& call) {
    return call.tariff == "мобильный";
}

bool isNovember2021(const Call& call) {
    return call.date.substr(3, 2) == "11" && call.date.substr(6, 2) == "21";
}

bool compareByDurationDescending(const Call& a, const Call& b) {
    return a.duration > b.duration;
}

bool compareByNumberCostAscending(const Call& a, const Call& b) {
    if (a.number != b.number) {
        return a.number < b.number;
    }
    return a.cost < b.cost;
}

void printCalls(const vector<Call>& calls) {
    for (const auto& call : calls) {
        cout << call.number << " " << call.date << " " << call.time << " " << call.duration << " " << call.tariff << " " << call.cost << endl;
    }
}

int main() {
    vector<Call> calls;
    calls.emplace_back("123456789", "15.11.21", "10:30:00", "00:15:30", "мобильный", 0.5);
    calls.emplace_back("987654321", "25.11.21", "12:00:00", "00:05:45", "город", 0.3);
    calls.emplace_back("543216789", "05.10.21", "14:45:00", "00:10:15", "межгород", 0.7);
    calls.emplace_back("987654321", "15.11.21", "11:00:00", "00:20:00", "мобильный", 0.6);

    vector<Call> mobileCalls;
    copy_if(calls.begin(), calls.end(), back_inserter(mobileCalls), isMobileNumber);

    vector<Call> november2021Calls;
    copy_if(calls.begin(), calls.end(), back_inserter(november2021Calls), isNovember2021);

    sort(calls.begin(), calls.end(), compareByDurationDescending);
    sort(mobileCalls.begin(), mobileCalls.end(), compareByDurationDescending);
    sort(november2021Calls.begin(), november2021Calls.end(), compareByNumberCostAscending);

    cout << "All calls:\n";
    printCalls(calls);

    cout << "Mobile calls:\n";
    printCalls(mobileCalls);

    cout << "Calls in November 2021:\n";
    printCalls(november2021Calls);

    return 0;
}