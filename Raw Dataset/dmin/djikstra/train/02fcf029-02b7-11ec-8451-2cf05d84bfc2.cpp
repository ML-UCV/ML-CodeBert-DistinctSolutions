#include <bits/stdc++.h>
using namespace std;

ifstream f("dmin.in");

ofstream g("dmin.out");

struct Nod{

    int nod;

    double val;

};





int heap[50004];

int n;

int getMin()

{

    return heap[1];

}

double cost[10000];

void add(int x)

{



    n++;

    int poz=n;

    heap[n]=x;

    while(poz>1 && cost[heap[poz/2]]>cost[heap[poz]])

    {

        swap(heap[poz/2], heap[poz]);

        poz/=2;

    }

}

void popMin()

{



    heap[1]=heap[n];

    heap[n]=0;

    int poz=1;

    n--;

    while(2*poz<=n)

    {

        poz*=2;

        if(poz<n && cost[heap[poz]]>cost[heap[poz+1]]) poz++;

        if(cost[heap[poz]] < cost[heap[poz/2]])

            swap(heap[poz/2], heap[poz]);

        else poz=n;

    }

}
int mod=104659;

vector<Nod> muchii[100000];



int mn[10000];

int viz[10000];

int pct, much;

int main()

{

    f>>pct>>much;

    for(int i=1;i<=much;++i)

    {

        int a,b;

        double x,c;

        f>>a>>b>>c;



        x=log(c);

        muchii[a].push_back({b,x});

        muchii[b].push_back({a,x});

    }

    for(int i=2;i<=pct;++i)

    {

        cost[i]=1e9;

    }

    int elem;

    add(1);

    cost[1]=0;

    viz[1]=1;

    mn[1]=1;



    while(n>0)

    {

         elem=getMin();

         popMin();

        viz[elem]=0;

         for(int i=0;i<muchii[elem].size();++i)

         {

             Nod vecin=muchii[elem].at(i);



                if(cost[vecin.nod]-vecin.val-cost[elem]>1e-8)

                {

                    mn[vecin.nod]=mn[elem]%mod;

                    cost[vecin.nod]=cost[elem]+vecin.val;



                    if(viz[vecin.nod]==0)

                    {

                        viz[vecin.nod]=1;

                        add(vecin.nod);

                    }

                }

                else {

                    if(abs(vecin.val+cost[elem]-cost[vecin.nod])<1e-8)

                    {

                        mn[vecin.nod]+=mn[elem];

                        mn[vecin.nod]%=mod;

                    }

                }



         }

    }

    for(int i=2;i<=pct;++i)

    {

        g<<mn[i]<<" ";

    }

    return 0;

}
