#include <fstream>
#include <bitset>
#include <vector>
#include <stack>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

int i,n,m,x,y,niv[100002],low[100002],f[100002],nivel,ctc;

vector <int> v[100002],sol[100002];

stack <int> s;

void dfs(int nod){



    niv[nod]=low[nod]=++nivel;

    s.push(nod);

    f[nod]=1;

    for(auto vecin: v[nod])

        if(!niv[vecin]){

            dfs(vecin);

            low[nod]=min(low[vecin],low[nod]);

        }else if(f[vecin])

            low[nod]=min(low[vecin],low[nod]);



    if(niv[nod]==low[nod]){

        ctc++;

        int x=0;

        while(x!=nod){

            x=s.top();

            sol[ctc].push_back(x);

            f[x]=0;

            s.pop();

        }

    }

}

int main(){

    fin>>n>>m;

    for(i=1;i<=m;i++){

        fin>>x>>y;

        v[x].push_back(y);

    }

    for(i=1;i<=n;i++)

        if(!niv[i])

            dfs(i);

    fout<<ctc<<"\n";

    for(i=1;i<=ctc;i++){

        for(auto x :sol[i])

            fout<<x<<" ";

        fout<<"\n";

    }

    return 0;

}
