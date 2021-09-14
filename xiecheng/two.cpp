#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

bool func(int target,vector<int>& values,int k){
    int line = 1;
    int max_val = 0, min_val = INT32_MAX;
    for(int i = 0;i < values.size(); i++){
        min_val = min(min_val,values[i]);
        max_val = max(max_val,values[i]);
        if(max_val - min_val < target)
            continue;
        else{
            line++;
            if(line>k)
                return false;
            min_val = INT32_MAX;
            max_val = 0;
            i--;
        }
    }
    return true;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> values(n,0);
    for (int i=0;i<n;i++)
        cin >> values[i];
    
    int low = 0, high = 0;
    for (int i=0;i<n;i++)
        high = max(high,values[i]);

    while(low < high){
        int mid = low + (high - low)/2;
        if (func(mid,values,k))
            high = mid;
        else
            low = mid + 1;
    }
    cout << low-1;


    return 0;
}