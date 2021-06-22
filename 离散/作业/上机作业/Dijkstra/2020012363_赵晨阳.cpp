#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int v, e, n;//点数，边数，测试点数
int p[110], q[210];//正向表的第一行和第二行，点数不超过100，边数不超过200；
bool judge[110];//标定每一个点是否有判定过，每一组测试点清除一次
int d[210];//记录权值，后期转化到map上；
int dis[110];//记录到起点的distance，要清除；注意到权可以为0，故清除到infinite:0x7fffffff
int map[110][110];//记录边的权；map的初值赋值为-11；
int path[110];//记录父节点，要清除去为-1；
int check[110][2];//记录测试点
int road[110];//记录道路，每次刷新
int ind = 0;//ind用来记录road的长度

void way(int beg, int end)
{
    if (path[end] == beg)
    {
        return;
    }
    road[ind] = path[end];//road[0]存了第一个点，之后index从0到1；
    ind++;
    way(beg, path[end]);
}
void clear()
{
    ind = 0;
    for (int i = 0; i < v; i++)
    {
        dis[i] = 0x7fffffff;
        path[i] = -1;
        judge[i] = 0;
        road[i] = -1;
    }
}

int foundlowest()
{
    int m = 0x7fffffff;
    int n = -1;
    for (int i = 0; i < v; i++)
    {
        if ((judge[i] == 0) && (dis[i] < m))
        {
            m = dis[i];
            n = i;
        }
    }
    return n;
}
void Dijkstra(int beg, int end)//实际是没有起点终点是同一个结点的样例的
{
    judge[beg] = 1;
    judge[end] = 1;//beg和end是不用遍历的
    for (int i = 0; i < v; i++)
    {
        if (map[beg][i] != -1)
        {
            path[i] = beg;
            dis[i] = map[beg][i];
        }
    }
    for (int i = 0; i < v; i++)
    {
        int k = foundlowest();
        if (k == -1) { break; }
        for (int i = 0; i < v; i++)
        {
            if ((map[k][i] != -1) && (map[k][i] + dis[k] < dis[i]))
            {
                dis[i] = map[k][i] + dis[k];
                path[i] = k;
            }
        }
        judge[k] = 1;
    }
    if (dis[end] == 0x7fffffff)
    {
        cout << "NO PATH" << endl;
    }
    else
    {
        cout << "[" << beg;
        way(beg, end);
        for (int i = ind - 1; i >= 0; i--)
        {
            cout << "->" << road[i];
        }
        cout << "->" << end << " " << dis[end] << "]" << endl;
    }
}
int main()
{
    cin >> v >> e;
    for (int i = 0; i <= v; i++) { cin >> p[i]; }//正向表的p[i]有v+1项
    for (int i = 0; i < e; i++) { cin >> q[i]; }
    for (int i = 0; i < e; i++) { cin >> d[i]; }
    for (int i = 0; i < v; i++)for (int j = 0; j < v; j++)map[i][j] = -1;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> check[i][0] >> check[i][1]; }
    for (int i = 0; i < v; i++)for (int j = p[i]; j < p[i + 1]; j++)map[i][q[j]] = d[j];
    for (int i = 0; i < n; i++)
    {
        clear();
        Dijkstra(check[i][0], check[i][1]);
    }
    return 0;
}
