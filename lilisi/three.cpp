#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    vector<pair<int,string>> MsgQueue;
    map<int,vector<int>> map1;
    
    vector<string> ans;
    int n;
    cin >> n;
    while (n-->0){
        string op;
        cin >> op;
        if (op=="out"){
            int type;
            cin >> type;
            if (MsgQueue.empty()){
                ans.push_back(to_string(-1));
            }
            else{
                if (type == 0){
                    int type_id = MsgQueue[0].first;
                    string res = MsgQueue[0].second;
                    ans.push_back(res);
                    MsgQueue.erase(MsgQueue.begin());
                    map1[type_id].erase(map1[type_id].begin());
                }
                else{
                    if(map1.count(type)==0 || map1[type].empty())
                        ans.push_back(to_string(-1));
                    else{
                        int index = map1[type].front();
                        ans.push_back(MsgQueue[index].second);
                        map1[type].erase(map1[type].begin());
                        MsgQueue.erase(MsgQueue.begin()+index);
                    }
                }
            }
        }
        else if(op == "in"){
            int type;
            string input;
            cin >> type >> input;
            MsgQueue.push_back({type,input});
            if (map1.count(type)!=0){
                map1[type].push_back(MsgQueue.size()-1);
            }
            else{
                map1[type] = vector<int>();
                map1[type].push_back(MsgQueue.size()-1);
            }
        }
    }
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << endl;
    system("pause");
    return 0;
}