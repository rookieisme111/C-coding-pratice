#include <iostream>

#ifndef MYTIME_H_
#define MYTIME_H_

class Time
{
private:
    int hours;
    int minutes;

public:
    Time();
    Time(int h ,int m=0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h=0,int m=0);
    Time operator+(const Time & t)const;
    friend Time operator*(double m, const Time & t);
    void Show()const;
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
    ~Time(){}
};
#endif

Time::Time()
{
    hours=minutes=0;
}

Time::Time(int h,int m)
{
    hours=h;
    minutes=m;
}

void Time::AddMin(int m)
{
    if (m+minutes>=60)
    {
        hours++;
        minutes=(m+minutes)%60;
    }
    else
        minutes=m+minutes;
}

void Time::AddHr(int h)
{
    if (h+hours>=24)
        hours=(h+hours)%24;
    else
        hours=h+hours;
}

void Time::Reset(int h,int m)
{
    hours=h;
    minutes=m;
}

Time Time::operator+(const Time & t)const
{
    int sum_minutes=t.minutes+minutes;
    int sum_hours=t.hours+hours;
    Time res(( sum_hours+sum_minutes/60)%24 , sum_minutes%60);
    return res;
}

void Time::Show()const
{
    std::cout << hours << " : " << minutes << std::endl ;
}

Time operator*(double m, const Time & t)
{
    Time result;
    long totalminutes=t.hours*m*60+t.minutes*m;
    result.hours=totalminutes/60;
    result.minutes=totalminutes%60;
    return result;
}

std::ostream & operator<<(std::ostream & os ,const Time & t)
{
    os << t.hours << " : " << t.minutes << std::endl;
    return os;
}


int main()
{
    using namespace std;
    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time total;

    total=3.6*coding;
    cout << total;

    cin.get();
    return 0;

}