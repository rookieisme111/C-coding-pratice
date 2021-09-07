#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    int n,k,m;
    cin >> n >> k >> m;
    vector<int> values(n,0);
    int bigger = 0;
    for (int i=0;i<n;i++){
        cin >> valuses[i];
        bigger = (values[i]>m)?(bigger+1):bigger;
    }
    // int sum = accumulate(values.begin(),values.end(),0);
    // cout << sum ;
    if (bigger<=1){
        int sum = accumulate(values.begin(),values.end(),0);
        cout << sum ;
        system("pause");
        return 0;
    }
    int l =0, end_of_small = n-1-bigger;
    int r = n-2;
    int sum = values[n-1];
    while (l<=r){
        if (l<=end_of_small){

        }
        else{
            if (r-l+1>=k){
                
            }
        }
    }
    cout << 0;


    system("pause");
    return 0;
}