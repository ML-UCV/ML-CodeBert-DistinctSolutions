#include <bits/stdc++.h>






using namespace std;
int n,m,postord[100005], t, viz[100005], k;

vector<int> G[100005], GT[100005], ctc[100005];

ifstream fin("ctc.in");

ofstream fout("ctc.out");

void DFS(int x)

{

    int i, w;







    viz[x] = 1;







    for (i = 0;i< G[x].size();i++)

        {

            w=G[x][i];

            if (!viz[w])

                DFS(w);

        }

t++;

postord[t] = x;

}







void DFST(int x)

{

    int i, w;







    viz[x] = 1;

    ctc[k].push_back(x);

    for (i = 0;i<GT[x].size(); i++)

    {

        w=GT[x][i];

        if (!viz[w])

            DFST(w);

    }







}







int main()

{

    int i,j, x, y;

    fin>>n>>m;

    for (i=1;i<=m;i++)

    {

        fin>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }



    for (i = 1; i <= n; i++)

        if (!viz[i])

            DFS(i);
    for(i=1;i<=n;i++)

        viz[i]=0;







    k=0;



    for (i = n; i>=1; i--)

        if (!viz[postord[i]])

        {

            k++;

            DFST(postord[i]);

        }







    fout<<k<<'\n';

    for (i = 1; i <= k; i++)

    {

        sort(ctc[i].begin(),ctc[i].end());

        for (j=0; j < ctc[i].size(); j++)

            fout<<ctc[i][j]<<' ';

        fout<<'\n';

    }







    return 0;

}
