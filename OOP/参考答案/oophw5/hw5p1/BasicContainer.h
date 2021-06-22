#ifndef BASICCONTAINER_H
#define BASICCONTAINER_H

template<class A, class B>
class BasicContainer
{
public:
    void insert(const A &x) {
        B* pB = static_cast<B*>(this);
        pB->insert_();
    };
    A find(int k) {
        B* pB = static_cast<B*>(this);
        pB->find_();
    };
};
#endif
