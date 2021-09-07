#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

typedef struct 
{
    int row;
    int col;
    char move;
}item;

unordered_map<char,pair<int,int>> directions;
directions['U']={-1,0};
directions['D']={1,0};
directions['L']={0,-1};
directions['r']={0,1};


int main(){
    int N,M;
    cin >> N >> M;
    vector<item> res;
    vector<vector<char>> table(N,vector<char>(M,' '));
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++){
            cin >> table[i][j];
        }

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cout << table[i][j];
        }
        cout <<endl;
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            
        }
    }





    system("pause");
    return 0;
}