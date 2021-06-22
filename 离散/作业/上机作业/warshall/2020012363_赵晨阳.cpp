#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;  //怎么改字体颜色？
//为什么它中途没有给我报错？
//比如我写cin >> x，明明x没定义，也没报错？
//一组一组处理，还是输入完了全部处理？
int v, e, n;
int p[110], q[210];
bool map[101][101];
int path[101][101];
int check[12][2];//如果你写[12][1]的话，只能使用[0]

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
            map[i][q[j]] = 1;//为什么true和True都没定义？
            path[i][q[j]] = q[j];
        }
    }
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if ((i != k) && (map[i][j] == 0) && (map[i][k] && map[k][j]))//如果[i][k]!=0,则把第i行和第j行相加并记录在i
                {
                    path[i][j] = path[i][k];//更新的先后顺序!!!
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
