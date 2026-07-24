#include <iostream>
 
using namespace std;
 
const int mod=1000000007;
 
int N;
 
int stairs(int n)
{
    if(n<=1)
        return 1;
 
    return (stairs(n-1)+stairs(n-2))%mod;
}
 
int main()
{
    cin>>N;
    cout<<stairs(N)<<endl;
    return 0;
}