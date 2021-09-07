#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> circles(N,vector<int>(3,0));
    for (int i=0;i<N;i++)
        cin >> circles[i][0] >> circles[i][1] >> circles[i][2];
    
    vector<int> res;
    for (int i=0;i<N;i++){
        int num = 0;
        int x = circles[i][0], y = circles[i][1], r = circles[i][2];
        //先判断与x轴的交点数
        if (abs(y)<r)
            num += 2;
        else if (abs(y)==r)
            num += 1;
        
        if (abs(x)<r)
            num += 2;
        else if (abs(x)==r)
            num += 1;

        //如果过零点，则num减1
        if ((x*x+y*y)==r*r)
            num -= 1;

        res.push_back(num);
    }
    for (int i=0;i<res.size();i++)
        cout << res[i] << endl;

    system("pause");
    return 0;
}