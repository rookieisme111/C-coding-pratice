#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

int func(int a,int b,int k){
    if (a-b > -k)
        return a-b;
    else
        return -k;
}

int main(){
    int n,k;
    cin >> n >> k;
    // // vector<int> A;
    // // vector<int> B;
    // //map1值表示该系列在本歌单中前一首听过的编号
    // map<int,int> map1;
    // //dirty表示该系列的歌曲是否已经被污染
    // map<int,bool> dirty;
    // int res = 0;
    // for (int i=0;i<n;i++){
    //     int a, b, c, d;
    //     cin >> a >> b >> c >> d;
    //     if (dirty.count(c)!=0){
    //         if (dirty[c]==true)
    //             res += func(a,b,k);
    //         else{
    //             if ((map1[c]+1)==d){
    //                 res += a;
    //                 map1[c]++;
    //             }
    //             else{
    //                 res += func(a,b,k);
    //                 dirty[c] = true;
    //             }
    //         }
    //     }
    //     else{
    //         dirty[c] = false;
    //         map1[c] = 0;
    //         if ((map1[c]+1)==d){
    //             res += a;
    //             map1[c]++;
    //         }
    //         else{
    //             res += func(a,b,k);
    //             dirty[c] = true;
    //         }
    //     }
    // }
    // cout << res;
    int data[n][4] = {};
    for (int i=0;i<n;i++){
        cin >> data[i][0] >> data[i][1] >> data[i][2] >> data[i][3];
    }
    vector<int> dp(n,0);
    dp[0] = max(0-k,data[0][3]==1 ? data[0][0] : data[0][0]-data[0][1]);
    for (int i=0;i<n;i++){
        if ()
    }


    return 0;
}