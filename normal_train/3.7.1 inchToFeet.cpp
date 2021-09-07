#include <iostream>

int main()
{
    using namespace std;
    const int CHANGE=12;
    float height;
    cout << "Please enter your height in inches:________\b\b\b\b\b\b\b\b";
    cin >> height;
    cout << "Your height in feet: " << height/CHANGE << endl;
    cin.get();
    cin.get();
    return 0;
}