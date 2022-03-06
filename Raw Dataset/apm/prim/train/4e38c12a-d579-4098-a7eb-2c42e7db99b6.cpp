#include <iostream>
#include <fstream>
#include <vector>
#include <queue>




using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct mucie {

    int nod1, nod2;

} muchii[200005];



struct node {

    int nod, cost;

};



struct heapNode {

    int nod_init, nod_fin, cost;

    inline bool operator < (const heapNode &other) const

    {

        return cost > other.cost;

    }

};



int nr_noduri, nr_muchii, total, nr_bagate;

vector <node> G[200005];

priority_queue <heapNode> heap;

bool isIn[200005];



void citire()

{

    fin>>nr_noduri>>nr_muchii;

    for(int i=1; i<=nr_muchii; i++)

    {

        node nod1, nod2;

        fin>>nod1.nod>>nod2.nod>>nod1.cost;

        nod2.cost=nod1.cost;

        G[nod1.nod].push_back(nod2);

        G[nod2.nod].push_back(nod1);

    }

}



void apm_prim()

{

    isIn[1]=true;

    for(int i=0; i<G[1].size(); i++)

    {

        heapNode initial;

        initial.nod_init=1;

        initial.nod_fin=G[1][i].nod;

        initial.cost=G[1][i].cost;

        heap.push(initial);

    }

    nr_bagate++;

    while(nr_bagate!=nr_noduri)

    {

        heapNode curent=heap.top();

        heap.pop();

        if(isIn[curent.nod_fin]==false)

        {

            isIn[curent.nod_fin]=true;

            muchii[nr_bagate].nod1=curent.nod_init;

            muchii[nr_bagate].nod2=curent.nod_fin;

            total+=curent.cost;

            nr_bagate++;

            for(int i=0; i<G[curent.nod_fin].size(); i++)

            {

                if(isIn[G[curent.nod_fin][i].nod]==false)

                {

                    heapNode vecin;

                    vecin.nod_init=curent.nod_fin;

                    vecin.nod_fin=G[curent.nod_fin][i].nod;

                    vecin.cost=G[curent.nod_fin][i].cost;

                    heap.push(vecin);

                }

            }

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

    apm_prim();

    afisare();

    return 0;

}
