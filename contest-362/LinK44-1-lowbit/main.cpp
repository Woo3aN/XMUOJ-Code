#include <iostream>
 
using namespace std;
 
#define N 17
 
int log[1<<N];
 
void BuildLogTable(int n)
{
    for(int i=0;i<n;i++)
    {
        log[1<<i]=i;
    }
}
 
inline int lowbit(int n)
{
    return n&-n;
}
int main()
{
    BuildLogTable(N);
    int n;
    cin>>n;
    cout<<log[lowbit(n)];
    return 0;
}