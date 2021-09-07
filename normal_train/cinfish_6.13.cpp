#include <iostream>

const int Max=5;

int main()
{
    using namespace std;
    double fish[Max];
    int i=0;
    cout << "fish #1: ";
    while(i<Max && cin >> fish[i]){
        if (++i<Max)
            cout << "fish #" << i+1 <<": ";
    }
    system("pause");
    return 0;
}