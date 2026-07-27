#include <algorithm>
#include <iostream>

using namespace std;

const int N=1000010;
int p[N];

int bsearch_1(int l,int r,int target)
{
    while(l<r)
    {
        int mid=l+r>>1;
        if(p[mid]>=target)
            r=mid;
        else
            l=mid+1;
    }

    if(p[l]==target) return l;
    else
        return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,t,x;
    cin>>n;
    
    for(int i=0;i<n;i++)
        cin>>p[i];

    cin>>t;
    while(t--)
    {
        cin>>x;
        cout<<bsearch_1(0,n-1,x)<<endl;
    }

    return 0;
}