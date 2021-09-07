#include <iostream>

using namespace std;

void display_time(int,int);

int main()
{
    int hour,minute;
    cout << "Please enter the number of hours:";
    cin >> hour;
    cout << "Please enter the number of minutes:";
    cin >> minute;
    display_time(hour,minute);
    cin.get();
    cin.get();
    return 0;
}

void display_time(int hour,int minute)
{
    cout << hour << ":" << minute << endl;
}