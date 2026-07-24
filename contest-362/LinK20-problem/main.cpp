#include <iostream>
using namespace std;

const int N = 50;

int n,m;
int path[N];
void dfs(int u,int start)
{
    if(u>m)
    {
        for(int i=1;i<=m;i++)
            cout<<path[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int i=start;i<=n;i++)
        {
            path[u]=i;
            dfs(u+1,i+1);
            path[u]=0;
        }
    }
}

int main()
{
  cin>>n>>m;
  dfs(1,1);

  return 0;
}
