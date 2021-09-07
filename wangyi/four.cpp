#include <queue>
#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> d{-1,0,1,0,-1};

unordered_map<int,int> m;

int minSailCost (vector<vector<int>> & input){
    m[0] = 2;
    m[1] = 1;
    if (input.size()==0)    
        return -1;
    
    int row = input.size();
    int col = input[0].size();
    if (input[row-1][col-1]==2)
        return -1;
    
    vector<vector<int>> dp(row,vector<int>(col,0));
    for(int i=1;i<row;i++){
        if(input[i][0]==2)
            break;

        int cost =m[input[i][0]];
        dp[i][0] = dp[i-1][0] + cost;
    }

    for(int i=1;i<col;i++){
        if (input[0][i]==2)
            break;
        dp[0][i] = dp[0][i-1] +m[input[0][i]];
    }

    for (int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            int up = dp[i-1][j];
            int left = dp[i][j-1];
            if (input[i][j]==2 ||(up==0 && left==0)){
                dp[i][j] = 0;
                continue;
            }
            int cost = m[input[i][j]];

            if(up==0)
                dp[i][j] = left+cost;
            else if(left==0)
                dp[i][j] = up+cost;
            else
                dp[i][j] = min(up,left)+cost;
        }
    }

    if (dp[row-1][col-1]==0)
        return -1;
    return dp[row-1][col-1];
}