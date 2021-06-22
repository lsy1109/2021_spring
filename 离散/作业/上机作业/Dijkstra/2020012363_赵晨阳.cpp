#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int v, e, n;//���������������Ե���
int p[110], q[210];//�����ĵ�һ�к͵ڶ��У�����������100������������200��
bool judge[110];//�궨ÿһ�����Ƿ����ж�����ÿһ����Ե����һ��
int d[210];//��¼Ȩֵ������ת����map�ϣ�
int dis[110];//��¼������distance��Ҫ�����ע�⵽Ȩ����Ϊ0���������infinite:0x7fffffff
int map[110][110];//��¼�ߵ�Ȩ��map�ĳ�ֵ��ֵΪ-11��
int path[110];//��¼���ڵ㣬Ҫ���ȥΪ-1��
int check[110][2];//��¼���Ե�
int road[110];//��¼��·��ÿ��ˢ��
int ind = 0;//ind������¼road�ĳ���

void way(int beg, int end)
{
    if (path[end] == beg)
    {
        return;
    }
    road[ind] = path[end];//road[0]���˵�һ���㣬֮��index��0��1��
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
void Dijkstra(int beg, int end)//ʵ����û������յ���ͬһ������������
{
    judge[beg] = 1;
    judge[end] = 1;//beg��end�ǲ��ñ�����
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
    for (int i = 0; i <= v; i++) { cin >> p[i]; }//������p[i]��v+1��
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
