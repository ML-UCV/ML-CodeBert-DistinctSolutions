#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



int n, m, cost;

struct muchie

{

    int sursa, dest, cost;

};

vector <muchie> v;

vector <int> P;

vector < pair<int, int> > sol;



bool comp(muchie A, muchie B)

{

    return A.cost<B.cost;

}



void citire()

{

    in>>n>>m;

    int x, y, z;

    for(int i=1;i<=m;i++)

    {

        in>>x>>y>>z;

        v.push_back({x,y,z});

    }



    sort(v.begin(),v.end(),comp);



    for(int i=0;i<=n;i++)

        P.push_back(i);



}



int radacina(int nod)

{

    int rad=nod, aux;

    while(P[rad]!=rad)

        rad=P[rad];

    while(nod!=rad)

    {

        aux=P[nod];

        P[nod]=rad;

        nod=aux;

    }

    return rad;

}



void unire(int nod1, int nod2)

{

    P[P[nod2]]=P[nod1];

}



int Kruskal()

{

    int x, y, z;

    for(int i=0;i<m;i++)

    {

        x=v[i].sursa;

        y=v[i].dest;

        z=v[i].cost;

        if(radacina(x)!=radacina(y))

        {

            unire(x,y);

            cost+=z;

            sol.push_back({x,y});

        }

    }

}



void afisare()

{

    out<<cost<<'\n';

    out<<sol.size()<<'\n';

    for(int i=0;i<sol.size();i++)

        out<<sol[i].first<<' '<<sol[i].second<<'\n';

}



int main()

{

    citire();

    Kruskal();

    afisare();

    return 0;

}
