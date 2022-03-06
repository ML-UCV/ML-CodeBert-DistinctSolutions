#include <iostream>
#include <fstream>
#include <queue>
#include <vector>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct road {

    int nod1, nod2, cost;

    inline bool operator < (const road &other) const

    {

        return cost > other.cost;

    }

};



struct {

    int nod1, nod2;

}muchii[200005];





int nr_muchii, nr_noduri, total, f;

priority_queue <road> heap;

int root[200005], depth[200005];



void citire()

{

    fin>>nr_noduri>>nr_muchii;

    for(int i=1; i<=nr_muchii; i++)

    {

        road muchie;

        fin>>muchie.nod1>>muchie.nod2>>muchie.cost;

        heap.push(muchie);

    }

}



void join(int n, int m)

{

    if(depth[n] > depth[m])

    {

        root[m]=n;

    }

    if(depth[n] < depth[m])

    {

        root[n]=m;

    }

    if(depth[n] == depth[m])

    {

        root[m]=n;

        depth[n]++;

    }

}



int findRoot(int n)

{

    if(root[n]==0)

        return n;

    else

        return findRoot(root[n]);

}



void apm_kruskal()

{

    while(!heap.empty())

    {

        road curent=heap.top();

        heap.pop();

        int r1, r2;

        r1=findRoot(curent.nod1);

        r2=findRoot(curent.nod2);

        if(r1!=r2)

        {

            join(r1, r2);

            total+=curent.cost;

            f++;

            muchii[f].nod1=curent.nod1;

            muchii[f].nod2=curent.nod2;

        }

    }



}



void afisare()

{

    fout<<total<<'\n';

    fout<<nr_noduri-1<<'\n';

    for(int i=1; i<nr_noduri; i++)

    {

        fout<<muchii[i].nod1<<' '<<muchii[i].nod2<<'\n';

    }

}



int main()

{

    citire();

    apm_kruskal();

    afisare();

    return 0;

}
