#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

int main(){
    /***********************
    string s1="Hello World!";
    string s2="Hello World!";
    char s3[13]="Hello World!";
    cout << s1.compare(s3) << endl;
    cout << s1.compare(6,6,s3+6,6);
    system("pause");
    ***********************/

    stack<int, vector<int>> istack;

    for (size_t i=0;i<10;i++){
        istack.push(i);
    }
    size_t val;
    while(!istack.empty()){
        val=istack.top();
        cout << val << endl;

        istack.pop();
    }


    queue<int> ique;
    priority_queue<int> pri_ique;
    for (size_t i=0;i<10;i++){
        pri_ique.push(i);
    }   
    while(!pri_ique.empty()){
        val=pri_ique.top();
        cout << val << endl;

        pri_ique.pop();
    }     
    system("pause");
    return 0;
}