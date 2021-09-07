# include <iostream>

template <class T, class Alloc = alloc>
class vector {
public:
    typedef T   value_type;
    typedef T*  iterator;
    typedef T&  reference;
    typedef T*  pointer;
    typedef ptrdiff_t   diff_type;
    typedef size_t size_type;

protected:
    iterator    start;
    iterator    finish;
    iterator    end_of_storage;

public:
    void push_back(const T& x);
}

void vector::push_back(const T& x){
    if (finsih!=end_of_storage){
        construct(finish,x);
        ++finsih;
    }
    else{
        iterator new_start,new_finish;
        size_type len = size()==0?1:2*size();
        new_start = data_allocator::allocate(len);
        new_finish = new_start;

        uninitialized_copy(start,finish,new_start);
        new_finish = new_start + size();
        construct(new_finish,x);

        destory(start,finish);
        deallocate();

        start = new_start;
        finish = new_finsih;
        end_of_storage = new_start + len;

    }
}