#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> g[205];

vector<int> gt[205];

vector<int> l;

vector<int> comp[205];

int pred[205];

vector<int> succ[205];

int val[205];

bool ans[205];

bool viz[205];

int f[205];

queue<int> q;

int cont;

void dfs(int nod)

{

    viz[nod]=1;

    for(int v : g[nod])

        if(!viz[v])

            dfs(v);

    l.push_back(nod);

}

void dfst(int nod)

{

    viz[nod]=1;

    for(int v : gt[nod])

        if(!viz[v])

            dfst(v);

    comp[cont].push_back(nod);

    f[nod]=cont;

}

FILE *_fin;

FILE *_fout;

int _in_loc; char _in_buff[4096];





void read_init(const char* nume)

{

 _fin = fopen(nume, "r");

 _in_loc = 4095;

}



char read_ch()

{

 ++_in_loc;

 if (_in_loc == 4096) {

  _in_loc = 0;

  fread(_in_buff, 1, 4096, _fin);

 }

 return _in_buff[_in_loc];

}



int read_u32()

{

 int u32 = 0; char c;

 while (!isdigit(c = read_ch()) && c != '-');

 int sgn = 1;

 if (c == '-') {

  sgn = -1;

 } else {

  u32 = c - '0';

 }

 while (isdigit(c = read_ch())) {

  u32 = u32 * 10 + c - '0';

 }

 return u32 * sgn;

}



long long read_u64()

{

 long long u64 = 0; char c;

 while (!isdigit(c = read_ch()) && c != '-');

 long long sgn = 1;

 if (c == '-') {

  sgn = -1;

 } else {

  u64 = c - '0';

 }

 while (isdigit(c = read_ch())) {

  u64 = u64 * 10 + c - '0';

 }

 return u64 * sgn;

}

int main()

{ read_init("party.in");

    _fout=fopen("party.out", "w");

    int n,m,i,x,y,j,nr=0,z;

    n=read_u32();

    m=read_u32();

    for(i=1; i<=m; i++){

        x=read_u32();

        y=read_u32();

        z=read_u32();

        if(z==0){

            g[2*x+1].push_back(2*y);

            g[2*y+1].push_back(2*x);

            gt[2*y].push_back(2*x+1);

            gt[2*x].push_back(2*y+1);

        }

        else{

            if(z==1){

                g[2*x+1].push_back(2*y+1);

                g[2*y].push_back(2*x);

                gt[2*y+1].push_back(2*x+1);

                gt[2*x].push_back(2*y);

            }

            else{

                if(z==2){

                    g[2*x].push_back(2*y);

                    g[2*y+1].push_back(2*x+1);

                    gt[2*x+1].push_back(2*y+1);

                    gt[2*y].push_back(2*x);

                }

                else{

                    g[2*x].push_back(2*y+1);

                    g[2*y].push_back(2*x+1);

                    gt[2*y+1].push_back(2*x);

                    gt[2*x+1].push_back(2*y);

                }

            }

        }

    }

    for(i=1; i<=2*n+1; i++)

        val[i]=-1;

    for(i=2; i<=2*n+1; i++)

        if(!viz[i])

            dfs(i);

    reverse(l.begin(), l.end());

    for(int u : l)

        viz[u]=0;

    for(int u : l){

        if(!viz[u]){

            cont++;

            dfst(u);

        }

    }

    for(i=2; i<=2*n+1; i++){

        if(f[(i/2)*2+(i%2+1)%2]==f[i]){

            fprintf(_fout, "-1");

            return 0;

        }

        for(j=0; j<g[i].size(); j++)

            if(f[i]!=f[g[i][j]]){

                pred[f[g[i][j]]]++;

                succ[f[i]].push_back(f[g[i][j]]);

            }

    }

    for(i=1; i<=cont; i++)

        if(pred[i]==0)

            q.push(i);

    while(!q.empty()){

        int u=q.front();

        q.pop();

        if(val[f[(comp[u][0]/2)*2+(comp[u][0]%2+1)%2]]!=-1)

            val[u]=(val[f[(comp[u][0]/2)*2+(comp[u][0]%2+1)%2]]+1)%2;

        else{

            val[u]=0;

            for(i=0; i<succ[u].size(); i++){

                pred[succ[u][i]]--;

                if(pred[succ[u][i]]==0)

                    q.push(succ[u][i]);

            }

        }

    }

    for(i=1; i<=cont; i++)

        for(j=0; j<comp[i].size(); j++)

            ans[comp[i][j]]=val[i];

    for(i=2; i<=2*n; i+=2)

        nr+=ans[i];

    fprintf(_fout, "%d\n", nr);

    for(i=2; i<=2*n; i+=2)

        if(ans[i]==1)

            fprintf(_fout, "%d\n", i/2);

    return 0;

}
