#include <iostream>
#include <fstream>
using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



long long A, N;



void gcd(long long &x, long long &y, int a, int b)

{

    if(b == 0){

        x = 1;

        y = 0;

    }

    else

    {

        gcd(x,y,b,a%b);

        long long aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}



int main()

{

    long long inv, ins;

    fin >> A >> N;

    gcd(inv,ins,A,N);

    if(inv <= 0){

        inv = N + inv % N;

    }

    fout << inv << "\n";

    return 0;

}
