#include <bits/stdc++.h>






std::ifstream InFile("schi.in");

std::ofstream OutFile("schi.out");



int N;

int Tree[30005];

int Loc[30005];

int Ans[30005];



int Sum(int Index) {

    int S = 0;

    while (Index) {

        S += Tree[Index];

        Index -= Index&(-Index);

    } return S;

}



void Add(int Index, int Value) {

    while (Index<=N) {

        Tree[Index] += Value;

        Index += Index&(-Index);

    }

}



int Query(int Index) {

    int Rez;

    int Left = 1, Right = N, Middle;

    while (Left <= Right) {

        Middle = (Left+Right)/2;

        if(Loc[Index] <= Sum(Middle)) {

            Right = Middle-1;

            Rez = Middle;

        }

        else Left = Middle+1;

    } return Rez;

}



void Citire() {

    InFile >> N;

    for (int i=0; i<N; i++)

        InFile >> Loc[i+1],

        Add(i+1, 1);

}

void Rezolvare() {

    for (int i=N; i>0; i--) {

        int Index = Query(i);

        Ans[Index] = i;

        Add(Index, -1);

    }



    for (int i=0; i<N; i++)

        OutFile << Ans[i+1] << '\n';

}



int main()

{

    Citire();

    Rezolvare();



    return 0;

}
