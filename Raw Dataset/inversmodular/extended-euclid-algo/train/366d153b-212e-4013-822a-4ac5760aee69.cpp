#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

void euclid( long long a, long long b, long long &d, long long &x, long long &y)

{

    if(!b)

    {

        d = a;

        x = 1;

        y = 0;

    }

    else

    {

        long long x_u, y_u;

        euclid(b,a%b,d, x_u, y_u);

        x=y_u;

        y=x_u- a/b*y_u;

    }

}

int main()

{

   long long n;



       long long a, b, c;

       fin >> a >> b;

       long long x,y,d;

       euclid(a, b, d, x, y);

       if(x<=0)x=b+x%b;

       fout<<x;



    return 0;

}
