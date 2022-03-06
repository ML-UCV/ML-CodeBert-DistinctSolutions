#include <bits/stdc++.h>


using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int a, b, c;



int cmmdc(int a, int b)

{

  if(!b)

    return a;

  return cmmdc(b, a % b);

}



int main()

{

  f>>a>>b;

  c = cmmdc(a, b);

  if(c == 1)

    g<<0;

  else

    g<<c;

  return 0;

}
