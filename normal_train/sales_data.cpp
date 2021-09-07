#include <iostream>
#include <string>
class Sales_data{
public:    
    //结构体的默认访问权限是公有的public
    Sales_data() =default;
    
    Sales_data(const std::string &s):bookNo(s){}
    Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}

    void show() const { std::cout << bookNo <<' '<<units_sold<<' '<<revenue;}
    std::string isbn() const { return bookNo;}
    Sales_data & combine(const Sales_data &);
    double avg_price() const;
private:
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
};
Sales_data add(const Sales_data &,const Sales_data &);
std::ostream & print(std::ostream &, const Sales_data &);
std::istream & read(std::istream &, Sales_data &);

int main(){

    Sales_data b("SadWorld!",10,20.1);
    Sales_data a=b;
    std::cout << a.isbn()<< std::endl;
    a.show();
    system("pause");
    return 0;
}
