#include <iostream>

using namespace std;

const int N = 1010;

int n;
int w[N];
int f[N];

int main()
{
    // input
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];

    // dp
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (w[i] > w[j])
            {
                f[i] = max(f[i], f[j] + w[i]);
            }
        }
    }

    // find res
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = max(res, f[i]);

    // output
    cout << res << endl;

    return 0;
}
