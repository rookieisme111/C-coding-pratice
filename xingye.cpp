#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
    
    string num;
    cin >> num;
    int len = num.size();

    reverse(num.begin(),num.end());
    string res(2*len-1,'0');
    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            int index = i+j;
            int temp = (num[i]-'0')*(num[j]-'0');
            temp += res[index]-'0';
            do{
                int yushu = temp%10;
                temp = temp/10;
                res[index] = char('0'+yushu);
                index++;
                temp += res[index]-'0';
            }while(temp>=10);
            res[index] = char('0'+temp);
        }
    }
    reverse(res.begin(),res.end());
    cout << res;
    return 0;
}
