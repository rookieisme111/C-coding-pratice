#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n ;
    cin >> n;
    vector<int> aNums(n),bNums(n);
    for (int i=0;i<n;i++)
        cin >> aNums[i];
    for (int i=0;i<n;i++)
        cin >> bNums[i];

    sort(aNums.begin(),aNums.end(),[](int x,int y){ return x>y;});
    sort(bNums.begin(),bNums.end(),[](int x,int y){ return x>y;});

    vector<int> record(n,0);
    int count = 0;
    int index = 0;
    for (int i=0;i<n;i++){
        while(index<n && aNums[i]<=bNums[index]){
            index ++;
            count ++;
        }
        record[i] = count;
    }
    int res = 1;
    for (int j=0;j<n;j++){
        res = res*(record[j]-j);
    }

    cout << res;
    system("pause");
    return 0;
}