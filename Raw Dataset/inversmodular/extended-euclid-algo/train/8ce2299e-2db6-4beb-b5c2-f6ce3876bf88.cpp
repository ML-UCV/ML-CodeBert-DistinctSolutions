#include <iostream>
#include <fstream>
using namespace std;

struct str{

int d;

int x0;

int y0;

};



str euclid(int a, int b){

    if(b==0)

            return {a, 1, 0};

    str d=euclid(b, a%b);

    return {d.d, d.y0, d.x0-(a/b) * d.y0};

}



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

int main()

{

    int a, n;

    f>>a>>n;

    str rez=euclid(a,n);

    rez.x0 %=n;

    while(rez.x0<0){

        rez.x0+=n;}

    g<<rez.x0;

    return 0;

}
