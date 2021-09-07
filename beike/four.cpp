#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int max_num = 0;

void backtracking(vector<pair<int,int>>& record,int cur,vector<int>& res){
    if (cur==record.size()){
        int sum = 0;
        for (int i=1;i<res.size();i++)
            sum += res[i]*res[i];
        max_num = max(sum,max_num);
        return;
    }

    int l = record[cur].first, r = record[cur].second;
    for (int i=l;i<=r;i++){
        res[i] += 1;
        backtracking(record,cur+1,res);
        res[i] -= 1;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int temp,l,r;
    vector<pair<int,int>> record;
    vector<int> res(m+1,0);
    for (int i=0;i<n;i++){
        cin >> temp;
        for (int j=0;j<temp;j++){
            cin >> l >> r;
            record.push_back({l,r});
        }
    }
    backtracking(record,0,res);
    cout << max_num;
    system("pause");
    return 0;
}