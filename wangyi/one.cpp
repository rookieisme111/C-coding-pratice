#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> nums;
    int temp;
    while(1){
        cin >> temp;
        nums.push_back(temp);
        if (cin.get() == '\n')
            break;
    }

    int M;
    cin >> M;

    int res = 0;
    for (int i = 0;i<nums.size()-1;i++){
        int target = M - nums[i];
        for (int j=i+1;j<nums.size();j++){
            if (nums[j]<=target)
                res++;
        }
    }
    cout << res;
    system("pause");
    return 0;

}