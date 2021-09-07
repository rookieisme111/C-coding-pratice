#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> a = {1,2,3,4,5};
    vector<int> prefix(a.size()+1,0);
    prefix[0] = 0;
    for (int i=1;i<=a.size();i++){
        prefix[i] = prefix[i-1]+a[i-1];
    }

    for (int i=0;i<prefix.size();i++)
        cout << prefix[i] << endl;

    system("pause");
    return 0;
}