#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



vector < pair <int, double> > G[1505];

int N, NHeap, Heap[1505], Poz[1505], NPaths[1505];

double D[1505];



void Read ()

{

    freopen ("dmin.in", "r", stdin);

    int M;

    scanf ("%d %d", &N, &M);

    for (; M>0; --M)

    {

        int X, Y;

        double C;

        scanf ("%d %d %lf", &X, &Y, &C);

        C=log(C);

        G[X].push_back (make_pair (Y, C));

        G[Y].push_back (make_pair (X, C));

    }

}



void Print ()

{

    freopen ("dmin.out", "w", stdout);

    for (int i=2; i<=N; ++i)

    {

        printf ("%d ", NPaths[i]);

    }

    printf ("\n");

}



inline double Abs (double a)

{

    if (a>0)

    {

        return a;

    }

    return -a;

}



inline void Swap (int X, int Y)

{

    int Aux;

    Aux=Poz[Heap[X]];

    Poz[Heap[X]]=Poz[Heap[Y]];

    Poz[Heap[Y]]=Aux;

    Aux=Heap[X];

    Heap[X]=Heap[Y];

    Heap[Y]=Aux;

}



void Percolate (int X)

{

    int F=X>>1;

    if (F>0 and D[Heap[X]]<D[Heap[F]])

    {

        Swap (X, F);

        Percolate (F);

    }

}



void Sift (int X)

{

    int S=X<<1;

    if (S+1<=NHeap and D[Heap[S+1]]<D[Heap[S]])

    {

        ++S;

    }

    if (S<=NHeap and D[Heap[S]]<D[Heap[X]])

    {

        Swap (X, S);

        Sift (S);

    }

}



void Delete (int X)

{

    Swap (X, NHeap);

    Poz[Heap[NHeap]]=0;

    Heap[NHeap]=0;

    --NHeap;

    Sift (X);

}



void Initialize (int Start)

{

    for (int i=1; i<=N; ++i)

    {

        Heap[i]=Poz[i]=i;

        D[i]=2000000000;

    }

    NHeap=N;

    Swap (1, Start);

    D[Start]=0;

}



void Dijkstra (int Start)

{

    Initialize (1);

    while (NHeap>0)

    {

        int X=Heap[1];

        Delete (1);

        for (int i=0; i<G[X].size (); ++i)

        {

            int V=G[X][i].first;

            double C=G[X][i].second;

            if (Abs (D[V]-D[X]-C)<0.0000001)

            {

                NPaths[V]+=NPaths[X];

                NPaths[V]%=104659;

            }

            else

            {

                if (D[X]+C<D[V])

                {

                    D[V]=D[X]+C;

                    NPaths[V]=NPaths[X];

                    Percolate (Poz[V]);

                }

            }

        }

    }

}



int main()

{

    Read ();

    NPaths[1]=1;

    Dijkstra (1);

    Print ();

    return 0;

}
