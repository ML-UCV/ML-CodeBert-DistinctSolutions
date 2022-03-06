#include <iostream>
#include <fstream>
using namespace std;





ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int n, m, k, l;



void invers_mod(int a, int b, int &k, int &l)

{

    if (!b)

    {

        k=1;

        l=0;

        return;

    }

    int kp, lp;

    invers_mod(b,a%b,kp,lp);

    k=lp;

    l=kp-lp*(a/b);

}



int main()

{

    f >> n >> m;

    invers_mod(n,m,k, l);

    while (k<0)

        k+=m;

    g << k;

    return 0;

}
