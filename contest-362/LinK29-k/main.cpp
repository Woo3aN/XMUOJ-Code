#include <algorithm>
#include <iostream>

using namespace std;

const int N=100010;
int q[N];

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    scanf("%d",&k);

    sort(q,q+n);

    for(int j=0;j<k;j++) cout<<q[n-j-1]<<endl;
    return 0;
}