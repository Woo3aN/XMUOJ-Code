#include <cmath>
#include <iostream>
#include <string>
using namespace std;
double p()
{
    string str;
    cin>>str;
    switch(str[0])
    {
        case '+':
            return p() + p();
            break;
        case '-':
            return p() - p();
            break;
        case '*':
            return p() * p();
            break;
        case '/':
            return p() / p();
            break;
        default:
            return stof(str);
            break;
    }
}
int main() {
    printf("%lf",p());
    return 0;
}