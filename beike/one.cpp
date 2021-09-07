#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;
    vector<int> samples(T,0);
    for (int i=0;i<T;i++){
        cin >> samples[i];
    }
    vector<int> res;
    for (int i=0;i<T;i++){
        if (samples[i]%2==0)
            res.push_back(samples[i]/2);
        else
            res.push_back((samples[i]+1)/2);
    }

    for (int i=0;i<T;i++)
        cout << res[i] << endl;

    system("pause");
    return 0;
}