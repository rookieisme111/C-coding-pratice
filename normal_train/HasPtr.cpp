#include <string>
#include <iostream>

using namespace std;
class HasPtr{
public:
    HasPtr(const string& s=string()):ps(new string(s)),i(0){}
    HasPtr(const HasPtr& tmp);
    HasPtr& operator=(const HasPtr& tmp);
    ~HasPtr();

    void show(){cout << i<< *ps <<endl; cout<< ps<<endl;}
private:
    string* ps;
    int i;
};

HasPtr::HasPtr(const HasPtr& tmp):i(tmp.i),ps(new string(*(tmp.ps))){}

HasPtr& HasPtr::operator=(const HasPtr& tmp){
    /*
    i=tmp.i;
    delete ps;      //非常重要
    ps=new string(*(tmp.ps));
    return *this;
    */
   newp=new string(*tmp.ps);
   delete ps;
   ps=newp;
   i=tmp.i;
   return *this;
}

HasPtr::~HasPtr(){
    delete ps;
}

int main(){
    HasPtr x("aaabb");
    x.show();

    HasPtr y=x;
    HasPtr z;
    z=x;
    y.show();
    z.show();
    system("pause");
    return 0;
}