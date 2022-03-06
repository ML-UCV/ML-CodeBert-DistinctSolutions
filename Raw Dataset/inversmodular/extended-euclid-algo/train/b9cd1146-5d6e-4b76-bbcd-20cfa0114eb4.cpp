#include <bits/stdc++.h>


using namespace std;



int a, n, k, L;



void euclid(int a, int n, int &k, int &L)

{

    if (n==0){

        k=0;

        L=1;

        return;

    }

    int k1, l1;

    euclid(n, a%n, k1, l1);

    L = k1;

    k = l1 - (a/n) * k1;

}



int main()

{

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");

    fin>>a>>n;

    euclid(a, n, k, L);

    while (L < 0){

        L+=n;

    }

    fout<<L;

    return 0;

}
