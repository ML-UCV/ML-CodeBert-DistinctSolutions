#include <iostream>
#include <fstream>


using namespace std;



void euclid(int a, int b, int c, int &x, int &y)

{



    int q[50],r,x0,y0,pas=0;

    while(b)

    {

        r=a%b;

        q[++pas]=a/b;

        a=b;

        b=r;

    }

    if(c%a)

    {

        x=y=0;

        return;

    }

    x=x0=c/a;

    y=y0=0;

    while(pas)

    {

        x=y0;

        y=x0-q[pas--]*y0;

        x0=x;

        y0=y;

    }

}



int main()

{

    ifstream fin("inversmodular.in");



ofstream fout("inversmodular.out");

    int a,x,y,b;

    fin>>a>>b;

    euclid(a,b,1,x,y);

    x=((long long)b+x%b)%b;

    fout<<x;

    return 0;

}
