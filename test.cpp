#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int timeFail(vector<int>& tree,int failid,vector<int>& costs){
    int len1 = tree.size(), len2 = costs.size();
    int start = -1;
    for (int i=0;i<len1;i++)
        if (tree[i]==failid){
            start = i;
            break;
        }

    if (start==-1)
        return 0;

    queue<int> que;
    int time = 0;
    que.push(0);
    bool flag = false;
    while (!que.empty()){
        int k = que.size();
        int once_time = INT32_MAX;
        for(int i=0;i<k;i++){
            int index = que.front();
            if (index == start)
                flag = true;
            que.pop();
            int left_child = index*2+1, right_child = left_child+1;
            if (left_child<len1 && tree[left_child]!= -1){
                que.push(left_child);
                once_time = min(once_time,costs[tree[index]]);
            }
            if (right_child<len1 && tree[right_child]!= -1){
                que.push(right_child);
                once_time = min(once_time,costs[tree[index]]);
            }
        }
        if (INT32_MAX == once_time)
            once_time = 0;
        if (flag == true)
            time += once_time;
    }
    return time;
}

int main(){
    vector<int> tree = {0,1,2,3,4,5,6,7,-1,-1,-1,8};
    vector<int> costs = {1,3,2,4,5,6,7,8,9};

    int res = timeFail(tree,6,costs);
    cout << res;
    system("pause");
    return 0;
}