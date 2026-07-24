#include <iostream>
#include <algorithm>
#include <queue>
 
using namespace std;
 
int k,m,n;
int get_int_sum(int x)
{
    int s=0;
    while(x)
        s+=x%10,x/=10;
    return s;
}
 
int get_pair_sum(pair<int,int> p)
{
    int s=0;
    s+=get_int_sum(p.first);
    s+=get_int_sum(p.second);
    return s;
}
 
int bfs(int threshold,int rows,int cols)
{
    if(!rows||!cols)
        return 0;
 
    vector<vector<bool>> st(rows,vector<bool>(cols,false));
 
    queue<pair<int,int>> q;
 
    int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
 
    int res=0;
    q.push({0,0});
    while(q.size())
    {
        auto t=q.front();
        q.pop();
 
        if(st[t.first][t.second]||get_pair_sum(t)>threshold)
            continue;
        res++;
        st[t.first][t.second]=true;
 
        for(int i=0;i<4;i++)
        {
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x>=0&&x<rows&&y>=0&&y<cols)
            q.push({x,y});
        }
    }
  return res;
}
 
int main()
{
    int ans;
    cin>>k>>m>>n;
    ans=bfs(k,m,n);
    cout<<ans;
}