#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int MALS(vector<int>& members) {
    // write code here
    int len = members.size();
    if (len <= 1)
            return len;
    vector<int> dp(len,1);
    for (int i=1;i<len;i++){
        for (int j=0;j<i;j++){
            if (members[i]>(members[j]) && (dp[j]+1)>dp[i])
                dp[i] = dp[j]+1;
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main(){
    vector<int> members{20,40,41,41,21,22,43};
    // vector<int> members{};
    cout << MALS(members);
    system("pause");
    return 0;
}
