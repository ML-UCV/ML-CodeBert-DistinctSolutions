#include <iostream>
#include <fstream>


using namespace std;



ifstream fin ("apm.in");

ofstream fout ("apm.out");



const int INFINIT = 400000000;

const int MAX_HEAP_SIZE=200001;

typedef int heap[MAX_HEAP_SIZE];



heap h;



struct nod

{

    int info, cost, sursa;

    nod * urm;

}*vecin[200001];



nod * prim[200001];

nod * ultim[200001];

int v[200001], p[200001];



struct nod2

{

    nod * info;

    nod2 * urm;

};



inline int father (int x)

{

    return x/2;

}



inline int left_son (int x)

{

    return x*2;

}



inline int right_son(int x)

{

    return x*2 + 1;

}



void sift(heap h, int n, int k)

{

    int son;

    do

    {

        son=0;



        if(left_son(k)<=n)

        {

            son=left_son(k);



            if(right_son(k)<=n && v[ h[right_son(k)] ] < v[ h[son] ] )

            {

                son=right_son(k);

            }



            if(v[ h[k] ] <= v[ h[son] ])

            {

                son=0;

            }

        }



        if(son)

        {

            swap(p[ h[k] ], p[ h[son] ]);

            swap(h[k], h[son]);

            k=son;

        }



    }while(son);

}



void percolate (heap h, int n, int k)

{

    int key=h[k];



    while(k>1 && v[key] < v[ h[father(k)] ])

    {

        p[ h[father(k)] ]=k;

        h[k]=h[father(k)];

        k=father(k);

    }



    p[key]=k;

    h[k]=key;

}



int main()

{

    int n, m, i, a, b, c, l;

    fin>>n>>m;



    for(i=1; i<=m; i++)

    {

        fin>>a>>b>>c;





        nod * aux1= new nod;

        aux1->info=b;

        aux1->cost=c;

        aux1->sursa=a;

        aux1->urm=NULL;



        if(prim[a]==NULL)

        {

            prim[a]=aux1;

            vecin[a]=aux1;

        }



        else

        {

            vecin[a]->urm=aux1;

            vecin[a]=aux1;

        }



        nod * aux2 = new nod;

        aux2->info=a;

        aux2->cost=c;

        aux2->sursa=b;

        aux2->urm=NULL;



        if(prim[b]==NULL)

        {

            prim[b]=aux2;

            vecin[b]=aux2;

        }



        else

        {

            vecin[b]->urm=aux2;

            vecin[b]=aux2;

        }

    }





    l=n-1;

    for(i=2; i<=n; i++)

    {

        v[i]=INFINIT;

        h[i-1]=i;

        p[i]=i-1;

    }



    v[1]=0;

    p[1]=n;

    nod * t = prim[1];



    while(t!=NULL)

    {

        v[t->info] = t->cost;

        percolate(h, l, p[t->info]);

        ultim[t->info] = t;



        t=t->urm;

    }



    nod * prim_lista = NULL;

    nod * lista = NULL;



    for(i=1; i<n; i++)

    {

        int x=h[1];



        swap(p[ h[1] ], p[ h[l] ]);

        swap(h[1], h[l]);

        l--;



        sift(h, l, 1);



        nod * afis = new nod;

        afis->urm=NULL;

        afis->info = ultim[x]->sursa;

        afis->sursa= ultim[x]->info;

        afis->cost=ultim[x]->cost;



        if(prim_lista==NULL)

        {

            prim_lista=afis;

            lista=afis;

        }

        else

        {

            lista->urm=afis;

            lista=afis;

        }



        nod * t = prim[x];



        while(t!=NULL)

        {

            if(p[t->info]<=l && t->cost < v[t->info])

            {

                v[t->info] = t->cost;

                percolate(h, l, p[t->info]);

                ultim[t->info] = t;

            }



            t=t->urm;

        }

    }



    nod * aux3= prim_lista;

    int suma=0;



    while(aux3!=NULL)

    {

        suma=suma+aux3->cost;

        aux3=aux3->urm;

    }



    fout<<suma<<"\n"<<n-1<<"\n";



    aux3=prim_lista;

    while(aux3!=NULL)

    {

        fout<<aux3->info<<' '<<aux3->sursa<<"\n";

        aux3=aux3->urm;

    }







}
