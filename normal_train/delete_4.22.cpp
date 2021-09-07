#include <iostream>
#include <cstring>

using namespace std;
char * getname(void);

int main()
{
    char * name;

    name=getname();
    cout << name << " at " << (int* )name << endl;
    delete [] name;

    cin.get();
    return 0;

}

char * getname(void)
{
    char temp[80];
    cout << "Enter last name:";
    cin >> temp;
    cin.get();
    char * pc=new char[strlen(temp)+1];
    strcpy(pc,temp);
    return pc;
}