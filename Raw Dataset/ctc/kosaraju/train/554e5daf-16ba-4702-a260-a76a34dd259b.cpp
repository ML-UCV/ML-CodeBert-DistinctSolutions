#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");



const int nlim=100005;

int n,m,nrCTC=0;

int beenThere[nlim];

vector <int> muchii[nlim],muchii_T[nlim],result[nlim];

stack <int> S;



void citire()

{

    f>>n>>m;

    int x,y;

    for(int i=1;i<=m;i++)

    {

        f>>x>>y;

        muchii[x].push_back(y);

        muchii_T[y].push_back(x);

    }

}



void DFS(int nod)

{

    beenThere[nod]=1;

    for(int i=0;i<muchii[nod].size();i++)

    {

        int vecin=muchii[nod][i];

        if(beenThere[vecin]==0)

            DFS(vecin);

    }

    S.push(nod);

}



void DFS_T(int nod)

{

    beenThere[nod]=2;

    result[nrCTC].push_back(nod);

    for(int i=0;i<muchii_T[nod].size();i++)

    {

        int vecin=muchii_T[nod][i];

        if(beenThere[vecin]==1)

            DFS_T(vecin);

    }

}



void rezolva()

{

    for(int i=1;i<=n;i++)

        if(beenThere[i]==0)

            DFS(i);

    while(!S.empty())

    {

        int nod=S.top();

        S.pop();

        if(beenThere[nod]==1)

        {

            nrCTC++;

            DFS_T(nod);

        }

    }

}



void afisare()

{

    g<<nrCTC<<'\n';

    for(int i=1;i<=nrCTC;i++)

    {

        for(int j=0;j<result[i].size();j++)

            g<<result[i][j]<<" ";

        g<<'\n';

    }

}



int main()

{

    citire();

    rezolva();

    afisare();

    return 0;

}
