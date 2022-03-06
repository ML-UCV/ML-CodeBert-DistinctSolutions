#include <bits/stdc++.h>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");







int n,m,x,y,nr;



vector <int > G[100005],GT[100005],S,sol[100005];

bitset <100005> v;



void dfs(int x)

{

    v[x]=1;

    for(int i=0;i<G[x].size();i++)

    if(v[G[x][i]]==0)

    {

        dfs(G[x][i]);



    }

    S.push_back(x);





}



void dfsGT(int x)

{





    sol[nr].push_back(x);

    v[x]=1;



    for(int i=0;i<GT[x].size();i++)

        if(v[GT[x][i]]==0)

      {

          dfsGT(GT[x][i]);

      }







}







int main()

{

    fin>>n>>m;



    for(int i=1;i<=m;i++)

    {

        fin>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);



    }





    for(int i=1;i<=n;i++)

        if(v[i]==0)

        dfs(i);



    v.reset();



    for(int i=n-1;i>=0;i--)

    if(v[S[i]]==0)

    {

        nr++;

        dfsGT(S[i]);



    }





    fout<<nr<<"\n";



    for(int i=1;i<=nr;i++)

    {

        for(int j=0;j<sol[i].size();j++)

           fout<<sol[i][j]<<" ";

           fout<<"\n";



    }







    return 0;

}
