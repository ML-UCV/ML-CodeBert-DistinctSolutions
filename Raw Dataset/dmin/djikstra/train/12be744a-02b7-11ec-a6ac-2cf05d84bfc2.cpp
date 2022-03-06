#include <fstream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

ifstream fin("dmin.in");

ofstream fout("dmin.out");

int N,M,H[1505],HPOZ[1505],NRD[1505],Hdim;

double D[1505];

vector < pair <int,double> > G[1505];

void read()

{

    int i,a,b;

    double c;

    fin>>N>>M;

    for(i=1;i<=M;i++)

    {

        fin>>a>>b>>c;

        c=log(c);

        G[a].push_back(make_pair(b,c));

        G[b].push_back(make_pair(a,c));

    }

}

void up(int k)

{

    while(k/2 && D[H[k]] < D[H[k/2]])

    {

        swap(H[k],H[k/2]);

        swap(HPOZ[H[k]],HPOZ[H[k/2]]);

        k/=2;

    }

}

void down(int k)

{

    int kp;

    while(2*k<=Hdim)

    {

        kp=2*k;

        if(kp+1<=Hdim && D[H[kp]] > D[H[kp+1]])

            kp++;

        if(D[H[k]] > D[H[kp]])

        {

            swap(H[k],H[kp]);

            swap(HPOZ[H[k]],HPOZ[H[kp]]);

            k=kp;

        }

        else

            break;

    }

}

int heap_extract()

{

    int x=H[1];

    HPOZ[H[1]]=0;

    H[1]=H[Hdim];

    HPOZ[H[1]]=1;

    Hdim--;

    down(1);

    return x;

}

void heap_insert(int nod)

{

    H[++Hdim]=nod;

    HPOZ[nod]=Hdim;

    up(Hdim);

}

void dijkstra()

{

    int i,x,nod;

    double cost;

    for(i=2;i<=N;i++)

        D[i]=INT_MAX;

    H[1]=1;

    HPOZ[1]=1;

    Hdim=1;

    NRD[1]=1;

    while(Hdim)

    {

        x=heap_extract();

        for(size_t j=0;j<G[x].size();j++)

        {

            nod=G[x][j].first;

            cost=G[x][j].second;

            if(D[nod] > D[x]+cost+0.0000000001)

            {

                D[nod] = D[x]+cost;

                NRD[nod] = NRD[x];

                if(HPOZ[nod]==0)

                    heap_insert(nod);

                else

                    up(HPOZ[nod]);

            }

            else if(max(D[nod] - (D[x]+cost),-(D[nod] - (D[x]+cost))) <= 0.0000000001)

            {

                NRD[nod] = (NRD[nod]+NRD[x])%104659;

                if(HPOZ[nod]==0)

                    heap_insert(nod);

            }

        }

    }

}

void print()

{

    for(int i=2;i<=N;i++)

        fout<<NRD[i]<<' ';

}

int main()

{

    read();

    dijkstra();

    print();

    return 0;

}
