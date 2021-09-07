#include <iostream>
#include <vector>


/*典型的动态规划题，一个货轮的载重为C，现有N个货物，每个货物的重量保存在一个数组中，每个货物对应的
价值保存在另一个数组中，求货轮所能装载货物的最大价值
*/
int main(){
    using namespace std;
    int C=0,n=0;
    cout << "enter overall weight:";
    cin >> C;
    cout << "enter number of goods:";
    cin >> n;

    vector<int> bagWeights(n,0);
    vector<int> bagValues(n,0);

    for (int i=0; i<n+1 ; i++)
        cin >> bagWeights[i];

    for (int i=0; i<n+1 ; i++)
        cin >> bagValues[i];

    vector<vector<int>> dp(n+1,vector<int>(C+1,0));

    for (int i=1; i<=n; i++)
        for (int j=C; j>=1; j--){
            if (j<bagWeights[i])
                dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-bagWeights[i]]+bagValues[i]);
            }
        }
    
    cout << dp[n][C];
    system("pause");
    return 0;
}