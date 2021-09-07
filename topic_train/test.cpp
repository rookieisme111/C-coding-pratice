#include <iostream>
#include <vector>
using namespace std;

int main (){
    int N;
    cin >> N;

    int n1 = N/3, n2 = N%3;
    
    int res = 0 ;
    if (n2==0)
        res = 3*(n1*(n1+1)/2);

    else
        res = n2*3*(n1*(n1+1)/2);
    
    cout << res;

    system("pause");
    return 0;
}