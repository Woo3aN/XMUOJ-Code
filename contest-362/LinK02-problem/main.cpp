#include <iostream>
using namespace std;
 
int main()
{
   int a,b,c,d;
   int N;
   cin>>N;
   for(a=2;a<=N;a++)
   {
       int a3;
       a3=a*a*a;
       for(b=2;b<N;b++)
       {
           for(c=b;c<N;c++)
           {
               for(d=c;d<N;d++)
               {
                   if(a3==b*b*b+c*c*c+d*d*d)
                   {
                       cout<<"Cube = " <<a<<", "<<"Triple = "<<"("<<b<<","<<c<<","<<d<<")"<<endl;
                   }
               }
           }
       }
   }
   return 0;
}