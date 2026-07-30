#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

#define For(i, a, b) for (int i = a; i < b; i++)
#define INF 0x3f

typedef pair<int, int> PII;
const int N = 507;
int n, m;
char area[N][N];
int dist[N][N];

void BuildMap(int n, int m)
{
    For(i, 0, n) For(j, 0, m)
    {
        cin >> area[i][j];
    }
}

bool isInside(int x, int y)
{
    return x >= 0 && x <= n && y >= 0 && y <= m;
}

int getWeight(int x, int y, int dir)
{
    int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};
    char edge[] = "\\/\\/";
    int newX = x + ix[dir], newY = y + iy[dir];
    if (area[newX][newY] == edge[dir])
        return 0;
    else
        return 1;
}

int bfs()
{
    int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
    memset(dist, INF, sizeof(dist));
    deque<PII> dq;
    dq.push_back({0, 0});
    dist[0][0] = 0;
    while (dq.size())
    {
        auto qHead = dq.front();
        dq.pop_front();
        PII next;
        For(i, 0, 4)
        {
            next.first = qHead.first + dx[i];
            next.second = qHead.second + dy[i];
            if (isInside(next.first, next.second))
            {
                int weight = getWeight(qHead.first, qHead.second, i);
                if (dist[next.first][next.second] > dist[qHead.first][qHead.second] + weight)
                {
                    dist[next.first][next.second] = dist[qHead.first][qHead.second] + weight;
                    if (weight == 1)
                        dq.push_back(next);
                    if (weight == 0)
                        dq.push_front(next);
                }
            }
        }
    }
    if (dist[n][m] == 0x3f3f3f3f)
        return -1;
    else
        return dist[n][m];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        memset(area, -1, sizeof(area));
        BuildMap(n, m);
        int res = bfs();
        if (res == -1)
            cout << "NO SOLUTION" << endl;
        else
            cout << res << endl;
    }
    return 0;
}
