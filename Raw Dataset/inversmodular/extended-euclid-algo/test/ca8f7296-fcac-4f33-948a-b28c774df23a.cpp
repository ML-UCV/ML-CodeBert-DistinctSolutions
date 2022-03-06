#include <bits/stdc++.h>


using namespace std;



ifstream f ("inversmodular.in");

ofstream g ("inversmodular.out");



int a,n,x,y;



void Euclid(int a, int b, int &x, int&y)

{

    if(b==0){x=1;y=0;}

    else{

        int x0,y0;

        Euclid(b,a%b,x0,y0);

        x=y0; y=x0-a/b*y0;

    }

}



int main()

{

    f>>a>>n;

    Euclid(n,a,x,y);

    while(y<0)y+=n;

    g<<y<<'\n';



    f.close(); g.close();

    return 0;

}
