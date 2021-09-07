#include <iostream>
#include <vector>
using namespace std;

struct _true_type{};
struct _false_type{};

template<class T>
struct _type_traits{
    typedef _false_type _is_POD_type;
};

template<>
struct _type_traits<int>{
    typedef _true_type _is_POD_type;
};

template<>
struct _type_traits<double>{
    typedef _true_type _is_POD_type;
};

template<class T>
void func (T var1){
    _func(var1, typename _type_traits<T>::_is_POD_type());
};

template<class T>
void _func (T var1,_true_type){
    cout << "T is POD type" << endl;
};

template<class T>
void _func (T var1,_false_type){
    cout << "T is not POD type" << endl;
};


int main(){
    int a ;
    double b;
    func(a);
    func(b);
    system("pause");
    return 0;
}
