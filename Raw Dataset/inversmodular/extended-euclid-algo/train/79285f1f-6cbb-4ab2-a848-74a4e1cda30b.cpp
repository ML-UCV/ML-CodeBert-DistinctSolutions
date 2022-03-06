#include <bits/stdc++.h>
using namespace std;

void cmmdc(int a,int b,int &x,int &y)

{

    if(!b)

    {

        x=1;

        y=0;

        return ;

    }

    int x0,y0;

    cmmdc(b,a%b,x0,y0);

    x=y0;

    y=x0-(a/b)*y0;

}

int main()

{

    int a,n,x,y;

    ifstream in("inversmodular.in");

    ofstream out("inversmodular.out");

    in>>a>>n;

    cmmdc(a,n,x,y);

    if(x<0)

        x=n-abs(x)%n;

    out<<x;



    return 0;

}
