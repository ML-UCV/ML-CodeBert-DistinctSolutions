#include <bits/stdc++.h>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m;

vector<int>v[100005], g[100005], answer[100005];

int viz[100005], parc[100005], top, nrc;

void DFS1(int x)

{

    viz[x] = 1;

    for(auto nod: v[x])

        if(!viz[nod])

            DFS1(nod);



    parc[++top] = x;



}

void DFS2(int x)

{

    viz[x] = 1;

    for(auto nod: g[x])

        if(!viz[nod])

            DFS2(nod);

    answer[nrc].push_back(x);

}





int main()

{

    int x, y;

    fin >> n >> m;

    for(int i = 1; i <= m; i++)

    {

        fin >> x >> y;

        v[x].push_back(y);

        g[y].push_back(x);

    }

    for(int i = 1; i <= n; i++)

        if(!viz[i])

            DFS1(i);

    for(int i = 1; i <= n; i++)

        viz[i] = 0;

    for(int i = n; i >= 1; i--)

        if(!viz[parc[i]])

        {

            nrc++;

            DFS2(parc[i]);

        }

    fout << nrc << "\n";

    for(int i = 1; i <= nrc; i++)

    {

        for(auto nod: answer[i])

            fout << nod << " ";

        fout << "\n";



    }



    return 0;

}
