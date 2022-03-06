#include <bits/stdc++.h>
using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



int a, p;



void Euclid (int a, int b, int&d, int &x, int &y)

{

    if (b==0) d=a, x=1, y=0;

    else

    {

        int x0, y0;

        Euclid(b, a%b, d, x0, y0);

        x=y0;

        y=x0-(a/b)*y0;

    }

}



int InversMod(int a, int p)

{

    int d, x, y;

    Euclid(a, p, d, x, y);

    if (x<0) x+=p;

    return x;

}



int main()

{

    fin>>a>>p;

    fin.close();

    fout<<InversMod(a, p);

    fout.close();

    return 0;

}
