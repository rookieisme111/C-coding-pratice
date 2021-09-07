#include <iostream>
#include <vector>

using namespace std;

int main (){
    int T;
    cin >> T;
    vector<int> res;
    while (T--){
        int P,Q;
        cin >> P >> Q;

        int count = 0;
        if (P == Q){
            res.push_back(count);
            continue;
        }
        if (P<Q){
            while (P < Q){
                P = 2*P;
                count ++;
                if (P >= Q)
                    break;
            }
            int n=0,m=0;
            if ((P-Q)%2==0)
                n = (P-Q)/2;
            else{
                n = (P-Q-1)/2;
                n ++;
            }
            m = Q-(P/2);
            count += min(m,n);
            res.push_back(count);
            continue;
        }
        else if(P>Q){
            int n=0,m=0;
            if ((P-Q)%2==0)
                n = (P-Q)/2;
            else{
                n = (P-Q-1)/2;
                n ++;
            }
            count += n;
            res.push_back(count);
            continue;
        }
    }

    for(int i=0;i<res.size();i++)
        cout << res[i] << endl;
    system("pause");
    return 0;

}