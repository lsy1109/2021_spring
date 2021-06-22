#include<iostream>//什么时候用箭头，指针才用箭头，这里纯粹是数组罢了
using namespace std;
int v, e;//点数，边数，测试点数//点类必须要有，用来判定边是否在某个集合etc，通过几个bool来判定集合关系//重边与自环
int p[110], q[1010];//正向表的第一行和第二行，点数不超过100，边数不超过1000；
int d[1010];//记录权值，存储在side里面
int k = 0;//用来记录哪些边存入了Class C时的临时变量
int m = 0;//在边存入时的临时变量
int tree = 0;
class side
{
public:
    int value = 0;
    int pot1 = 0;//记录出发点
    int pot2 = 0;//用来记录终点
};
class c//c集合用于储存输出边和输出点，以及输出顺序，输出最后的长度，注意输出顺序是按照输入边的顺序来输出
{
public:
    int start_point = 0;
    int end_point = 0;
};
class point
{
public:
    int length = 0x7fffffff;//起始长度之后不断被更新
    int farther_point = 220;//记录父节点
    bool included_in_c = 0;//一个点是否被c包含，甚至不用记录点的标号，应为边完全可以替代点的标号
};
void update(int m, point* x, side* y, c* z);
void prim(point* x, side* y, c* z);
void print(c* z);
void printnow(c* z);
int main()
{
    cin >> v >> e;
    point* x = new point[v + 1];//动态分配，记得删除
    side* y = new side[e + 1];//动态分配，记得删除
    c* z = new c[v + 1];//v个点的图树的边数为v-1
    for (int i = 0; i < v + 1; i++) { cin >> p[i]; }//正向表的p[i]有v+1项
    for (int i = 0; i < e; i++) { cin >> q[i]; }//正向表的第三行一共有e个元素
    for (int i = 0; i < e; i++) { cin >> d[i]; }
    for (int i = 0; i < v; i++)
    {
        for (int j = p[i]; j < p[i + 1]; j++)
        {
            y[m].pot1 = i;
            y[m].pot2 = q[j];
            y[m].value = d[j];
            m++;
        }
    }
    x[0].included_in_c = 1;
    update(0, x, y, z);
    prim(x, y, z);
    print(z);
    delete[]x;
    delete[]y;
    delete[]z;
    return 0;
}
void update(int m, point* x, side* y, c* z) {
    //不要搞混了，update的目的仅仅是更新而已
    for (int i = 0; i < e; i++)
    {
        if (x[y[i].pot1].included_in_c != x[y[i].pot2].included_in_c)
        {
            if ((y[i].pot1 == m) && (y[i].value < x[y[i].pot2].length))//某条边e[i],起点是m，终点是n，终点记录的长度比e[i]长，那么更新n的长度与n的起点，n的起点记为m即可
            {
                x[y[i].pot2].length = y[i].value;
                x[y[i].pot2].farther_point = m;
            }
            else if ((y[i].pot2 == m) && (y[i].value < x[y[i].pot1].length))//某条边e[i],终点是m，起点是n，起点记录的长度比e[i]长，那么更新n的长度与n的起点，n的起点记为200+m，不要记为-m，不然0会出问题
            {
                x[y[i].pot1].length = y[i].value;
                x[y[i].pot1].farther_point = m + 200;
            }
        }
    }
}
void prim(point* x, side* y, c* z) {
    if (k == v - 1) { return; }
    int now = 0x7fffffff;
    int ind = 220;
    for (int i = 0; i < v; i++)
    {
        if (x[i].included_in_c == 0)//如果一个点没有被C集合包含
        {
            if (x[i].length < now)//这个点的长度记录比已知的值小
            {
                ind = i;//index记录这个点
                now = x[i].length;//已知值改为现在这个点的长度
            }
        }
    }
    x[ind].included_in_c = 1;//将x加入c，且把这个数对加入class C
    if (x[ind].farther_point > 150)//小心0，0+200不大于200
    {
        z[k].start_point = ind;
        z[k].end_point = x[ind].farther_point - 200;//如果一个点的父节点大于200，那么他一定自己是起点，父节点-200是终点
        tree += x[ind].length;
    }
    else
    {
        z[k].start_point = x[ind].farther_point;
        z[k].end_point = ind;//如果一个点的父节点不大于两百，那么父节点是起点，自己是终点
        tree += x[ind].length;
    }
    k++;
    update(ind, x, y, z);
    //printnow(z);
    prim(x, y, z);
}
void print(c* z)
{
    for (int i = 0; i < v - 1; i++)
    {
        cout << "[" << z[i].start_point << "->" << z[i].end_point << "]";
    }
    cout << " " << tree << endl;
}
void printnow(c* z)
{
    for (int i = 0; i < k; i++)
    {
        cout << "[" << z[i].start_point << "->" << z[i].end_point << "]";
    }
    cout << " " << tree << endl;
}