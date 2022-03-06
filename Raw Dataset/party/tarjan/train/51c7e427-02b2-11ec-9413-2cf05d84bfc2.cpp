#include <bits/stdc++.h>
int N, M, X[1005], Y[1005],

    Colour[1005], Ans[105];



std::ifstream In ("party.in");

std::ofstream Out("party.out");



void Init() {

    srand(time(NULL));

}



void Citire() {

    In >> N >> M;

    for (int i=1; i<=M; ++i)

        In >> X[i] >> Y[i] >> Colour[i];

}



void Rezolvare() {

    bool check = true;

    while (check) {

        check = false;

        for (int i=1, val; i<=M; ++i) {

            val = (Ans[X[i]]<<1) + Ans[Y[i]];

            if (val == Colour[i]) {

                if (rand()&1) Ans[X[i]] = 1-Ans[X[i]];

                else Ans[Y[i]] = 1-Ans[Y[i]];



                check = true;

                i = M+5;

            }

        }

    }



    int Count = 0;

    for (int i=1; i<=N; ++i)

        Count += Ans[i];



    Out << Count << '\n';

    for (int i=1; i<=N; ++i)

        if (Ans[i])

            Out << i << '\n';

}



int main()

{

    Init();

    Citire();

    Rezolvare();



    return 0;

}
