#include <iostream>

int main()
{
    using namespace std;
    const int DAYTOHOURS=24;
    const int HOURSTOMINUTES=60;
    const int MINUTESTOSECONDS=60;
    long int seconds;
    int daysOfTime,hoursOfTime,minutesOfTime,secondsOfTime;
    cout << "Enter the number of seconds:";
    cin >> seconds;
    secondsOfTime=seconds%MINUTESTOSECONDS;
    int minutes=seconds/MINUTESTOSECONDS;
    minutesOfTime=minutes%HOURSTOMINUTES;
    int hours=minutes/HOURSTOMINUTES;
    hoursOfTime=hours%DAYTOHOURS;
    daysOfTime=hours/DAYTOHOURS;
    cout << seconds << " seconds= " << daysOfTime << " days, " << hoursOfTime << " hours, "
                    << minutesOfTime << " minutes, " << secondsOfTime << " seconds";
    cin.get();
    cin.get();
    return 0;
}