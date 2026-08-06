#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int h[N];
int f[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &h[i]);

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            f[i] = 1;
            for (int j = 0; j < i; j++)
                if (h[i] < h[j])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }

        memset(f, 0, sizeof f);
        for (int i = n - 1; i >= 0; i--)
        {
            f[i] = 1;
            for (int j = n - 1; j > i; j--)
                if (h[i] < h[j])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }

        printf("%d\n", res);
    }

    return 0;
}
