#include <iostream>
using namespace std;

class Match
{   
    public:
    int edge[25][25]={0};
    bool on_path[25]={0};
    int path[25]={-1};
    int max_path=0;
    Match(){}
    ~Match(){}
};

bool Hungary_match(Match*match,const int& xi,const int&x,const int&y,const int&num);
void print(Match*match,const int&y);void clear_on_path(Match*match);
void initial(Match*match);
int main()
{
    int x,y,num;
    cin>>x>>y>>num;
    Match match;
    initial(&match);
    for(int i=0;i<num;i++)
    {
        int f,j;
        cin>>f>>j;
        match.edge[f][j]=1;
    }
    for(int i=0;i<x;i++)
    {
        if(Hungary_match(&match,i,x,y,num))//bool Hungary_match(Match*match,int i)
        {
            match.max_path++;
        }
        clear_on_path(&match);//void clear_on_path(Match*match);
    }
    print(&match,y);//对于y储存的信息的倒叙输出
    return 0;
}

bool Hungary_match(Match*match,const int& xi,const int&x,const int&y,const int&num)
{
    for (int yj=0;yj<y;yj++)
    {
        if((match->edge[xi][yj]==1)&&!(match->on_path[yj]))
        {
            match->on_path[yj]=true;
            if((match->path[yj]==-1)||Hungary_match(match,match->path[yj],x,y,num))
            {
                match->path[yj]=xi;
                return true;
            }
        }
    }
    return false;
}

void print(Match*match,const int&y)
{   int my_path[20];//这里没有使用map来存储输出，因为：map下标访问时如果元素不存在，则创建对应元素，而不会提示访问错误。
    //cout<<"总共匹配边为："<<match->max_path<<endl;
    for(int i=0;i<20;i++)
    {
        my_path[i]=-1;
    }
    for(int i=0;i<y;i++)
    {
        if(match->path[i]!=-1)
        {
            my_path[match->path[i]]=i;
        }
    }
    for(int i=0;i<20;i++)
    {
        if(my_path[i]!=-1)
        {
            cout<<i<<" "<<my_path[i]<<endl;
        }
    }
    return;
}

void clear_on_path(Match*match)
{
    for(int i=0;i<25;i++)
    {
        match->on_path[i]=0;
    }
    return;
}

void initial(Match*match)
{
    for(int i=0;i<25;i++)
    {
    match->on_path[i]=0;
    match->path[i]=-1; 
    }
    return;
}