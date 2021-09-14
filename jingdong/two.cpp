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
    int n,q;
    cin >> n >> q;
    int graph[n+1][n+1] = {0};
    for (int i=1;i<=n;i++){
        int num ;
        cin >> num;
        if (num==0)
            continue;
        for (int j=0;j<num;j++){
            int v;
            cin >> v;
            graph[i][v] = 1;
            graph[v][i] = 2;
        }
    }

    vector<bool> open(n+1,false);

    long open_num = 0;
    for (int i=0;i<q;i++){
        int op, k;
        cin >> op >> k;
        if (op == 1){
            if (open[k]==true){
                cout << open_num;
                continue;
            }
            else{
                open[k] = true;
                open_num++;
                for (int j=1;j<=n;j++){
                    if (k == j)
                        continue;
                    if (graph[k][j]==1 && open[j]==false){
                        open_num++;
                        open[j] = true;
                    }
                }
            }
        }
        else if(op == 0){
            if (open[k]==false){
                cout << open_num;
                continue;
            }
            else{
                open[k] = false;
                open_num--;
                for(int j=1;j<=n;j++){
                    if (k == j)
                        continue;
                    if (graph[k][j]==2 && open[j]==true){
                        open_num--;
                        open[j] = false;
                    }
                }
            }
        }
        cout << open_num;
    }
    return 0;
}