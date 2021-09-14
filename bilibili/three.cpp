#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

int func(vector<vector<int>>& monsters){
    int len = monsters.size();
    if (len<=2)
        return len;

    map<double,int> map1;
    int num = INT32_MIN;
    int count = 0;
    for (int i=0;i<len-1;i++){
        map.clear();
        
    }
}


int main(){
    int n;
    cin >> n;
    vector<vector<int>> monsters(n,vector<int>(2,0));

    for (int i=0;i<n;i++)
        cin >> monsters[i][0] >> monsters[i][1];

    int res = func(monsters);
    cout << res;


    return 0;
}