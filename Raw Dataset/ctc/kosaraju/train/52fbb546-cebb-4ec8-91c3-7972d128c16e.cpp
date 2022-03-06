#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector<vector<int>>graf(100002),graf_trans(100002),rez(100002);

vector<bool>vizitat(100001);

vector<int>vect;

int cnt;



void dfs_graf(int nod)

{

    int i;

    vizitat[nod] = true;

    for(i=0; i<graf[nod].size(); i++)

    {

        if(!vizitat[graf[nod][i]])

        {

            dfs_graf(graf[nod][i]);

        }

    }

    vect.push_back(nod);

}



void dfs_graf_trans(int nod)

{

    int i;

    vizitat[nod] = true;

    rez[cnt].push_back(nod);

    for(i=0; i<graf_trans[nod].size(); i++)

    {

        if(!vizitat[graf_trans[nod][i]])

        {

            dfs_graf_trans(graf_trans[nod][i]);

        }

    }

}



int main()

{

    int nr_varfuri,nr_arce,i,j,x,y;

    f>>nr_varfuri>>nr_arce;

    for(i=0; i<nr_arce; i++)

    {

        f>>x>>y;

        graf[x].push_back(y);

        graf_trans[y].push_back(x);

    }

    for(i=1 ; i<=nr_varfuri; i++)

    {

        if(!vizitat[i])

        {

            dfs_graf(i);

        }

    }

    vizitat = vector<bool>(nr_varfuri+1,false);

    for(i=vect.size()-1; i>=0; i--)

    {

        if(!vizitat[vect[i]])

        {

            cnt++;

            dfs_graf_trans(vect[i]);

        }

    }

    g<<cnt<<"\n";

    for(i=0; i<cnt; i++)

    {

        for(j=0; j<rez[i+1].size(); j++)

        {

            g<<rez[i+1][j]<<" ";

        }

        g<<"\n";

    }

    return 0;

}
