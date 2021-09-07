#include <iostream>
#include "stock1.h"

int main()
{
    using namespace std;
    const Stock zhao=Stock("alibabaasdasdasdasdaddasdasdasd",20,600.67);
    const Stock xu=Stock("Tencentasdasddasddadqdasdasddad",15,724.23);
    string company_name="ByteDanceasdasdasdasdasdasdasd";
    const Stock gao=Stock(company_name,30,309.7);
    zhao.show();
    cout << endl;
    xu.show();
    cout << endl;
    gao.show();
    cout << endl;
    Stock top;
    top=zhao.topval(xu);
    cout << "bigger val:" << endl;
    top.show();
    cin.get();
    
    return 0;
}