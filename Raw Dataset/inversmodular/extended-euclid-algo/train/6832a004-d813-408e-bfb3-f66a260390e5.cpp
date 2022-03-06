#include <bits/stdc++.h>
long long A,N;

using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void P(long long &x,long long &y, int a, int b)

{

     if(b==0) x=1,y=0;

     else

     {

         P(x,y,b,a%b);

         long long o=x;

         x=y;

         y=o-y*(a/b);

     }

}



int main()

{

    long long i=0,j;

    fin>>A>>N;

    P(i,j,A,N);

    if (i<=0)

       i=N+i%N;

    fout<<i;

    return 0;

}
