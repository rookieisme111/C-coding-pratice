#include <iostream>
#include <string>

#ifndef STOCK1_H_
#define STOCK1_H_

class Stock
{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot(){ total_val =shares * share_val;}

public:
    Stock (const char* co, int n, double pr);
    Stock (const std::string & co,int n,double pr);
    Stock ();
    ~Stock(){ std::cout << "bye " <<company <<std::endl;}
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    void show() const ;
    const Stock & topval(const Stock & s)const;
};

#endif