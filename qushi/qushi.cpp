#include <iostream>
#include <vector>
#include <string>

using namespace std;

int less1(vector<int> & nums,int start,int end);
int more1 (vector<int> & nums,int start,int end){
    if (nums.size()==0)
        return 0;
    if (end-start==0)
            return nums[start];
    return max(nums[start]+less1(nums,start+1,end),nums[end]+less1(nums,start,end-1));
}

int less1(vector<int> & nums,int start,int end){
    if (end==start) 
        return 0;
    return min(more1(nums,start+1,end),more1(nums,start,end-1));
}

int main(){
    string s;
    cin >> s;
    vector<int> nums;
    int start = 0;
    for (int i=0;i<s.size();i++){
        if (s[i]>='0' && s[i]<='9'){
            continue;
        }
        else{
            int len = i-start;
            nums.push_back(stoi(s.substr(start,len)));
            start = i+1;
        }
    }
    nums.push_back(stoi(s.substr(start,s.size()-start)));

    // for (int i=0;i<nums.size();i++)
    //     cout << nums[i] << endl;
    int res = more1(nums,0,nums.size()-1);
    cout << res;
    system("pause");

}