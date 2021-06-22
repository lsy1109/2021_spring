#include"Map.h"
Map::Map(int n)
{
    data=new Pair[n];
    sz=0;
}

int&Map::operator[](string x)
{
    for(int i=0;i<sz;i++)
    {
        if(data[i].hasKey(x))//hasKey中间的K是大写
        {
            return data[i].getVal();
        }
    }
    sz++;
    data[sz-1].reset(x,0);
    return data[sz-1].getVal();//忘记加小括号 
}
int Map::operator[](string x) const
{
    for(int i=0;i<sz;i++)
    {
        if(data[i].hasKey(x))//hasKey中间的K是大写
        {
            return data[i].getVal();
        }
    }
    return 0;
}

    int Map:: size()
    {
        return sz;
    }

    Map::~Map()
    {
        delete []data;
    }