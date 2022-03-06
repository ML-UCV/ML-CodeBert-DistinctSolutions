#include <bits/stdc++.h>




using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m, nr, vf[200001], urm[200001], last[100001];

int nrt, vft[200001], urmt[200001], lastt[100001];

int top[100001], nrtop, nrc;

bitset < 100001 > viz;

vector < int > answer[100001];



void adauga(int from, int to)

{

    vf[++nr] = to;

    urm[nr] = last[from];

    last[from] = nr;

}



void adaugat(int from, int to)

{

    vft[++nrt] = to;

    urmt[nrt] = lastt[from];

    lastt[from] = nrt;

}





void citire()

{

    fin>>n>>m;

    for(int x, y, i=1; i<=m; i++)

    {

        fin>>x>>y;

        adauga(x, y);

        adaugat(y, x);



    }



}



void dfs(int nod)

{

    viz[nod] = 1;



    for(int k = last[nod]; k; k = urm[k])

        if(viz[ vf[k] ] == 0)

            dfs(vf[k]);



    top[++nrtop] = nod;



}



void dfst(int nod)

{

    viz[nod] = 1;

    answer[nrc].push_back(nod);

    for(int k = lastt[nod]; k; k = urmt[k])

        if(viz[ vft[k] ] == 0)

            dfst(vft[k]);

}





int main(){

    citire();

    for(int i=1; i<=n; i++)

        if(!viz[i])

            dfs(i);



    viz = 0;



    for(int i = nrtop; i>0; i--)

    {

        if(!viz[ top[i] ])

        {

            nrc++;

            dfst(top[i]);

        }



    }

    fout<<nrc<<'\n';

    for(int i=1; i<=nrc; i++)

    {

        for(auto a : answer[i])

            fout<<a<<' ';

        fout<<'\n';



    }



    return 0;

}
