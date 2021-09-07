#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 9999999;
int main (){
    int n;
    cin >> n;
    int g[n+1][n+1];
    for (int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if (i==j)
                g[i][j] = 0;
            else    
                g[i][j] = INF;
        }
    for (int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++){
            cin >> g[i][j];
        }
    

    int dis[n+1];
    int visited[n+1];
    memset(visited,0,sizeof(visited));

    for (int i=1;i<=n;i++){
        dis[i] = g[1][i];
    }
    dis[1] = 0;
    visited[1] = 1;

    for(int i=2;i<=n;i++){
        int min_val = INF,u;
        for (int j=1;j<=n;j++){
            if(visited[j]==0 && dis[j] < min_val){
                u = j;  
                min_val = dis[j];              
            }
        }

        visited[u] = 1;

        for(int j=1;j<=n;j++){
            dis[j] = min(dis[u]+g[u][j],dis[j]);
        }

    }
    cout << dis[n];
    system("pause");
    return 0;
}