#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>


using namespace std;



ifstream in ("swap.in");

ofstream out ("swap.out");



const int MAXN = 50010;



int N;

char S1[MAXN], S2[MAXN];

int V[MAXN], AIB[MAXN];

vector <int> Ap1[30], Ap2[30];

int A1[30], A2[30];



inline int lsb (const int &x)

{

    return x & (-x);

}



inline void update (int poz)

{

    for ( ; poz <= N; poz += lsb (poz))

        AIB[poz] ++;

}



inline int query (int poz)

{

    int ret = 0;



    for ( ; poz; poz -= lsb (poz))

        ret += AIB[poz];



    return ret;

}



int main()

{

    int i, j, Ans = 0;



    in >> (S1 + 1) >> (S2 + 1);

    N = strlen (S1 + 1);



    for (i = 1; i <= N; i ++){

        Ap1[S1[i] - 'a'].push_back (i);

        Ap2[S2[i] - 'a'].push_back (i);

        ++ A1[S1[i] - 'a'];

        ++ A2[S2[i] - 'a'];

    }



    for (i = 0; i < 26; i ++)

        if (A1[i] != A2[i]){

            out << -1;



            return 0;

        }



    for (i = 0; i < 26; i ++)

        for (j = 0; j < (int) Ap1[i].size (); j ++)

            V[Ap1[i][j]] = Ap2[i][j];



    for (i = N; i; i --){

        Ans += query (V[i]);

        update (V[i]);

    }



    out << Ans;



    return 0;

}
