#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int special_num(vector<int>& a, int t){
    //动态规划，记录非奇特区间的数量，再用总区间数减去非奇特区间数

    //dp[i]表示以a[i]为右区间的非奇特区间的数量
    vector<int> dp(a.size(),0);
    int len = a.size();

    for (int i=1;i<a.size();i++){
        int temp = -1;
        for (int j=i-1;j>=0;j--){
            if ((a[i]^a[j]) == t){
                temp = j+1;
                break;
            }
        }
        dp[i] = max(dp[i-1],temp);
    }

    //计算非奇特区间的数量
    // int not_special = accumulate(dp.begin(),dp.end(),0);
    int not_special = 0;
    for (int i=0;i<len;i++)
        not_special += dp[i];
    int sum = len*(len-1)/2;
    return sum-not_special;
}

int main(){
    vector<int> nums = {2,4,8};
    int t = 6;
    cout << special_num(nums,t) << endl;
    system("pause");
    return 0;
}

