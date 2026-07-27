#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int,int> PII;

const int N=155;

int n,m;
PII start;
char g[N][N];
int dist[N][N];

int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};

int bfs(PII start,PII end)
{
    memset(dist,-1,sizeof dist);

    dist[start.first][start.second]=0;

    queue<PII> q;
    q.push(start);

    while(q.size())
    {
        auto t=q.front();
        q.pop();

        for(int i=0;i<8;i++)
        {
            int x=t.first+dx[i],y=t.second+dy[i];

            if(x<0||x>=n||y<0||y>=m) continue;
            if(g[x][y]=='*') continue;
            if(dist[x][y]!=-1) continue;

            dist[x][y]=dist[t.first][t.second]+1;

            if(make_pair(x,y)==end) return dist[x][y];

            q.push({x,y});
        }
    }

    return -1;
}

int main()
{
    cin>>m>>n;

    for(int i=0;i<n;i++) cin>>g[i];

    PII start,end;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='K')
                start=make_pair(i,j);
            else if(g[i][j]=='H')
                end=make_pair(i,j);

    cout<<bfs(start,end)<<endl;

    return 0;
}