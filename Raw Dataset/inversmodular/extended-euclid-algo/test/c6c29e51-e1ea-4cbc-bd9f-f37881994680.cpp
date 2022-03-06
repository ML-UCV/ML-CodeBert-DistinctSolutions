#include <bits/stdc++.h>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

void euclid(int a, int b, int &x, int &y)

{

    if(b==0)

    {

        x=1;

        y=0;

    }

    else

    {

        int x1,y1;

        euclid(b,a%b,x1,y1);

        x=y1;

        y=x1-a/b*y1;

    }

}

int32_t main()

{

   int a,b,x=0,y=0;

   fin>>a>>b;

   euclid(a,b,x,y);

   while(x<0)

    x+=b;

   fout<<x;

}
