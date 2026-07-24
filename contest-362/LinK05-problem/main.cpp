#include <iostream>
#include <cstring>
using namespace std;
 
string Left[3];
string Right[3];
string result[3];
 
bool isfeitcoin(char icoin,bool islight)
{
    string c;
    c.push_back(icoin);
 
    for(int i=0;i<3;i++)
    {
        string l=Left[i],r=Right[i];
 
        if(!islight)
        swap(l,r);
 
        switch(result[i][0])
        {
            case 'e':
            if(l.find(c)!=string::npos||r.find(c)!=string::npos)
            return false;
            break;
 
            case 'u':
            if(r.find(c)==string::npos)
            return false;
            break;
 
            case 'd':
            if(l.find(c)==string::npos)
            return false;
            break;
        }
    }
 
    return true;
 
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<3;++i)
        cin>>Left[i]>>Right[i]>>result[i];
 
        for(char icoin='A';icoin<='L';icoin++)
        {
            if(isfeitcoin(icoin,true))
            {
                cout<<icoin<<" is the counterfeit coin and it is light."<<endl;
                break;
            }
            else if(isfeitcoin(icoin,false))
            {
                cout<<icoin<<" is the counterfeit coin and it is heavy."<<endl;
                break;
            }
        }
    }
 
    return 0;
}