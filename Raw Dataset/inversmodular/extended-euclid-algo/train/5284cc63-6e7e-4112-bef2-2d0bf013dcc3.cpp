#include <bits/stdc++.h>






namespace maths {

    void euclid(long long A, long long B, long long &X, long long &Y) {

        if (B == 0) {

            Y = 0, X = 1;

            return;

        } euclid(B, A%B, X, Y);

        long long aux = Y; Y = X - (A/B)*Y; X = aux;

    }



    long long invmod(long long A, long long MOD) {

        long long temp, inv;

        euclid(A, MOD, inv, temp);

        return (inv+MOD)%MOD;

    }

}



long long A, N;



std::ifstream input ("inversmodular.in");

std::ofstream output("inversmodular.out");



void readInput() {

    input >> A >> N;

}



void solveInput() {

    output << maths::invmod(A, N);

}



int main()

{

    readInput();

    solveInput();



    return 0;

}
