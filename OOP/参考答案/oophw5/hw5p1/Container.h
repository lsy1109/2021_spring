#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <vector>
#include <set>
#include <algorithm>
//#include <iostream>
template<class A, class C>
class Container : public BasicContainer<A, Container<A, C<A>>>
{
    C base;
public:
    void insert_(const A &x)
    {
        //std::cout << "using general insert" << std::endl;
        for(auto t = base.begin(); t != base.end(); ++t)
            if(*t > x)
            {
                base.insert(t, x);
                return;
            }
        base.insert(base.end(), x);
    }
    A find_(int k)
    {
        //std::cout << "using general find" << std::endl;
        auto t = base.begin();
        while(--k)
            ++t;
        return *t;
    }
};

template<typename A>
class Container <A, std::vector<A>> : public BasicContainer<A, Container<A, vector<A>>>
{
    std::vector<A> base;
    bool sorted = false;
public:
    void insert_(const A &x) {
        //std::cout << "using vector insert" << std::endl;
        base.insert(base.end(), x);
    }
    A find_(int k) {
        //std::cout << "using vector find" << std::endl;
        if (!sorted) {
            sort(base.begin(), base.end());
            sorted = true;
        }
        return base[k - 1];
    }
};

template<class A>
class Container<A, std::multiset<A>> : public BasicContainer<A, Container<A, multiset<A>>>
{
    std::multiset<A> base;
public:
    void insert_(const A &x) {
        //std::cout << "using multiset insert" << std::endl;
        base.insert(x);
    }
    A find_(int k) {
        //std::cout << "using multiset find" << std::endl;
        auto t = base.begin();
        while(--k)
            ++t;
        return *t;
    }
};
#endif
