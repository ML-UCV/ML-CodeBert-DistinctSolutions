#include <iostream>

using namespace std;

int main()
{
    freopen ("cmmdc.in","r",stdin);
    freopen ("cmmdc.out","w",stdout);
    int a, b, rest;
    cin >> a >> b;
    while(b != 0){
       rest = a % b ;
       a = b;
       b = rest;
       }
       if (a == 1)
           a = 0;
       cout << a;
 return 0;
}
