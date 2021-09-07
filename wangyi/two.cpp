#include <iostream>
#include <vector>

using nameapce std;

char findKthBit(int n, int k) {
    // write code here
    if (n==1)
        return (char)('a'+n-1);

    int left = 0;
    int right = pow(2,n)-2;
    bool flag = false;
    k = k-1;
    for (int i=n;i>=1;i--){
        int mid = (left+right)/2;

        if (k==mid){
            if (flag == false)
                return (char)('a'+i-1);
            else    
                return (char)('a'+26-i);
        }

        else if (k<mid){
            right = mid-1;
            continue;
        }

        else if(k>mid){
            right = mid-1;
            k = (mid-1)-(k-(mid+1));
            flag = flag ? false:true;
        }
    }
    return 'a';
}