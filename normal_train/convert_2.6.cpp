#include <iostream>
int stonetolb(int);

int main()
{
    using namespace std;
    cout <<"Please tell me your weight(in stone):";
    int weight_stone;
    cin >> weight_stone;
    int pounds=stonetolb(weight_stone);
    cout <<"So,your weight in pounds is:" << pounds << endl;
    cin.get();
    cin.get();
    return 0;
}

int stonetolb(int n)
{
    int m=n*14;
    return m;
}