#include <iostream>
#include <string>
using namespace std;

// Using Separate Arrays for Names and Days
/*
int main() {
    const char* monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int totalDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    cout << "List of Months and Corresponding Days (Separate Arrays):\n";
    for (int index = 0; index < 12; ++index) {
        cout << monthNames[index] << ": " << totalDays[index] << " days\n";
    }

    return 0;
}
*/

// Using an Array of Structures
struct MonthInfo {
    const char* monthName;
    int dayCount;
};

int main() {
    MonthInfo calendar[] = {
        {"January", 31}, {"February", 28}, {"March", 31}, {"April", 30},
        {"May", 31}, {"June", 30}, {"July", 31}, {"August", 31},
        {"September", 30}, {"October", 31}, {"November", 30}, {"December", 31}
    };

    cout << "Months and their days (using array of structures):\n";
    for (int index = 0; index < 12; ++index) {
        cout << calendar[index].monthName << ": " << calendar[index].dayCount << " days\n";
    }

    return 0;
}
