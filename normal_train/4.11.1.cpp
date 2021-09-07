#include <iostream>

int main()
{
    using namespace std;
    char firstName[10];
    char lastName[10];
    char desireGrade;
    int age;

    cout << "What is your first name? ";
    cin.getline(firstName,10);
    cout << "What is your last name? ";
    cin >> lastName;
    cout << "What letter grade do you deserve? ";
    cin >> desireGrade;
    cout << "What is your age? ";
    cin >> age;
    cout << "Name: " << lastName << "," << firstName << endl;
    cout << "Grade: " << char(desireGrade+1) << endl;
    cout << "Age: " << age << endl;
    
    cin.get();
    cin.get();
    return 0;
}