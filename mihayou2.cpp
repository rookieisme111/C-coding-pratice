#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int T;
    cin >> T;
    vector<int> res;
    while(T--){
        int num;
        cin >> num;
        if (num < 9){
            res.push_back(-1);
            continue;
        }
        int k = (num-9)/3;
        int ans = (1+k+1)*(k+1)/2;
        res.push_back(ans);
    }

    for (int i=0;i<res.size();i++){
        cout << res[i] << endl;
    }


    return 0;
}