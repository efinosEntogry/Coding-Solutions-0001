#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool validation(int day, int month, int year );
void calculateTheNextDay(int & day, int & month, int & year);

int main() {

    int day, year, month;

    do {

        cout << "Please enter the day: "; cin >> day;
        cout << "Please enter the month: "; cin >> month;
        cout << "Please enter the year: "; cin >> year;

        if (!validation(day, month, year)) {
            cout << "Invalid input" << endl;
        }

    }while (!validation(day, month, year));

    calculateTheNextDay(day, month, year);

    cout << endl << day << "/" << month << "/" << year << endl;

    return 0;
}

bool validation(int day, int month, int year) {
    int daysInMonths[] = { 31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > daysInMonths[month - 1] || month > 12 || month < 1) {
        return false;
    }else {
        return true;
    }
}

void calculateTheNextDay(int & day, int & month, int & year) {
    int daysInMonths[] = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day == daysInMonths[month - 1]) {
        if (month == 12) {
            month = 1;
            year++;
        }else {
            month++;
        }
        day = 1;
    }else {
        day++;
    }
}
