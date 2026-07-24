#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
 
int res[92][8];
int path[8];
int count=0;
 
void dfs(int n)
{
    if(n>7)
    {
        for(int k=0;k<n;k++)
        {
            res[count][k]=path[k];
        }
        count++;
        return;
    }
 
    for(int i=1;i<=8;i++)
    {
        int k;
        for(k=0;k<n;k++)
        {
            if(path[k]==i||abs(path[k]-i)==abs(k-n))
                break;
        }
 
        if(k==n)
        {
            path[n]=i;
            dfs(n+1);
        }
 
    }
}
 
int main()
{
    int T,n;
    memset(path,0,sizeof(path));
    dfs(0);
 
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<8;i++)
        {
            cout<<res[n-1][i];
        }
        cout<<endl;
    }
    return 0;
}
