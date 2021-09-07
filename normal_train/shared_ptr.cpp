#include <string>

class HasPtr{
public:
    friend void swap(HasPtr&,HasPtr&);
    HasPtr(const std::string& rhs=std::string()):
        ps(new std::string(rhs)),i(0),use(new std::size_t(1));
    
    HasPtr(const HasPtr& p):
        ps(p.ps),i(p.i),use(p.use) { ++*use;}

    HasPtr& operator=(const HasPtr& p);
    ~HasPtr();

private:
    std::string * ps;
    int i;
    std::size_t *use;
}

inline void swap(HasPtr &lhs,HasPtr &rhs){
    using std::swap;
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
}

HasPtr::~HasPtr(){
    if (--*use==0){
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs){
    ++*rhs.use;
    if (--*use==0){
        delete ps;
        delete use;
    }
    ps=rhs.ps;
    i=rhs.i;
    use=rhs.use;
    return *this;

}

HasPtr& HasPtr::operator=(const HasPtr &rhs){
    ++*rhs.use;
    if(--*use==0){
        delete ps;
        delete use;
    } 
    use=rhs.use;
    i=rhs.i;
    ps=rhs.ps;
    return *this;
}