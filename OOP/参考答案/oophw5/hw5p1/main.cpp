#include "Container.h"
#include <set>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <iostream>

using namespace std;

template<class A, class C>
void work(BasicContainer<A, Container<A, C<A>>>* cont)
{	
	int n;
    cin >> n;
    while(n--)
    {
		string act;
        cin >> act;
        if(act == "insert")
        {
			A item;
            cin >> item;
            cont->insert(item);
        }
        else
        {
			int k;
            cin >> k;
            cout << cont->find(k) << endl;
        }
    }
}

template <class A, class C>
void start(const string &base)
{
    BasicContainer<A, Container<A, C<A>>>* cont;
    if(base == "vector")
        cont = new Container<A, vector<A>>;
    else if(base == "multiset")
        cont = new Container<A, multiset<A>>;
    else if (base == "list")
        cont = new Container<A, list<A>>;
    //else if (base == "queue")
    //    cont = new Container<A, queue<A>>;
    work(cont);
    delete cont;
}

int main()
{
    string base, type;
    cin >> base >> type;
	
    if(type == "int")
        start<int>(base);
    else if(type == "string")
        start<string>(base);		
	
	return 0;
}
