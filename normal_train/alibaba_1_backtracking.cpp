#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void backtracking (vector<string> & ans,string & s,int level ,int m );
bool isAnswer(string s);

int main(){
    int m,n;
    
    cin >> m;
    cin >> n;
    
    string s;
    char ch;
    for(int i=0; i<n ; i++){
        cin >> ch;
        s+=ch;
    }
    sort (s.begin(),s.end(),[](char ch1,char ch2){return ch1<ch2;});
    
    cout << s <<endl;
    vector<string> ans;
    backtracking(ans,s,0,m);

    for (int k=0;k<ans.size();k++)
        cout << ans[k] <<endl;

    system("pause");
    
    
    
}

void backtracking (vector<string> & ans,string & s,int level ,int m ){
    if (level==m){
        string tmp=s.substr(0,m);
        if (isAnswer(tmp))
            ans.push_back(tmp);
        return;
    }
    for (int i=level; i<s.size();i++){
        swap(s[i],s[level]);
        backtracking(ans,s,level+1,m);
        swap(s[i],s[level]);
    }
}
bool isAnswer(string s){
    //判断是否满足字典序，且包含一个数字和两个字符
    string tmp;
    tmp=s;
    sort (s.begin(),s.end(),[](char ch1,char ch2){return ch1<ch2;});
    if (tmp!=s)    
        return false;
    int i=0,j=0;
    for (int k=0;k<s.size();k++){
        if (s[k]>='0' && s[k]<='9')
            i++;
        if (s[k]>='a' && s[k]<'z')
            j++;
    }
    if (i>=1 && j>=2)
        return true;
    else 
        return false; 
}