#include <bits/stdc++.h>






long long A, N;



void Euclid(long long A, long long B, long long &X, long long &Y) {

    if (B == 0) {

        Y = 0;

        X = 1;

        return;

    } Euclid(B, A%B, X, Y);

    long long Aux = Y;

    Y = X - (A/B)*Y;

    X = Aux;

}



long long InvMod(long long A, long long MOD) {

    long long Temp, Inv;

    Euclid(A, MOD, Inv, Temp);

    return (Inv + MOD) % MOD;

}



std::ifstream In ("inversmodular.in");

std::ofstream Out("inversmodular.out");



void Citire() {

    In >> A >> N;

}



void Rezolvare() {

    Out << InvMod(A, N);

}



int main()

{

    Citire();

    Rezolvare();



    return 0;

}
