#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("date.in");

int main()
{
    int k, sol = 0, x;
    fin >> k;
    while(fin >> x)
        if(sol + x <= k) sol += x;
        else sol = max(sol, x);
    cout << sol;
    return 0;
}

/*
Ideea de rezolvare a acestui subpunct este urmatoarea: in timp ce citim fiecare numar incercam sa il adunam la suma, 
fara a depasi valoarea k. La un moment dat vom avea o suma mai mica decat k/2 si vom incerca sa adunam la aceasta suma un numar x, putem avea 2 cazuri:
- daca suma va fi mai mare decat k atunci cu siguranta x va fi cel putin k/2, astfel il putem lua doar pe el, respectand conditia
- daca suma este mai mica decat k, o pastram si trecem mai departe
*/