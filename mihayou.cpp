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
    int T;
    cin >> T;
    vector<int> res;

    while(T-->0){
        string s;
        cin >> s;
        int temp = 0;
        stack<char> record;
        for (int i=0;i<s.size();i++){
            if (s[i]=='[' || s[i]=='{'){
                record.push(s[i]);
            }
            else{
                char top_char = record.top();
                record.pop();
                if ((s[i]==']'&& top_char=='[') || (s[i]=='}' && top_char=='{'))
                    continue;
                temp++;
            }
        }
        res.push_back(temp);
    }

    for (int i=0;i<res.size();i++)
        cout << res[i] << endl ;

    return 0;
}