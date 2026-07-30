#include <iostream>
#include <cmath>

using namespace std;

#define EPS 1e-6
#define spacesize 4

double inputnumber[spacesize + 1];

bool isZero(double x)
{
    return fabs(x)<=EPS;
}

bool count24(double a[],int n)
{
    if (n==1)
    {
        if(isZero(a[0]-24))
            return true;
        else
            return false;
    }

    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            double temp[n-1]={0};
            int iTemp=0;
            for (int k=0;k<n;k++)
            {
                if((k!=i)&&(k!=j))
                    temp[iTemp++]=a[k];
            }

            temp[iTemp]=a[i]+a[j];
            if (count24(temp,n - 1)) return true;

            temp[iTemp]=a[i]*a[j];
            if (count24(temp,n - 1)) return true;

            temp[iTemp]=a[i]-a[j];
            if (count24(temp,n - 1)) return true;

            temp[iTemp]=a[j]-a[i];
            if (count24(temp,n - 1)) return true;

            if (!isZero(a[j]))
            {
                temp[iTemp]=a[i]/a[j];
                if (count24(temp,n - 1)) return true;
            }

            if (!isZero(a[i]))
            {
                temp[iTemp]=a[j]/a[i];
                if (count24(temp,n - 1)) return true;
            }
        }
    }
    return false;
}

int main() {
    while(true)
    {
        bool isEndInput=true;
        for (int i=0;i<spacesize;i++)
        {
            cin>>inputnumber[i];
            if (!isZero(inputnumber[i]))
                isEndInput=false;
        }
        if (isEndInput) break;

        if (count24(inputnumber,spacesize))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
