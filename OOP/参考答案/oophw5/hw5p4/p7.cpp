#include <functional>
#include <algorithm>
using namespace std;

bool compPt(int a, int b)
{
    return a < b;
}

class CompCls
{
public:
    bool operator()(int a, int b) const
    {
        return a < b;
    }
};

function<bool(int, int)> fn = compPt;

template<class T, class Compare>
void mysort1(T* first, T* last, Compare comp)
{
    for (auto i = first; i != last; i++)
        for (auto j = i; j != last; j++)
            if (!comp(*i, *j)) swap(*i, *j);
}

template<class T>
void mysort2(T* first, T* last, function<bool(T, T)> comp)
{
    for (auto i = first; i != last; i++)
        for (auto j = i; j != last; j++)
            if (!comp(*i, *j)) swap(*i, *j);
}

int main()
{
    int arr[] = {2, 1, 3, 5, 4};
    //(1)
    mysort2(arr, arr + 5, compPt);
    //compPt(1, 2);
    //CompCls(1, 2);
    //fn(1, 2);
    return 0;
}