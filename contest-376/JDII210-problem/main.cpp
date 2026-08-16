#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_V = 505;
const int MAX_M = 505;

int dp[MAX_V][MAX_M];

int main()
{
    int N, V, M;
    cin >> N >> V >> M;

    for (int i = 0; i <= V; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        int vi, mi, wi;
        cin >> vi >> mi >> wi;

        for (int j = V; j >= vi; j--)
        {
            for (int k = M; k >= mi; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - vi][k - mi] + wi);
            }
        }
    }

    cout << dp[V][M] << endl;

    return 0;
}