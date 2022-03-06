#include <bits/stdc++.h>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



void Euclid(int a,int b,int &x,int &y)

{

     if(b==0)

     {

         x=1;

         y=0;

         return;

     }

     int x0,y0;

     Euclid(b,a%b,x0,y0);

     x=y0;

     y=x0-(a/b)*y0;

}



int main()

{

    int N,A,X,Y;

    f>>A>>N;



    Euclid(A,N,X,Y);

    X=X%N;

    if(X<0) X=N+X;

    g<<X;



    return 0;

}
