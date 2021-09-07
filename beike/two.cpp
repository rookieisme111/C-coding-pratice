#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    vector<int> res;
    while (T-->0){
        int n;
        cin >> n;
        string str;
        cin >> str;

        //count表示扫描到目前为止左括号的数量
        int count = 0;
        int op_num = 0;
        for(int i=0;i<str.size();i++){
            if (str[i]=='(')
                count ++;
            if (str[i] == ')'){
                if (count>0)
                    count --;
                else
                    op_num ++;
            }
        }

        res.push_back(op_num);
    }

    for (int i=0;i<res.size();i++)
        cout << res[i] << endl;

    system("pause");
    return 0;
}