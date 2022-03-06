#include <bits/stdc++.h>
int N, M;

int AIB[100005];



int Ind[100005];

std::pair <int, int> V[100005];



void Update(int X, int Value) {

    for (X; X<=N; X += X&(-X))

        AIB[X] += Value,

        AIB[X] %= 9917;

}



int Query(int X) {

    int Sum = 0;

    for (X; X; X -= X&(-X))

        Sum += AIB[X],

        Sum %= 9917;

    return Sum;

}



std::ifstream In("inv.in");

std::ofstream Out("inv.out");



void Citire() {

    In >> N;

    for (int i=0; i<N; ++i)

        In >> V[i+1].first,

        V[i+1].second = i+1;

}



void Rezolvare() {

    std::sort (V+1, V+N+1);

    for (int i=1; i<=N; ++i)

        Ind[V[i].second] = i;



    int NInv = 0;



    for (int i=0, X; i<N; ++i) {

        NInv += Query(N) - Query(Ind[i+1]);

        while (NInv < 0) NInv += 9917;

        NInv %= 9917;

        Update(Ind[i+1], 1);

    } Out << NInv << '\n';

}



int main()

{

    Citire();

    Rezolvare();



    return 0;

}
