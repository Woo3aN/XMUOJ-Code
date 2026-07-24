#include <iostream>
using namespace std;
 
int f(int x,int y)
{
    if(x<y)
    return f(x,x);
 
    if(x==0)
    return 1;
 
    if(y<=0)
    return 0;
 
    return f(x,y-1)+f(x-y,y);
}
int main()
{
    int t,x,y;
    cin>>t;
 
    while(t--)
    {
        cin>>x>>y;
        cout<<f(x,y)<<endl;
    }
    return 0;
}