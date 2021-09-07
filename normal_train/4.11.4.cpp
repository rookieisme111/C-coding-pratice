#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string firstname,lastname,fullname;

    cout << "Enter your first name: ";
    cin >>firstname;
    cout << "Enter your last name: ";
    cin >>lastname;
    fullname=lastname+", "+firstname;
    cout << "your name: " << fullname;
    cin.get();
    cin.get();
    return 0;


}