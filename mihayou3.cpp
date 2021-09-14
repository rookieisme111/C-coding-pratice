#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <set>
#include <deque>
using namespace std;

int main(){
    int R1,C1,R2,C2;
    cin >> R1 >> C1;
    cin >> R2 >> C2;

    set<pair<int,int>> set1;
    int dx[8] = {-3,-3,-2,2,3,3,2,-2};
    int dy[8] = {-2,2,3,3,-2,2,-3,-3};

    queue<pair<int,int>> que;
    que.push({R1,C1});
    set1.insert({R1,C1});
    
    int level = 0;
    int res = -1;
    bool flag = false;
    while(!que.empty()){
        int len = que.size();
        level++;
        for (int i=0;i<len;i++){
            auto position = que.front();
            que.pop();
            for (int j=0;j<8;j++){
                int x = position.first + dx[j];
                int y = position.second + dy[j];
                if (x>=0 && x<=9 && y>=0 && y<=8 && set1.count({x,y})==0){
                    if (x==R2 && y==C2){
                        flag = true;
                        res = level;
                        break;
                    }
                    else{
                        set1.insert({x,y});
                        que.push({x,y});
                    }
                }
            }
            if (flag == true)
                break;
        }

        if (flag == true)
            break;
    }

    cout << res;


    return 0;
}