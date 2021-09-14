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
    int M, N;
    cin >> M >> N;

    vector<vector<int>> matrix(M,vector<int>(N,0));
    vector<vector<bool>> visited(M,vector<bool>(N,false));
    for (int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin >> matrix[i][j];

    int a,b;
    cin >> a >> b;

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    int index = 0;
    int count = 1;
    vector<int> res;
    res.push_back(matrix[0][0]);
    visited[0][0] = true;
    int x=0,y=0;
    while(count<M*N){
        int row = x + dx[index];
        int col = y + dy[index];
        if (row>=0 && row<M && col>=0 && col<N && visited[row][col]==false){
            count++;
            visited[row][col]=true;
            res.push_back(matrix[row][col]);
            x = row;
            y = col;
        }
        else{
            index = (index+1)%4;
        }
    }

    for (int i=0;i<res.size();i++){
        if (i==res.size()-1){
            cout << res[i];
            continue;
        }
        cout << res[i] <<",";
    }


    return 0;
}