#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> record(n+1,0);
    set<pair<int,int>> set1;
    for (int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        if (u==v)
            continue;
        if (set1.count({u,v})==0){
            set1.insert({u,v});
            set1.insert({v,u});
            record[u]++;
            record[v]++;
        }
    }

    for (int j=0;j<q;j++){
        int x,y;
        cin >> x >> y;
        if (x==y)
            continue;
        else{
            swap(record[x],record[y]);
        }
    }

    for (int i=1;i<=n;i++){
        if (i==n){
            cout << record[i];
            break;
        }
        cout << record[i] << ' ';
        
    }


    return 0;
}