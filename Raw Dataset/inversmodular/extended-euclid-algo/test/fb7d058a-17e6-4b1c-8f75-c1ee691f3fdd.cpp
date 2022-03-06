#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");







int A, N;



void Euclid(long long &x, long long &y, int a, int b)

{

    if(b == 0) {

        x = 1;

        y = 0;

    }

    else {

        Euclid(x, y, b, a % b);

        long long aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}



int main()

{

    fin.tie(NULL);

    fin >> A >> N;



    long long inv = 0, ins;

    Euclid(inv, ins, A, N);



    if(inv <= 0)

        inv = N + inv % N;



    fout << inv << "\n";

}
