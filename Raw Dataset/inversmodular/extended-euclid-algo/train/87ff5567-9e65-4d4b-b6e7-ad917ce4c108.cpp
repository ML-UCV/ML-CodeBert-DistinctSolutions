#include <bits/stdc++.h>

using namespace std;
long long int a,n;
ifstream in ("inversmodular.in");
ofstream out ("inversmodular.out");
void euclid(long long &x, long long &y, int a, int b)
{
     if (!b){
         x = 1;
         y = 0;
     }else
     {
         euclid(x, y, b, a % b);
         long long cx = x;
         x = y;
         y = cx - y * (a / b);
     }
}
int main()
{
    long long int x0,y0;
    in>>a>>n;
    euclid(x0,y0,a ,n);
    if(x0<=0){
        x0=n+x0%n;
    }
    out<<x0;
    return 0;
}
