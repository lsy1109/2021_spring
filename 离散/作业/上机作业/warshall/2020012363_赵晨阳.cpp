#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;  //��ô��������ɫ��
//Ϊʲô����;û�и��ұ���
//������дcin >> x������xû���壬Ҳû����
//һ��һ�鴦��������������ȫ������
int v, e, n;
int p[110], q[210];
bool map[101][101];
int path[101][101];
int check[12][2];//�����д[12][1]�Ļ���ֻ��ʹ��[0]

void way(int beg, int end)
{
    cout << "->" << path[beg][end];
    if (path[beg][end] == end)
    {
        return;
    }
    way(path[beg][end], end);
}

void print(int size=v)
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
    cout << "PATH is" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    cin >> v >> e;
    for (int i = 0; i <= v; i++) { cin >> p[i]; }
    for (int i = 0; i <= e - 1; i++) { cin >> q[i]; }
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> check[i][0] >> check[i][1]; }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            path[i][j] = -1;
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = p[i]; j < p[i + 1]; j++)
        {
            map[i][q[j]] = 1;//Ϊʲôtrue��True��û���壿
            path[i][q[j]] = q[j];
        }
    }
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if ((i != k) && (map[i][j] == 0) && (map[i][k] && map[k][j]))//���[i][k]!=0,��ѵ�i�к͵�j����Ӳ���¼��i
                {
                    path[i][j] = path[i][k];//���µ��Ⱥ�˳��!!!
                }
                map[i][j] = map[i][j] || (map[i][k] && map[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (map[check[i][0]][check[i][1]] != 0)
        {
            cout << check[i][0];
            way(check[i][0], check[i][1]);
            cout << endl;
        }
        else
        {
            cout << "NO PATH" << endl;
        }
    }
    return 0;
}
