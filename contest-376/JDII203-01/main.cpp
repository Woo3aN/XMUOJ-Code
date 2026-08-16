#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, m;
int f[N];

int main()
{
    cin >> n >> m;

    f[0] = 1;

    while (n--)
    {
        int v;
        cin >> v;

        for (int i = m; i >= v; i--)
        {
            f[i] += f[i - v];
        }
    }

    cout << f[m] << endl;

    return 0;
}