# include <fstream>
# include <vector>


using namespace std;

ifstream fin("party.in");

ofstream fout("party.out");

vector <int> Lista[210],sol[210];

int val[210],Marcat[210],poz[210],low[210],s[210];

int n,m,i,j,nr,u,ctc,ok,loc,x,y,r,sum;

int sw(int x){

    if(x>n)

        return x-n;

    else

        return x+n;

}

void tarjan(int nc){

    nr++;

    poz[nc]=nr;

    low[nc]=nr;

    Marcat[nc]=1;

    s[++u]=nc;

    for(int i=0;i<Lista[nc].size();i++){

        int nv=Lista[nc][i];

        if(!poz[nv]){

            tarjan(nv);

            low[nc]=min(low[nc],low[nv]);

        }

        else

            if(Marcat[nv])

                low[nc]=min(low[nc],low[nv]);

    }

    if(poz[nc]==low[nc]){

        ctc++;

        ok=1;

        while(s[u]!=nc){

            if(val[s[u]]+1){

                loc=val[s[u]];

                ok=0;

            }

            sol[ctc].push_back(s[u]);

            Marcat[s[u--]]=0;

        }

        u--;

        if(val[nc]+1){

            loc=val[nc];

            ok=0;

        }

        sol[ctc].push_back(nc);

        Marcat[nc]=0;

        if(ok)

            loc=1;

        val[nc]=loc;

        val[sw(nc)]=1-loc;

    }

}

int main () {

    fin>>n>>m;

    for(i=1;i<=m;i++){

        fin>>x>>y>>r;

        if(r==0){

            Lista[x+n].push_back(y);

            Lista[y+n].push_back(x);

        }

        if(r==1){

            Lista[x+n].push_back(y+n);

            Lista[y].push_back(x);

        }

        if(r==2){

            Lista[y+n].push_back(x+n);

            Lista[x].push_back(y);

        }

        if(r==3){

            Lista[x].push_back(y+n);

            Lista[y].push_back(x+n);

        }

    }

    for(i=1;i<=2*n;i++)

        val[i]=-1;

    for(i=1;i<=2*n;i++)

        if(!poz[i])

            tarjan(i);

    for(i=1;i<=ctc;i++)

        for(j=sol[i].size()-2;j>=0;j--)

            val[sol[i][j]]=val[sol[i][j+1]];

    for(i=1;i<=n;i++)

        sum+=val[i];

    fout<<sum<<"\n";

    for(i=1;i<=n;i++)

        if(val[i])

            fout<<i<<"\n";

    return 0;

}
