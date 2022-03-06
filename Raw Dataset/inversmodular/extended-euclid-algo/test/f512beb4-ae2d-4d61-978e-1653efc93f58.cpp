#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int a, n, x, y;



void euclid(int a, int b, int &x, int &y)

{

    if(b==0)

    {

        x=1; y=0;

        return;

    }

    int x0, y0;

    euclid(b, a%b, x0, y0);

    x=y0;

    y=x0-(a/b)*y0;

}



int main()

{

    fin>>a>>n;

    euclid(a, n, x, y);

    if(x<=0) x=n+x%n;

    fout<<x<<"\n";

    return 0;

}
