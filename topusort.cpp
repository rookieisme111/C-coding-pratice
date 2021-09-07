#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ENode{
    int vertx;
    ENode* next;
};

struct VNode{
    int in_degree;
    ENode* first;
};

int main(){
    int T;
    cin >> T;
    while(T-->0){
        int n,m;
        cin >> n >> m;

        VNode Graph[n];
        for (int i=0;i<n;i++){
            Graph[i].in_degree = 0;
            Graph[i].first = nullptr;
        }

        while (m-->0){
            vector<int> data;
            int temp;
            int num;
            cin >> num;
            for (int i=0;i<num;i++){
                cin >> temp;
                data.push_back(temp);
            }
            
            for (int i=0;i<data.size()-1;i++){
                int v1 = data[i]-1, v2 = data[i+1]-1;
                ENode* cur = Graph[v1].first;
                if (cur == nullptr){
                    ENode* node = new ENode;
                    node->next = nullptr;
                    node->vertx = v2;
                    Graph[v1].first = node;
                }
                else{
                    while (cur->next!=nullptr && cur->vertx!=v2){
                        cur = cur->next;
                    }

                    if (cur->next == nullptr && cur->vertx!=v2){
                        ENode* node = new ENode;
                        node->next = nullptr;
                        node->vertx = v2;
                        cur->next = node;
                    }
                }
            }
        }
        //计算所有顶点的入度
        for(int i=0;i<n;i++){
            ENode* cur = Graph[i].first;
            while(cur!=nullptr){
                Graph[cur->vertx].in_degree++;
                cur = cur->next;
            }
        }

        //把所有入度为0的顶点入队列
        queue<int> que;
        for (int i=0;i<n;i++)
            if (Graph[i].in_degree==0)
                que.push(i);
        
        if (que.size()>=2){
            cout << "No" <<endl;
            system("pause");
            break;
        }

        vector<int> res;
        while(!que.empty()){
            int rm_vertex = que.front();
            que.pop();
            res.push_back(rm_vertex);

            ENode* rm_cur = Graph[rm_vertex].first;
            while(rm_cur!=nullptr){
                Graph[rm_cur->vertx].in_degree--;
                if (Graph[rm_cur->vertx].in_degree==0)
                    que.push(rm_cur->vertx);
                rm_cur = rm_cur->next;
            }

            if (que.size()>=2)
                break;
            

        }
        if (res.size()==n){
            for (int j=0;j<n;j++)
                cout << res.at(j)+1 << ' ';
            cout << endl;
            system("pause");
        }
        else{
            cout << "No" <<endl;
            system("pause");
        }
            
    }
}