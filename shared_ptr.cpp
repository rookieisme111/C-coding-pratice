#include <iostream>

using namespace std;
//本来应该是一个模板类，为了简单实现，用一个Int型的变量作为共享指针的管理的资源
template<class T>
class shared_ptr{
private:
    T* _ptr;
    size_t * _count;

public:
    shared_ptr(T * ptr=nullptr ):_ptr(ptr){
        if (_ptr)
            _count = new size_t(1);
    }

    ~shared_ptr(){
        *_count--;
        if (*_count==0){
            delete _ptr;
            delete _count;
        }
    }

    shared_ptr(const shared_ptr& rhs){
        if (this != &rhs){
            this->_ptr = rhs._ptr;
            this->_count = rhs._count;
            (*this->_count)++;
        }
    }

    shared_ptr& operator=(const shared_ptr& rhs){
        if (this->_ptr == rhs._ptr)
            return *this;
        if (_ptr){
            (*_count)--;
            if ((*_count)==0){
                delete this->_ptr;
                delete this->_count;
            }
        }
        this->_ptr = rhs._ptr;
        this->_count = rhs._count;
        (*this->_count)++;
        return *this;
    }

    T& operator*(){
        // if (_ptr)
        return *_ptr;
    }

    T* operator->(){
        return _ptr;
    }

    size_t print_count(){
        return *this->_count;
    }

};

struct A{
    int var1;
    long var2;
    A(int a,int b):var1(a),var2(b){}
};

int main(){
    shared_ptr<struct A> ptr (new struct A(1,10));
    cout << ptr->var2 << endl;
    shared_ptr<int> p1(new int(10));
    cout << *p1 << endl;
    cout << p1.print_count() << endl;
    shared_ptr<int> p2(p1);
    cout << p2.print_count() << endl;
    shared_ptr<int> p3;
    p3 = p2;
    cout << p3.print_count() << endl;
    system("pause");
    return 0;
}