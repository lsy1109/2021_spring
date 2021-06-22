#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

class Point{
    public:
    int number=0;//编号
    int timecost=0;//时间花费
    int enter=0;//入度
    int waste=0;//可以延迟的时间
    int qui=0;//工序最早启动时间
    int sl=0;//工序最晚启动时间
    vector<int>pre_wa;//所有的先前节点的花销
    vector<int>pre_point;//全部前驱节点
    vector<int>success_point;//全部后继节点
};
vector<int>top_result;//记录top后的数组，
int quick[103];//把这个0删去了int quick[103]={0};
int slow[103];
vector<int>pre_waste[103];
vector<int>superend;//用来转移superend
int reverse_top_result[103];
void input(int &n,Point*node);
void topsort(int &n,Point*node);
void print1(int &n,Point*node);
void print2(int&n,Point*node);
void set_super_end(int&n,Point*node);
void print_supreme_path(int n, Point*node);
void quicktime(int&n,Point*node);
void slowtime(int &n,Point*node);
vector<int>path;

int main() {
    int n;cin>>n;
    Point*node=new Point[103];
    input(n,node);
    //cout<<"输入完成后打印结束"<<endl;
    //print1(n);
    set_super_end(n,node);
    /*for(int i=0;i<superend.size();i++)
    {   cout<<"输出superend"<<endl;
        cout<<superend[i]<<"我日"<<endl;
    }
    cout<<"superend 结束了"<<endl;
    node[n].pre_point=superend;  
for(int i=0;i<node[n].pre_point.size();i++)
    {   cout<<"输出superend"<<endl;
        cout<<node[n].pre_point[i]<<"我日"<<endl;
    }*/
    //cout<<endl;
    //cout<<"设置超节点后打印结束"<<endl;
    //print1(n);
    Point*virtual_node=new Point[110];
    for (int i=0;i<n;i++){
        virtual_node[i]=node[i];
    }//先赋值再排序
    topsort(n,node);
     //cout<<endl;
    //cout<<"top结果"<<endl;
    /*for(int i=0;i<n;i++)
    {
        cout<<top_resulslow[i]<<" ";
    }
    cout<<endl;
    cout<<"top排序结束了后的数据为"<<endl;
    print1(n);
    cout<<"这是print1的结果"<<endl;
    print2(n);*/
    for (int i=0;i<n;i++){
        node[i]=virtual_node[top_result[i]];
    } 
    for (int i=0;i<n;i++){
        reverse_top_result[top_result[i]]=i;
    }//排序之后的还原
    /*cout<<endl;
    cout<<"我做了交换"<<endl;
    print1(n);
    cout<<"这是print1的结果"<<endl;
    print2(n);*/
    quicktime(n,node);
    //cout<<endl;
    cout<<quick[n-1]<<endl;//最后一个点的最早起始时间，也就是开始时间
    /*cout<<"寻找出时间后的输出"<<endl;
    print1(n);
    cout<<"这是print1的结果"<<endl;
    print2(n);*/
    print_supreme_path(n-1,node);
    slow[n-1]=quick[n-1];
    slowtime(n,node);
    for (int i=0;i<n-1;i++){
        cout<<node[reverse_top_result[i]].waste<<endl;
    }
    //print1(n);
    //print2(n);
    delete[]node;
    delete[]virtual_node;
    return 0;
}

void topsort(int &n,Point*node){//拓扑排序
    queue<int>q;
    for (int i=0;i<n;i++){
        if (node[i].enter==0){q.push(i);}
    }
    while (!q.empty()){
        int p=q.front();
        q.pop();
        top_result.push_back(p);
        for (int i=0;i<node[p].success_point.size();i++){
            int y=node[p].success_point[i];
            node[y].enter--;
            if (node[y].enter==0){
                q.push(y);
            }
        }
    }
}

void print1(int &n,Point* node)
{
    for(int i=0;i<n;i++)
    {
        cout<<"序号为："<<node[i].number<<" 时间消耗为："<<node[i].timecost<<" 最早启动时间为："<<node[i].qui<<" 最晚启动时间为："<<node[i].sl<<endl;
    }
}
void print2(int&n,Point*node)
{
     for(int i=0;i<n;i++)
    {
        cout<<"序号为："<<reverse_top_result[i]<<" 时间消耗为："<<node[reverse_top_result[i]].timecost<<" 最早启动时间为："<<node[reverse_top_result[i]].qui<<" 最晚启动时间为："<<node[reverse_top_result[i]].sl<<endl;
    }
}
void input(int &n,Point*node)//本来想用getline，还是老实getchar好了，哎，de了大半天
{
    for (int i=0;i<n;i++){
        cin>>node[i].number>>node[i].timecost;
        char c;
        if ((c=getchar())!=' '){continue;}
        int num=0;
        bool nopre_waste=true;
        while((c = getchar()) >' '){
            nopre_waste=false;
            if (c!=','){
                int tmp=c-'0';
                num=num*10+tmp;
            }
            else{
                node[i].pre_point.push_back(num);
                node[num].success_point.push_back(i);
                node[i].enter++;
                num=0;
            }
        }
        if (nopre_waste){continue;}
        else{
            node[i].pre_point.push_back(num);
            node[num].success_point.push_back(i);
            node[i].enter++;}
    }
}
void set_super_end(int&n,Point*node)
{
    for (int i=0;i<n;i++){
        if (node[i].success_point.size()==0){
            superend.push_back(i);
            node[i].success_point.push_back(n);
        }
    }
    node[n].number=n;
    node[n].timecost=0;
    node[n].enter=superend.size();
    node[n].pre_point=superend;  
    n=n+1;
    return;
}
void print_supreme_path(int n, Point*node)
{//注意到，这其实本质上是深度优先搜索+回溯法
    if (node[n].pre_point.size()==0){
        cout<<"[";
        for (int j=path.size()-1;j>=0;j--){
            cout<<node[path[j]].number<<"->";
        }
        cout<<"end]"<<endl;
        return;
    }
    for (int i=0;i<pre_waste[n].size();i++){
        path.push_back(pre_waste[n][i]);
        print_supreme_path(pre_waste[n][i],node);
        path.pop_back();
    }
}


void quicktime(int&n,Point*node)
{
    for (int i=1;i<n;i++)
    {
        int ind=0;
        for (int j=0;j<node[i].pre_point.size();j++)
        {
            if (ind<quick[reverse_top_result[node[i].pre_point[j]]]+node[reverse_top_result[node[i].pre_point[j]]].timecost){
                ind=quick[reverse_top_result[node[i].pre_point[j]]]+node[reverse_top_result[node[i].pre_point[j]]].timecost;
                pre_waste[i].clear();
                pre_waste[i].push_back(reverse_top_result[node[i].pre_point[j]]);
            }
            else if (ind==quick[reverse_top_result[node[i].pre_point[j]]]+node[reverse_top_result[node[i].pre_point[j]]].timecost){
                pre_waste[i].push_back(reverse_top_result[node[i].pre_point[j]]);
        }
    }
        quick[i]=ind;
    }
    return;
}
void slowtime(int &n,Point*node)
{
      for (int i=n-2;i>=0;i--){
        int tmp=slow[n-1];
        if (node[i].success_point.size()==0){
            slow[i]=tmp-node[i].timecost;
            continue;
        }
        for (int j=0;j<node[i].success_point.size();j++){
            if (tmp>slow[reverse_top_result[node[i].success_point[j]]]-node[i].timecost){
                tmp=slow[reverse_top_result[node[i].success_point[j]]]-node[i].timecost;
            }
        }
        slow[i]=tmp;
    }
    for (int i=0;i<n;i++){
        node[i].waste=slow[i]-quick[i];
    }
    return;
}