#include<iostream>
using namespace std;
int v, e;
int p[110], q[1010];
int d[1010];
int k = 0;
int m = 0;
int tree = 0;
class side
{
public:
    int value = 0;
    int pot1 = 0;
    int pot2 = 0;
};
class c
{
public:
    int start_point = 0;
    int end_point = 0;
};
class point
{
public:
    int length = 0x7fffffff;
    int farther_point = 220;
    bool included_in_c = 0;
};
void update(int m, point* x, side* y, c* z);
void prim(point* x, side* y, c* z);
void print(c* z);
void printnow(c* z);
int main()
{
    cin >> v >> e;
    point* x = new point[v + 1];
    side* y = new side[e + 1];
    c* z = new c[v + 1];
    for (int i = 0; i < v + 1; i++) { cin >> p[i]; }
    for (int i = 0; i < e; i++) { cin >> q[i]; }
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
    for (int i = 0; i < e; i++)
    {
        if (x[y[i].pot1].included_in_c != x[y[i].pot2].included_in_c)
        {
            if ((y[i].pot1 == m) && (y[i].value < x[y[i].pot2].length))
            {
                x[y[i].pot2].length = y[i].value;
                x[y[i].pot2].farther_point = m;
            }
            else if ((y[i].pot2 == m) && (y[i].value < x[y[i].pot1].length))
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
        if (x[i].included_in_c == 0)
        {
            if (x[i].length < now)
            {
                ind = i;
                now = x[i].length;
            }
        }
    }
    x[ind].included_in_c = 1;
    if (x[ind].farther_point > 150)
    {
        z[k].start_point = ind;
        z[k].end_point = x[ind].farther_point - 200;
        tree += x[ind].length;
    }
    else
    {
        z[k].start_point = x[ind].farther_point;
        z[k].end_point = ind;
        tree += x[ind].length;
    }
    k++;
    update(ind, x, y, z);
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
