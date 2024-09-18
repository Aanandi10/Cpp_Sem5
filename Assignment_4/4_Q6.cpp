#include<iostream>
#include <string>
using namespace std;

//Using Separate Arrays for Names and Days

/*int main() {
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    cout << "Months and their days (using separate arrays):\n";
    for (int i = 0; i < 12; ++i) {
        cout << months[i] << ": " << days[i] << " days\n";
    }

    return 0;
}*/

//Using an Array of Structures:

struct Month {
    const char* name;
    int days;
};

int main(){
    Month months[] = {
        {"January", 31}, {"February", 28}, {"March", 31}, {"April", 30},
        {"May", 31}, {"June", 30}, {"July", 31}, {"August", 31},
        {"September", 30}, {"October", 31}, {"November", 30}, {"December", 31}
    };

    cout << "Months and their days (using array of structures):\n";
    for (int i = 0; i < 12; ++i) {
        cout << months[i].name << ": " << months[i].days << " days\n";
    }

    return 0;
}