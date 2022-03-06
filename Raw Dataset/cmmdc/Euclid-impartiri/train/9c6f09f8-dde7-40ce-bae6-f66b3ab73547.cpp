#include <bits/stdc++.h>
using namespace std;



ifstream in("cmmdc.in");

ofstream out("cmmdc.out");



int cmmdc(int a, int b)

{

    int r=a%b;

    while(r)

    {

        a=b;

        b=r;

        r=a%b;

    }

    return b;

}



int main()

{

    int a,b;

    in>>a>>b;

    if(cmmdc(a,b)==1)

        out<<0;

    else

        out<<cmmdc(a,b);

    return 0;

}
