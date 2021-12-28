#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector> 

#define N 120005
#define EPS 1e-6
#define inf 1e9
 
using namespace std;

struct punct
{
    double x, y;
    friend bool operator==(const punct &a, const punct &b) {
        return a.x == b.x && a.y == b.y;
    }
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
            viz[i] = 1;
        }
}
 
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> v[i].x >> v[i].y;
 
    Hull();
 
    vector <punct> left_points, sol;
    for(int i = 1; i <= n; ++i)
        if(!viz[i]) left_points.insert(left_points.end(), v[i]);
    for(int i = 1; i < top; ++i) sol.insert(sol.end(), v[st[i]]);

    while(!left_points.empty())
    {
        double rapMin = inf;
        int pozInsert;
        punct toInsert;
        for(auto i : left_points)
        {
            double difMin = inf;
            int poz = 0;
            for(int j = 1; j <= top; ++j)
            {
                double difDist = distance(v[st[j]], i) + distance(i, v[st[j+1]%top]) - distance(v[st[j]], v[st[j+1]]);
                difMin = min(difMin, difDist);
                if(difDist < difMin)
                {
                    difMin = difDist;
                    poz = j;
                }
            }
            double rapDist = distance(v[st[poz]], i) + distance(i, v[st[poz+1]%top]) - distance(v[st[poz]], v[st[poz+1]]);
            if(rapDist < rapMin)
            {
                rapMin = rapDist;
                pozInsert = poz-1;
                toInsert = i;
            }
        }
        //left_points.erase(remove(left_points.begin(), left_points.end(), toInsert), left_points.end());
        int pozI;
        for(int i = 0; i < left_points.size(); ++i)
            if(left_points[i] == toInsert) pozI = i;
        left_points.erase(left_points.begin()+pozI); 
        sol.insert(sol.begin()+pozInsert+1, toInsert);
    }

    for(auto i : sol) cout << "(" << i.x << "," << i.y << ") ->";
    return 0;
}