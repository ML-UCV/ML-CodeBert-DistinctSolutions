#include <bits/stdc++.h>


using namespace std;

ifstream fi("cmmdc.in");

ofstream ge("cmmdc.out");



bool primalitate(int x, int y)

{

  int r;

  while(y)

  {

      r=x%y;

      x=y;

      y=r;

  }

  if(x==1) return true;

  else return false;



}



int a,b;

int main()

{



    fi>>a>>b;

    while(a!=b)

    {

        if(a>b)

            a=a-b;

        else

            b=b-a;

    }

    if(primalitate(a,b)==true) ge<<0;

    else ge<<a;

    fi.close();

    ge.close();

    return 0;

}
