#include <iostream>
#include <set>

using namespace std;

set<int> sume;

int main()
{
    int n, k, Max = 0;
    cin >> n >> k;
    sume.insert(0);
    for(int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        for(auto j : sume)
            if(j + x <= k)
            {
                sume.insert(j + x);
                Max = max(Max, j+x);
            }
    }
    cout << Max;
    return 0;
}