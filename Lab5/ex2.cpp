#include <iostream>
#include <algorithm>
#include <iomanip>
 
#define N 120005
 
using namespace std;

struct punct
{
    double x, y;
} v[N];
 
int n, st[N], top;
bool viz[N];
 
double det(int i, int j, int p)
{
    return v[p].x*(v[i].y - v[j].y) + v[p].y*(v[j].x - v[i].x) + v[i].x*v[j].y - v[i].y*v[j].x;
}

void Hull()
{
    st[1] = 1; st[2] = 2; top = 2;
    viz[2] = 1;
    for(int i = 3; i <= n; ++i)
    {
        while(top > 1 && det(st[top-1], st[top], i) < 0)
        {
            viz[st[top]] = 0;
            top--;
        }
        st[++top] = i;
        viz[i] = 1;
    }
    for(int i = n-1; i; --i)
        if(!viz[i])
        {
            while(det(st[top-1], st[top], i) < 0)
            {
                viz[st[top]] = 0;
                top--;
            }
            st[++top] = i;
        }
}
 
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> v[i].x >> v[i].y;
 
    Hull();
 
    cout << top-1 << '\n';
    for(int i = 2; i <= top; ++i)
        cout << v[st[i]].x << " " << v[st[i]].y << '\n';
    return 0;
}