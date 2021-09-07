#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    vector<int> ages;
    int age;
    while (cin.peek()!='\n'){
        cin >> age;
        ages.push_back(age);
    }

    int size = ages.size();
    if (size < 2)
        return size;

    vector<int> num(size,1);
    for (int i =1;i<size;i++){
        if (ages[i]>ages[i-1]){
            num[i] = num[i-1]+1;
        }
    }
    for (int i=size-1;i>0;i--){
        if (ages[i] < ages[i-1]){
            num[i-1] = max(num[i-1],num[i]+1);
        }
    }
    cout << accumulate(num.begin(),num.end(),0);
    system("pause");
    return 0;
}