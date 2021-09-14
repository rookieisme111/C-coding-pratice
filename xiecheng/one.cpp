#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

void printPath(vector<string>& dir){
    if (dir.size()==0){
        cout << "\\" << endl;
    }
    else{
        for (int i=0;i<dir.size();i++)
            cout << "\\" << dir[i];
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> dir;
    while (n-->0){
        string op, subdir;
        cin >> op;
        if (op == "pwd"){
            printPath(dir);
            continue;
        }
        if (op == "cd"){
            cin >> subdir;
            if (subdir == ".."){
                if (dir.size()==0)
                    continue;
                dir.pop_back();
            }
            else{
                dir.push_back(subdir);
            }
        }
    }


    return 0;
}