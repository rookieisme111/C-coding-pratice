#include<vector>
#include<iostream> 
#include<stack>
using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> st;
        int i = 0, j = 0;
        while (i < pushV.size()) {
            if (pushV[i] != popV[i]) {
                st.push(pushV[i + 1]);
            }
            else {
                ++i;
                ++j;
                while (!st.empty() && st.top() == popV[j]) {
                    st.pop();
                    ++j;
                }
            }
        }
        return st.empty();
    }
    

    void main() {
        vector<int> pushA = { 1, 2, 3, 4, 5 };
        vector<int> popA = { 4, 3, 5, 1, 2 };
        bool flag = IsPopOrder(pushA, popA);
        cout << "flag = " << flag << endl;
        // system("pause");
        // return 0;
    }
};

int main(){
    system("pause");
    return 0;
}