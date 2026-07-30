#include <iostream>
using namespace std;

int main()
{
    double number;
    scanf("%lf",&number);
    double l=-10000,r=10000;
    while(r-l>=1e-8)
    {
        double mid=(r+l)/2;
        if(mid*mid*mid>=number)
            r=mid;
        else
            l=mid;
    }

    printf("%lf",l);
}