#include <bits/stdc++.h>
using namespace std;

int a, b;

long long rez1, rez2;

void invers_modular(int a, int b, long long & alfa, long long & beta)

{

    if(b == 0)

    {

        alfa = 1;

        beta = 0;

        return;

    }

    long long fost_alfa, fost_beta;

    invers_modular(b, a % b, fost_alfa, fost_beta);

    alfa = fost_beta;

    beta = fost_alfa + (-a / b) * fost_beta;

}

int main()

{

    ifstream f("inversmodular.in");

    ofstream g("inversmodular.out");

    f >> a >> b;

    invers_modular(a, b, rez1, rez2);

    if(rez1 > 0)g << rez1;

    else g << rez1 + b;

    return 0;

}
