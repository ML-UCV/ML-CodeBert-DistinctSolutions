#include <bits/stdc++.h>
using namespace std;

int main()

{

    ifstream cin("inversmodular.in");

    ofstream cout("inversmodular.out");

    int y0,y,y1,aux,b,a,c,r;

    y0=0;y1=1;cin>>a>>b;

    aux=b;

    while(a!=0){

        r=b%a;

        c=b/a;

        b=a;

        a=r;

        y=y0-c*y1;

        y0=y1;

        y1=y;

    }

    while(y0<0)

        y0+=aux;

    cout<<y0;

}
