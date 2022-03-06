#include <bits/stdc++.h>


using namespace std;

ifstream in ("cmmdc.in");

ofstream out ("cmmdc.out");

int main()

{

    int a,b,r;

    in>>a>>b;

    while(b)

    {

        r=a%b;

        a=b;

        b=r;



    }

    if(a==1)

        a=0;

    out<<a;

    return 0;

}
