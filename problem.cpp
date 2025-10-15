#include <iostream>
#include <vector>

using namespace std;

bool isLeapYear(int year);
bool validation(int day, int month, int year);
string calculateTheNextDay(int day, int month, int year, int nextDay, int nextMonth, int nextYear);

int main() {

    int day, year, month, nextDay, nextMonth, nextYear;

    do {

        cout << "Please enter the day: "; cin >> day;
        cout << "Please enter the month: "; cin >> month;
        cout << "Please enter the year: "; cin >> year;

    }while (!validation(day, month, year));

    cout << calculateTheNextDay(day, month, year, nextDay, nextMonth, nextYear) << endl;

    return 0;
}

bool isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}

bool validation(int day, int month, int year) {
    vector<int> days = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> months = {1,2,3,4,5,6,7,8,9,10,11,12};

    if (day < 1 || day > days[month - 1] || month < 1 || month > months.size() + 1 ) {
        cout << "You passed through an invalid input, please try again!" << endl;
        return false;
    }else {
        return true;
    }
}

string calculateTheNextDay(int day, int month, int year, int nextDay, int nextMonth, int nextYear) {
    vector<int> days = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> months = {1,2,3,4,5,6,7,8,9,10,11,12};

    if (day == days[month - 1]) {
        nextDay = 1;
        nextMonth = months[month];
        nextYear = year;
        if (month == months.size() + 1) {
            nextMonth = months[0];
            nextYear = year + 1;
        }
    }else {
        nextDay = day + 1;
        nextMonth = month;
        nextYear = year;
    }

    return to_string(nextDay) + " / " + to_string(nextMonth) + " / " + to_string(nextYear);

}
