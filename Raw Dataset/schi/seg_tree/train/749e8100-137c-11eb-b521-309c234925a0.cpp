#include <fstream>
#include <cmath>
#include <iostream>


using namespace std;

ifstream fin;
ofstream fout;

int Arb[4 * 30005 + 5], rez[30005], sol, v[30005];

void Update(int st, int dr, int poz, int nod){
    if(st == dr){
        Arb[nod] = 0;
        return;
    }

    int mij = (st + dr) / 2;
    if(poz <= mij)
        Update(st, mij, poz, 2 * nod);
    else Update(mij + 1, dr, poz, 2 * nod + 1);

    Arb[nod] = Arb[2 * nod] + Arb[2 * nod + 1];
}

void Query(int st, int dr, int nod, int val){
    if(st == dr){
        sol = st;
        return;
    }

    int mij = (st + dr) / 2;
    if(Arb[2 * nod] < val)
        Query(mij + 1, dr, 2 * nod + 1, val - Arb[2 * nod]);
    else Query(st, mij, 2 * nod, val);
}

int main()
{
    fin.open("schi.in");

    int n;
    fin >> n;

    int N;
    for (N=1; N<=n; N <<= 1);


    for(int i = 1; i <= n; ++i){
        fin >> v[i];
        Arb[N + i - 1] = 1;
    }
    fin.close();

    for(int i = N - 1; i >= 1; --i)
        Arb[i] = Arb[2 * i] + Arb[2 * i + 1];

    for(int i = n; i >= 1; --i){
        Query(1, N, 1, v[i]);
        int poz = sol;
        rez[poz] = i;
        Update(1, N, poz, 1);
    }

    fout.open("schi.out");
    for(int i = 1; i <= n; ++i)
        fout << rez[i] << '\n';
    fout.close();

    return 0;
}
