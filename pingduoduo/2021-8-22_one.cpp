#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    vector<int> res;
    while (T--){
        int N;
        cin >> N;
        vector<pair<int,int>> info;
        int max_day = 0;
        for (int i=0;i<N;i++){
            int s,t;
            cin >> s >> t;
            max_day = max(max_day,t);
            info.push_back({s,t});
        }

        sort(info.begin(),info.end(),[](auto a,auto b){
            if (a.first > b.first)
                return true;
            else if (a.first == b.first)
                return a.second<b.second;
            else 
                return false;
            
        });

        vector<int> vec(max_day+1,0);
        for (int i=0;i<info.size();i++){
            int day = info[i].second;
            int min_val = INT_MAX;
            int min_index = -1;
            for(int j=day;j>=1;j--){
                if (vec[j]==0){
                    vec[j] = info[i].first;
                    min_index = -2;
                    break;
                }
                else{
                    if (vec[j]<info[i].first){
                        if (vec[j]<min_val){
                            min_val = vec[j];
                            min_index = j;
                        }
                    }
                    
                }
            }
            if (min_index==-2 || min_index==-1)
                continue;
            else{
                vec[min_index] = info[i].first;
            }
        }
        int temp = 0;
        for (int i=0;i<vec.size();i++)
            temp+= vec[i];
        res.push_back(temp);
    }
    
    for (int i=0;i<res.size();i++)
        cout << res[i] << endl;

    system("pause");
    return 0;
}