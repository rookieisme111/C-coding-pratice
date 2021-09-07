#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void dfs (vector<vector<int>>&g,int cur,int distance);
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> g (n*m,vector<int>(n*m,0));
    vector<vector<int>> visited (n*m,vector<int>(n*m,1));
    for (int i=0;i<k;i++){
        int x,y,u,v,w;
        cin >> x >> y >> u >> v >> w;
        g[(x-1)*m+y-1][(u-1)*m+v-1]=w;
    }
    int min_dist=INT32_MAX;
    dfs(g,0,0);
    cout << min_dis;
}

void dfs (vector<vector<int>>&g,int cur,int distance){
    
}