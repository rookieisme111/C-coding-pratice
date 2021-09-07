#include <iostream>

int main()
{
    using namespace std;
    int* p= new int;
    *p=1001;
    cout << "int ";
    cout << "value = " << *p << "; location= " << p << endl;

    double* pd=new double;
    *pd=10000001.0;

    cout << "double";
    cout << "value = " << *pd << ", location= " << pd << endl;
    cout << "size of p= " << sizeof(p);
    cout << " size of *p= " << sizeof(*p) <<endl;
    cout << "size of pd= " << sizeof(pd);
    cout << " size of *pd= " << sizeof(*pd) <<endl;

    cin.get();
    return 0;
}