#include <iostream>
void simon(int);

int main()
{
    using namespace std;
    simon(3);
    cout << "Pick an integer:";
    int x;
    cin >>x;
    simon(x);
    cout <<"Done!" << endl;
    cin.get();
    cin.get();
    return 0;
}

void simon(int n)
{
    using namespace std;
    cout <<"Simon says touch your eyes " << n <<" times." << endl;
}