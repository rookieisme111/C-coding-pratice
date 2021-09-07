#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    int a1=0,b8=0,c0=0,d7=0;
    for (int i=0;i<str.size();i++){
        if(str[i]=='1'){
            a1++;
        }
        if(str[i]=='8'){
            b8=max(a1,b8)+1;
        }
        if(str[i]=='0'){
            c0=max(b8,c0)+1;
        }
        if(str[i]=='7'){
            d7=max(c0,d7)+1;
        }
    }
    cout <<d7;
    system("pause");
    return 0;

    

}