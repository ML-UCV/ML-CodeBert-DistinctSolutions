#include <bits/stdc++.h>
std::ifstream input (std::string("inversmodular")+".in");

std::ofstream output(std::string("inversmodular")+".out");



int gcd(long long A, long long B, long long &X, long long &Y) {

    if (B == 0) {

        X = 1;

        Y = 0;

        return A;

    } int v = gcd(B, A%B, X, Y);

    long long aux = Y;

    Y = X - (A/B)*Y;

    X = aux;

    return v;

}



int main()

{

    long long A, B; input >> A >> B;

    long long X, Y; gcd(A, B, X, Y);

    output << (X%B+B)%B;



    return 0;

}
