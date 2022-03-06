#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");



struct muchii

{

    int st, dr, cost;

};



const int NMAX = 400001;



int n, m, T[NMAX], rad;

muchii M[NMAX], sol[NMAX];



bool cmp(muchii a, muchii b)

{

    return a.cost<b.cost;

}



void citire()

{

    f >> n >> m;

    for(int i = 0; i < m; i++)

        f >> M[i].st >> M[i].dr >> M[i].cost;

}



int Rad(int i)

{

    if(T[i]==i)

        return i;

    return T[i] = Rad(T[i]);

}



int main()

{

    citire();



    sort(M, M + m, cmp);



    for(int i = 1; i <= n; i++)

        T[i] = i;



    int S = 0, nr = 0;

    for(int i = 0; i < m; i++)

        if(Rad(M[i].st) != Rad(M[i].dr))

        {

            T[Rad(M[i].dr)] = M[i].st;

            S += M[i].cost;



            sol[++nr].st = M[i].st;

            sol[nr].dr = M[i].dr;

        }



    g << S << '\n' << nr << '\n';

    for(int i = 1; i <= nr; i++)

        g << sol[i].st << ' ' << sol[i].dr << '\n';



    return 0;

}
