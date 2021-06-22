#pragma once
#include <vector>
#include <list>
#include <functional>
using namespace std;


template<class A, class B>
class MyQueriable {
    B base;
public:
    MyQueriable(B v) : base(v) {}

    int size() {
        return base.size();
    }
    
    A operator[](int k) {
        auto t = base.begin();
        while (k--) ++t;
        return *t;
    }

    MyQueriable<A, B> where(function<bool(A)> bfunc) {
        B filtered;
        for (auto t = base.begin(); t != base.end(); ++t) {
            if (bfunc(*t)) filtered.push_back(*t);
        }
        return MyQueriable(filtered);
    }

    MyQueriable<A,B> apply(function<A(A)> afunc) {
        B applied;
        for (auto t = base.begin(); t != base.end(); ++t) {
            applied.push_back(afunc(*t));
        }
        return MyQueriable(applied);
    }

    A sum() {
        A s = 0;
        for (auto t = base.begin(); t != base.end(); ++t)
            s += *t;
        return s;
    }
};

template<typename A>
MyQueriable<A, vector<A>> from(vector<A> v) {
    MyQueriable<A, vector<A>> m(v);
    return m;
}

template<typename A>
MyQueriable<A, list<A>> from(list<A> v) {
    MyQueriable<A, list<A>> m(v);
    return m;
}