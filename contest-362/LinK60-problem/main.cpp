#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define For(a,begin,end) for(int a=(begin);a<(end);a++)
const int N=10000007;

int n,m;
int head[N],edge[N],nextVertex[N],idx;
int q[N],d[N];

void add(int a,int b)
{
    edge[idx]=b;
    nextVertex[idx]=head[a];
    head[a]=idx++;
}

bool topsort()
{
    int qHeadIdx=0,qTailIdx=-1;

    for(int i=1;i<=n;i++)
        if(!d[i])
            q[++qTailIdx]=i;

    while(qHeadIdx<=qTailIdx)
    {
        int t=q[qHeadIdx++];

        for(int i=head[t];i!=-1;i=nextVertex[i])
        {
            int j=edge[i];
            d[j]--;
            if(d[j]==0)
                q[++qTailIdx]=j;
        }
    }

    return qTailIdx==n-1;
}

int main()
{
    cin>>n>>m;
    memset(head,-1,sizeof(head));

    For(i,0,m)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b]++;
    }

    if(topsort())
    {
        for(int i=0;i<n;i++) printf("%d ",q[i]);
    }
    else
        puts("-1");
    
        return 0;
}