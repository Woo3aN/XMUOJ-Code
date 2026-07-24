#include <iostream>
using namespace std;

void move(char start,char target)
{
    cout<<start<<"->"<<target<<endl;
    return;
}

void hanoi(int n,char start,char other,char target)
{
    if(n==1)
    {
        move(start,target);
        return;
    }

    hanoi(n-1,start,target,other);
    move(start,target);
    hanoi(n-1,other,start,target);
    return;
}

int main()
{
    int n;
    cin>>n;
    hanoi(n,'A','B','C');
    return 0;
}