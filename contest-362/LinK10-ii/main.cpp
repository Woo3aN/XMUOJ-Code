#include <iostream>
 
using namespace std;
 
void move(int id,char start,char target)
{
    cout<<id<<":"<<start<<"->"<<target<<endl;
    return;
}
 
void hanoi(int n,int id,char start,char other,char target)
{
    if(n==1)
    {
        move(id,start,target);
        return;
    }
 
    hanoi(n-1,id,start,target,other);
    int newid=id+n-1;
    move(newid,start,target);
    hanoi(n-1,id,other,start,target);
    return;
}
 
int main()
{
    char a,b,c;
    int n;
    cin>>n>>a>>b>>c;
    hanoi(n,1,a,b,c);
}