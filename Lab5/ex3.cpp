#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
 
#define N 120005
#define EPS 1e-6
 
using namespace std;

struct punct
{
    double x, y;
} v[N], Q;
 
int n, st[N], top;
bool viz[N];

double det(punct p1, punct p2, punct p3)
{
    return p2.x*p3.y + p1.x*p2.y + p3.x*p1.y - p2.x*p1.y - p3.x*p2.y - p1.x*p3.y;
}
double distance(punct p1, punct p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void Hull()
{
    st[1] = 1; st[2] = 2; top = 2;
    viz[2] = 1;
    for(int i = 3; i <= n; ++i)
    {
        while(top > 1 && det(v[st[top-1]], v[st[top]], v[i]) < 0)
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
            while(det(v[st[top-1]], v[st[top]], v[i]) < 0)
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
 
    cin >> Q.x >> Q.y;
    for(int i = 1; i <= top; ++i)
    {
        double determinant = det(v[st[i]], v[st[i+1]%top], Q);
        if(determinant < 0)
        {
            cout << "Punctul este in exterior";
            return 0;
        }
        else if(determinant == 0)
        {
            if(distance(v[i], v[st[i+1]%top]) + EPS <= distance(v[st[i]], Q) + distance(Q, v[st[i+1]%top]) && distance(v[st[i]], Q) + distance(Q, v[st[i+1]%top]) <= distance(v[i], v[st[i+1]%top]) + EPS)
            {
                cout << "Punctul este pe o latura";
                return 0;
            }
            else
            {
                cout << "Punctul este in exterior";
                return 0;
            }
        }
    }
    cout << "Punctul este in interior";
    return 0;
}