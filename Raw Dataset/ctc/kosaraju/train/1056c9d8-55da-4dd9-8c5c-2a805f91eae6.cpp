#include <iostream>
#include <fstream>
#include <vector>
#include <deque>


using namespace std;



ifstream fin ("ctc.in");

ofstream fout ("ctc.out");

vector<int>gi[100002], gf[100002], comp[100002];

deque <int> t;

bool viz1[100002], viz2[100002];

int n, m, nr_componente=0;



void DFS1(int x)

{

    viz1[x]=1;

    for(int i=0; i<gi[x].size(); i++){

        if(!viz1[gi[x][i]])

            DFS1(gi[x][i]);

    }

    t.push_back(x);

}

void DFS2(int x)

{

    comp[nr_componente].push_back(x);

    viz2[x]=1;

    for(int i=0; i<gf[x].size(); i++){

        if(!viz2[gf[x][i]])

            DFS2(gf[x][i]);

    }

}

void sortareTopologica()

{

    for(int i=1; i<=n; i++){

        if(!viz1[i]) DFS1(i);

    }

}

int main()

{

    fin>>n>>m;

    int i, j, x, y;

    for(i=1; i<=m; i++){

        fin>>x>>y;

        gi[x].push_back(y);

        gf[y].push_back(x);

    }

    sortareTopologica();



    for(i=t.size()-1; i>=0; i--){

        if(!viz2[t[i]]){



            nr_componente++;

            DFS2(t[i]);

        }

    }



    fout<<nr_componente<<"\n";

    for(i=1; i<=nr_componente; i++){

        for(j=0; j<comp[i].size(); j++) fout<<comp[i][j]<<' ';

        fout<<"\n";

    }

}
