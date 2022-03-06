#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;

ifstream in("schi.in");

ofstream out("schi.out");

const int NMax = 30000;



int N,V[NMax+5] ,AIB[NMax+5], Sol[NMax+5], sol = 1e9;



void Init(int Pos) {

    for (int i = Pos; i <= N; i += i&(-i))

        AIB[i]++;

}



void Update(int Pos) {

    for (int i = Pos; i <= N; i += i&(-i))

        AIB[i]--;

}



int Query(int Pos) {

    int Sum = 0;

    for (int i = Pos; i > 0; i -= i&(-i))

        Sum += AIB[i];

    return Sum;

}

void BinarySearch(int x, int low, int hi) {

    int m;

    if(low<=hi) {

        m=low + (hi-low)/2;

        int val = Query(m);

        if(val == x)

            if(m<sol)

            sol=m;

        if(x > val) BinarySearch(x,m+1,hi);

        else BinarySearch(x,low,m-1);

    }

}



void Solve() {

    for (int i = N; i >= 1; i--) {

        BinarySearch(V[i],1,N);

        Update(sol);

        Sol[sol] = i;

        sol = 1e9;

    }

}



int main() {

    in >> N;

    for(int i = 1; i <= N; i++)

        in >> V[i], Init(i);

    Solve();



    for (int i = 1; i <= N; i++)

        out << Sol[i] << '\n';

}
