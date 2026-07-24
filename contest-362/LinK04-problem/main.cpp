#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,value;
        cin>>N;
        vector<int> numbers;
        for(int i=0;i<N;++i)
        {
            cin>>value;
            numbers.push_back(value);
        }
        sort(numbers.begin(),numbers.end());
        for(int i=0;i<N;++i)
        {
            if(i>0)
            cout<<" ";
            cout<<numbers[i];
        }
        cout<<endl;
    }
    return 0;
}