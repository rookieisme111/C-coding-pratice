#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m,n,time;

    cin >> m;   //机器数量
    cin >> n;   //任务数量
    vector<int> needTime(m,0);
    vector<int> pro(m,0);
    for (int i=0; i<m; i++){
        cin >>needTime[i];
    }

    int min;
    int min_pos;

    for(int i=0; i<n; i++){
        min=pro[0]+needTime[0];
        min_pos=0;
        for (int j=1;j<m;j++){
            if(pro[j]+needTime[j]<min){
                min=pro[j]+needTime[j];
                min_pos=j;
            }
        }
        pro[min_pos]+=needTime[min_pos];
        time=pro[min_pos];

    }

    cout << time;
    system("pause");
    return 0;
}