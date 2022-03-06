#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



const int NMAX = 200005;

const int MMAX = 400005;



int N,M,Total;

int TT[NMAX],RG[NMAX];



pair < int, int > PP[MMAX];

int k;



struct Muchie{

    int x,y,Cost;

}V[MMAX];



bool Compare(Muchie a, Muchie b){

    return a.Cost < b.Cost;

}



void Read(){

    f >> N >> M;

    for(int i = 1; i <= M;i++)

        f >> V[i].x >> V[i].y >> V[i].Cost;



    sort (V + 1, V + M + 1, Compare);



    for(int i = 1; i <= N;i++){

        TT[i] = i;

        RG[i]= 1;

    }



}



int Find(int Nod){

    while(TT[Nod] != Nod)

        Nod = TT[Nod];

    return Nod;

}



void Unire(int x, int y){

    if(RG[x] < RG[y])

        TT[x] = y;

    if(RG[y] < RG[x])

        TT[y] = x;

    if(RG[x] == RG[y]){

        TT[x] = y;

        RG[y]++;

    }

}



void apm(){

    for(int i = 1; i <= M;i++){

        int Tx = Find(V[i].x);

        int Ty = Find(V[i].y);

        if(Tx!=Ty){

            Unire(Tx,Ty);

            PP[++k].first = V[i].x;

            PP[k].second = V[i].y;

            Total += V[i].Cost;

        }

    }

}



void afis(){

    g << Total << "\n";

    g << k << "\n";

    for(int i = 1; i<= k;i++)

        g << PP[i].first <<" " << PP[i].second << "\n";

}



int main()

{

    Read();

    apm();

    afis();

    return 0;

}
