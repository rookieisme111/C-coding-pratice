#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
    int n,w;
    cin >> n;

    vector <double> startTime(n,0);
    vector <double> lenth(n,0);
    vector <double> speed(n,0);

    for (int i=0; i<n; i++){
        cin >> startTime[i] >>lenth[i]>>speed[i];
    }

    cin >> w;

    vector <double> endTime(n,0);
    for (int i=0; i<n; i++){
        endTime[i]=(lenth[i]+w)/speed[i];
    }

    vector<pair<double,double>> Time(n);
    for (int i=0; i<n; i++){
        Time[i]={startTime[i],endTime[i]};
    }

    sort(Time.begin(),Time.end(),[](pair<double,double> a ,pair<double,double> b){ return a.second<b.second;});

    int max=0;
    for (int i=0;i<n;i++){
        double right=Time[i].second;
        int cnt=1;
        for (int j=i+1;j<n;j++)
            if(right>Time[j].second)
                cnt++;
        if (max<cnt)
            max=cnt;
    }

    cout << max;
    system("pause");
    return 0;

}