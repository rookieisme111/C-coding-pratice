#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> res(n,0);

    int shang = m/(2*n-2);
    int yu = m%(2*n-2);

    vector<int> temp((2*n-2),shang);

    for (int i=0;i<yu;i++)
        temp[i]++;

    for (int j=0;j<n;j++)
        res[j] = temp[j];

    for (int j=n;j<(2*n)-2;j++)
        res[2*n-2-j] += temp[j];

    for (int i=0;i<n;i++)
        cout << res[i] << " ";

    // system("pause");
    return 0;
}