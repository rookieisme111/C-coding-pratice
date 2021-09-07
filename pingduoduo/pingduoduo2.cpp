#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,t,c;
    cin >> n >> t >> c;
    
    vector<int> candies(n);
    for (int i=0;i<n;i++)
        cin >> candies[i];

    int count = 0,res=0;
    for (int i=0;i<n;i++){
        if (candies[i]<=t){
            count ++;
            if (count>=c)
                res++;
        }
        else{
            count = 0;
        }
    }

    cout << res <<endl;
    system("pause");
    return 0;
}