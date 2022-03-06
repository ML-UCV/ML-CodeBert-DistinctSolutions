#include<bits/stdc++.h>


using namespace std;



ifstream f ("inversmodular.in");

ofstream g("inversmodular.out");



int a, n;



void euc(int a, int b, int &x, int &y)

{

  if (!b)

  {

    x=1;

    y=0;

    return;

  }

  euc(b,a%b,x,y);

  int y0=y;

  y=x-(a/b)*y;

  x=y0;

}





int main()

{

  f>>a>>n;

  int x, y;

  euc(a,n,x,y);

  if (x<0)

      x+=n;

  g<<x;

}
