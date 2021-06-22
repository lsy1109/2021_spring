/*ʵ�� Dijkstra �㷨����Ǹ�Ȩ����ͼ�����·����
������������ͼ���������ر߻��Ի����������л�·���Ĵ洢��������о���Ľ��ܣ�
�� 1 �а����ո�����Ķ������ v��1 <= v < 100���ͱߵĸ��� e��1 <= e < 200����
�� 2 �а��� v+1 ���������ո������p(i)��0 <= i <= v, 0 <= p(i) <= e����
�� 3 �а��� e ���������ո������q(i)��0 <= i <= e-1, 0 <= q(i) <= v-1����
�� 4 �а��� e ���������ո����������Ȩ�أ� r(i)��
�� 5 �а������Ե�Եĸ��� n��1 <= n <= 100����
�� 6~5+n �а����ո��������ʼ���� Vs(i) ����ֹ���� Ve(i)��0 <= Vs, Ve <= v-1����
��Ȩ����Ȩ�;����ᳬ�� int�ķ�Χ��*/

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
int road[110];
int index = 0;//index������¼road�ĳ���

//ÿ����Ҫ������ݣ�����յ㣬Ȩ��

void way(int beg, int end)
{
    if (path[end] == beg)
    {
        return;
    }
    road[index] = path[end];//road[0]���˵�һ���㣬֮��index��0��1��
    index++;
    way(beg,path[end]);
}

void print(int size = v)
{
    cout << "MAP is" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
            cout <<"farther["<<i<<"] is "<< path[i]<< endl;
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "distance[" << i << "] is " << dis[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "judge[" << i << "] is " << judge[i] << " ";
    }
    cout << endl;
}

void clear()
{
    for (int i = 0; i < v; i++)
    {
        dis[i] = 0x7fffffff;
        path[i] = -1;
        judge[i] = 0;
        road[i] = -1;
        index = 0;
    }
}

int foundlowest() 
{
    int m = 0x7fffffff;
    int n = -1;
    for (int i = 0; i < v; i++)
    {
        if ((judge[i] == 0) &&(dis[i] < m))
        {
            m = dis[i];
            n = i;
        }
    }
    return n;
}
void Dijkstra(int beg,int end)//ʵ����û������յ���ͬһ������������
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
        if (k == -1) { break;}
        for (int i = 0; i < v; i++)
        {
            if ((map[k][i] != -1)&&(map[k][i]+dis[k]<dis[i]))
            {
                dis[i] = map[k][i] + dis[k];
                path[i] = k;
            }
        }
        judge[k] = 1;
    }
    //print();
    if(dis[end]== 0x7fffffff)
    {
        cout << "NO PATH"<< endl;
        clear();
    }
    else
    {
        cout <<"["<< beg;
        way(beg, end);
        //cout << "index= " << index << endl;
        for (int i = index - 1; i >= 0; i--)
        {
            cout << "->" << road[i];
        }
        cout << "->" << end<<" "<<dis[end]<<"]";
        cout << endl;
        clear();
    }
}
int main()
{
    cin >> v >> e;
    for (int i = 0; i <= v; i++) { cin >> p[i]; }//������p[i]��v+1��
    for (int i = 0; i <e; i++) { cin >> q[i]; }
    for (int i = 0; i < e; i++) { cin >> d[i]; }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            map[i][j] = -1;
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> check[i][0] >> check[i][1]; }
    for (int i = 0; i < v; i++)
    {
        for (int j = p[i]; j < p[i + 1]; j++)
        {
            map[i][q[j]] = d[j];//������߸�Ȩֵ
        }
    }
    for (int i = 0; i < n; i++)
    {
        clear();
        Dijkstra(check[i][0], check[i][1]);
    }
    return 0;
}