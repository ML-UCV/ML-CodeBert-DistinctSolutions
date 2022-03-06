#include <bits/stdc++.h>


using namespace std;



void extins(int a, int b, int &d, int &x, int &y){

    if(b == 0){

        d = a;

        x = 1;

        y = 0;

    }

    else{

        int x0 = 0, y0 = 0;

        extins(b, a % b, d, x0, y0);

        x = y0;

        y = x0 - y0 * (a / b);

    }

}



int main()

{

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");

    int n, a;

    fin >> a >> n;

    int x = 0, y = 0, d = 0;

    extins(a, n, d, x, y);

    if(x < 0)

        x = (x + n) % n;

    fout << x;

    return 0;

}
