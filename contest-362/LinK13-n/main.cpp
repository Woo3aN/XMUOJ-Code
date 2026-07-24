#include <iostream>
#include <vector>
using namespace std;
 
int N;
 
vector<int> res;
 
void dfs(int n)
{
    if(n==N)
    {
        for(auto x:res)cout<<x;
        cout<<endl;
        return;
    }
 
    for(int i=1;i<=N;i++)
    {
        int k;
        for(k=0;k<n;k++)
        {
            if(res[k]==i||abs(res[k]-i)==abs(k-n))
                break;
        }
        if(k==n)
        {
            res[n]=i;
            dfs(n+1);
        }
    }
}
 
int main()
{
    cin>>N;
    res.resize(N);
    dfs(0);
    return 0;
}