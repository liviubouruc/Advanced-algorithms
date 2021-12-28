#include <iostream>

using namespace std;

struct Point
{
    double x, y;
} P, Q, R;

double determinant(Point p1, Point p2, Point p3)
{
    return p2.x*p3.y + p1.x*p2.y + p3.x*p1.y - p2.x*p1.y - p3.x*p2.y - p1.x*p3.y;
}

int main()
{
    cin >> P.x >> P.y;
    cin >> Q.x >> Q.y;
    cin >> R.x >> R.y;

    double det = determinant(P, Q, R);
    if(determinant < 0) cout << "viraj la dreapta";
    else if(determinant > 0) cout << "viraj la stanga";
    else cout << "puncte coliniare";
    return 0;
}