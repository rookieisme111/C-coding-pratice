#include <iostream>
#include <vector>

using namespace std;
static int directions[4][2] = {{1,2},{1,-2},{2,1},{2,-1}};
static vector<vector<pair<int,int>>> res;

void backtracking(int x,int y,int target_x,int target_y,vector<pair<int,int>>& path){
    if (x==target_x && y==target_y)
        res.push_back(path);

    for (int i=0;i<4;i++){
        int col = x + directions[i][0];
        int row = y + directions[i][1];
        if (col>=0 && col<=target_x && row>=0 && row<=target_y){
            path.push_back({col,row});
            backtracking(col,row,target_x,target_y,path);
            path.pop_back();
        }
    }
}

int main(){
    int X,Y;
    cin >> X >> Y;


    vector<pair<int,int>> path;
    path.push_back({0,0});
    backtracking(0,0,X,Y,path);

    for (int i=0;i<res.size();i++){
        for (int j=0;j<res[i].size();j++){
            if (j<res[i].size()-1)
                cout << "(" << res[i][j].first << ',' << res[i][j].second << ")" << "->";
            else    
                cout << "(" << res[i][j].first << ',' << res[i][j].second << ")" ;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}