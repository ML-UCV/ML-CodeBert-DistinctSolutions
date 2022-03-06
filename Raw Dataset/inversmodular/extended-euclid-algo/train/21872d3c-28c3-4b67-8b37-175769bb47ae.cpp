#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

ifstream in("inversmodular.in");
ofstream out("inversmodular.out");



long long int egcd(long long int a, long long int b, long long int *x, long long int *y)
{
    if(b ==0)
    {
        *x=1;
        *y=0;
        return a;
    }
    long long int x0,y0,d;
    d = egcd(b,a%b,&x0,&y0);
    *x = y0;
    *y = x0 - (a/b)*y0;

    return d;

}

int main ( )
{
   long long int a,n,x,y,d;

    in>>a>>n;
    d = egcd(a,n,&x,&y);

    while(x<0) x+=n;
    out<<x;

    return 0;
}
