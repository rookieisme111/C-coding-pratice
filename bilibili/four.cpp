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
    int n;
    cin >> n;

    vector<int> hang(500001,0);
    vector<int> lie(500001,0);

    for (int k=0;k<n;k++){
        pair<int,int> temp;
        cin >> temp.first >> temp.second;
        hang[temp.first]++;
        lie[temp.second]++;
    }

    int max_val = INT32_MIN;
    for (int i=0;i<500001;i++){
        max_val = max(hang[i],max_val);
        max_val = max(lie[i],max_val);
    }

    cout << max_val << endl;

    return 0;
}