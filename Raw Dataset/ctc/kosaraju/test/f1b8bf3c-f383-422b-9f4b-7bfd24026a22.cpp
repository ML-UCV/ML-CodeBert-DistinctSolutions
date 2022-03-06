#include <bits/stdc++.h>
#include <cstdio>


using namespace std;



FILE* fin=fopen("ctc.in", "r");

FILE* fout=fopen("ctc.out", "w");



vector<int> lista[100001];

vector<int> listaTrans[100001];

vector<int> comp[100001];

int n, m, ordine[100001], vizitat[100001], total, tot[100001], nr;



void DFFinal(int nod)

{

    vizitat[nod]=1;

    for (int i=0; i<lista[nod].size(); i++)

    {

        if (!vizitat[lista[nod][i]])

        {

            DFFinal(lista[nod][i]);

            total++;

        }

    }

    tot[nod]=total;

}



void Ordonare()

{

    for (int i=1; i<=n; i++)

    {

        ordine[n-tot[i]+1]=i;

        vizitat[i]=0;

    }

}



void DF(int nod)

{

    vizitat[nod]=1;

    for (int i=0; i<listaTrans[nod].size(); i++)

    {

        if (!vizitat[listaTrans[nod][i]])

        {

            comp[nr].push_back(listaTrans[nod][i]);

            DF(listaTrans[nod][i]);

        }

    }

}



int main()

{

    fscanf(fin, "%d%d", &n, &m);

    for (int i=1; i<=m; i++)

    {

        int x, y;

        fscanf(fin, "%d%d", &x, &y);

        lista[x].push_back(y);

        listaTrans[y].push_back(x);

    }

    for (int i=1; i<=n; i++)

    {

        if (!vizitat[i])

        {

            total++;

            DFFinal(i);

        }

    }

    Ordonare();

    for (int i=1; i<=n; i++)

    {

        if (!vizitat[ordine[i]])

        {

            nr++;

            comp[nr].push_back(ordine[i]);

            DF(ordine[i]);

        }

    }

    fprintf(fout, "%d\n", nr);

    for (int i=1; i<=nr; i++)

    {

        for (int j=0; j<comp[i].size(); j++)

        {

            fprintf(fout, "%d ", comp[i][j]);

        }

        fprintf(fout, "\n");

    }

    fclose(fin);

    fclose(fout);

    return 0;

}
