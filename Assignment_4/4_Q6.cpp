#include <iostream>
#include <iomanip>  // For formatting output
using namespace std;

struct Month 
{
    const char* name;
    int days;
};

int main()
{
    // First method: using arrays for month names and days
    const char* monthNames[] = { "January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December" };
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Formatting table headers
    cout << "Month Table using Array of Month Names and Days" << endl;
    cout << left << setw(15) << "Month" << setw(10) << "Days" << endl;
    cout << "---------------------------------" << endl;

    // Loop through the arrays and print month names with days
    for (int i = 0; i < 12; i++)
        {
           cout << left << setw(15) << monthNames[i] << setw(10) << monthDays[i] << endl;
         }

    // Spacer line for aesthetic purposes
    cout << "\n";

    // Second method: using an array of structures
    Month months[] = { {"January", 31}, {"February", 28}, {"March", 31}, {"April", 30},{"May", 31}, {"June", 30}, {"July", 31}, {"August", 31},
        {"September", 30}, {"October", 31}, {"November", 30}, {"December", 31}};

    // Formatting table headers for the structure-based method
    cout << "Month Table using Array of Structure of Months" << endl;
    cout << left << setw(15) << "Month" << setw(10) << "Days" << endl;
    cout << "---------------------------------" << endl;

    // Loop through the array of structures and print the data
    for (int i = 0; i < 12; i++)
    {
        cout << left << setw(15) << months[i].name << setw(10) << months[i].days << endl;
    }

    return 0;
}
