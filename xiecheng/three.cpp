#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

int bagProblems(int V,vector<int>& weights, vector<int>& values){
    vector<int> dp(V+1,0);
    int goods_num = weights.size();
    for (int i=0;i<goods_num;i++){
        for(int j=weights[i];j<=V;j++)
            dp[j] = max(dp[j],dp[j-weights[i]]+values[i]);
    }
    return dp[V];
}

int main(){
    int n,m;
    cin >> n >> m;
    string sequence;
    cin >> sequence;
    vector<int> weights;
    vector<int> values;
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        weights.push_back(a);
        values.push_back(b);
    }

    vector<int> valid;
    int count = 0;
    for (int i=0;i<n;i++){
        if (sequence[i]=='1'){
            count++;
        }
        else{
            if (count == 0)
                continue;
            else{
                valid.push_back(count);
                count = 0;
            }
        }
    }
    if (count!=0)
        valid.push_back(count);

    int res = 0;
    for (int i=0; i<valid.size(); i++){
        res += bagProblems(valid[i],weights,values);
    }
    cout << res;


    return 0;
}