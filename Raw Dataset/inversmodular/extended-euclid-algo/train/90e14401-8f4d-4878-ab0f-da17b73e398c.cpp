#include <bits/stdc++.h>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

int N,A,x,y;



void Euclid(int a,int b,int &x,int &y)

{

    if(b==0)

    {

        x=1;

        y=0;

        return;

    }

    else

    {

        int x0,y0;

        Euclid(b,a%b,x0,y0);

        x=y0;

        y=x0-(a/b)*y0;

    }

}



int main()

{

    f>>A>>N;

    Euclid(A,N,x,y);

    if(x<0) g<<x%N+N;

    else

    g<<x;

    return 0;

}
