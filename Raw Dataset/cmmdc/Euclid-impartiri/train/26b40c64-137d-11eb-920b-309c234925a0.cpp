#include <bits/stdc++.h>

using namespace std;

ifstream in("cmmdc.in");
ofstream out("cmmdc.out");

int a, b, r;

int main()
{
    in>>a>>b;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    if(a == 1)
        out<<0;
    else
        out<<a;
    return 0;
}
