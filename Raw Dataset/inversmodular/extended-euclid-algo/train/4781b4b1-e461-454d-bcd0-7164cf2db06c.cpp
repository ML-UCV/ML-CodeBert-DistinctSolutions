#include <iostream>
#include <fstream>
using namespace std;

ifstream in("inversmodular.in");

ofstream out("inversmodular.out");

typedef long long ull;

ull mod,a,x,y,d;



int euclid_e(ull a, ull b, ull &x, ull &y, ull &d){

    if(b==0){

        x=1;

        d=a;

        y=0;

    }

    else{

        ull x0, y0;

        euclid_e(b,a%b,x0,y0,d);

        x=y0;

        y=x0-a/b*y0;

    }

}



int main()

{

    in>>a>>mod;

    euclid_e(mod,a,x,y,d);

    while(y<1) y+=mod;

    out<<y<<'\n';

    return 0;

}
