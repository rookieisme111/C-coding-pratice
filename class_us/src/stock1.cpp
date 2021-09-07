#include <iostream>
#include <cstring>
#include "stock1.h"

void Stock::show()const
{
    using std::cout;
    using std::endl;
    cout << "Company:" << company
        << " Shares:" << shares <<endl    
        << "Shares Price: $" << share_val
        << " Total Worth: $" << total_val << endl;
}

Stock::Stock(const char* co, int n=0, double pr=0)
{
    company=co;
    if (n<0)
    {
        std::cerr << "Number of shares can't be negative; "
            << company <<"shares set to 0.\n";
        shares=0;
    }
    else    
        shares=n;
    share_val=pr;
    set_tot();
}

Stock::Stock()
{
    company="no name";
    shares=0;
    share_val=0.0;
    total_val=0.0;
}

const Stock & Stock::topval(const Stock & s)const
{
    if (s.total_val>total_val)
        return s;
    else
        return *this;
}

Stock::Stock(const std::string & co ,int n ,double pr)
{
    company=co;
    shares=n;
    share_val=pr;
    set_tot();
}
