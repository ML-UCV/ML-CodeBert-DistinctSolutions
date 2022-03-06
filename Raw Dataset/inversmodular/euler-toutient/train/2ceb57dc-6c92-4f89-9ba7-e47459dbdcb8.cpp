#include<bits/stdc++.h>
using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int euclid( int a, int b, int &x, int &y ){

    if( b == 0 ){

        x = 1;

        y = 0;

        return a;

    }else{

        int x0, y0;

        int cmmdc = euclid( b, a % b, x0, y0 );

        x = y0;

        y = x0 - y0 * (a / b);

        return cmmdc;

    }

}

int A, N;

int main(){

    fin >> A >> N;

    int invmod, aux;

    int d = euclid( A, N, invmod, aux );

    while( invmod < 0 )

        invmod += N;

    fout << invmod << endl;

    return 0;

}
