#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cmath>


using namespace std;



ifstream f("dmin.in");

ofstream g("dmin.out");



vector <pair <int, long double> > G[1505];

int Heap[1505], Poz[1505];

long long M[1505];

long double D[1505];

long double const tol = 1e-10;

int Heap_Size, n, m;

long long const oo = 1000000000, MOD = 104659;



void Read()

{

    int i, x, y;

    long double c;



    f>>n>>m;

    for(i=1; i<=m; i++){

        f>>x>>y>>c;

        c = log10(c);

        G[x].push_back(make_pair(y, c));

        G[y].push_back(make_pair(x, c));

    }

}



void Swap(int hx, int hy)

{

    swap(Heap[hx], Heap[hy]);

    swap(Poz[Heap[hx]], Poz[Heap[hy]]);

}



void UpHeap(int nod)

{

    int tata = nod/2;

    if(tata && D[Heap[tata]] > D[Heap[nod]]){

        Swap(tata, nod);

        UpHeap(tata);

    }

}



void DownHeap(int nod)

{

    int son = 2*nod;

    if(son + 1 <= Heap_Size && D[Heap[son+1]] < D[Heap[son]])

        son++;

    if(son <= Heap_Size && D[Heap[son]] < D[Heap[nod]]){

        Swap(son, nod);

        DownHeap(son);

    }

}



void Dijkstra()

{

    int i, nod, vecin;

    long double cost;

    vector <pair <int, long double> >::iterator it;



    for(i=1; i<=n; i++){

        D[i] = oo;

        Heap[++Heap_Size] = i;

        Poz[i] = Heap_Size;

    }



    D[1] = 0;

    M[1] = 1;

    UpHeap(Poz[1]);

    while(Heap_Size){

        nod = Heap[1];

        Swap(1, Heap_Size--);

        DownHeap(1);



        for(it = G[nod].begin(); it != G[nod].end(); it++){

            vecin = it -> first;

            cost = it -> second;

            if(D[vecin] - cost - D[nod] > tol){

                M[vecin] = M[nod];

                D[vecin] = D[nod] + cost;

                UpHeap(Poz[vecin]);

            }

            else

                if(abs(D[nod] + cost - D[vecin]) < tol)

                    M[vecin] = (M[vecin] + M[nod])%MOD;

        }

    }



    for(i=2; i<=n; i++)

        g<<M[i]<<" ";

    g<<"\n";

}



int main()

{

    Read();

    Dijkstra();

    return 0;

}
