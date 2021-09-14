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
    int n,m,x,y,z;
    cin >> n >> m >> x >> y >> z;
    map<char,pair<int,int>> map1;
    for (int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            char temp;
            cin >> temp;
            map1[temp] = {i,j};
        }
    
    string str;
    cin >> str;

    long cost = 0;
    pair<int,int> position{0,0};

    for (int i=0;i<str.size();i++){
        pair<int,int> next_position = map1[str[i]];

        long temp = z;
        if (position.first!=next_position.first && position.second!=next_position.second)
            temp += y;
        temp += x*(abs(position.first-next_position.first)+abs(position.second-next_position.second));
        
        cost += temp;
        position = next_position;

        
    }
    cout << cost;


    return 0;
}