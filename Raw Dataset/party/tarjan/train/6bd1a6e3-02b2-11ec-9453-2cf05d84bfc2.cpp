#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>




using namespace std;



int n,m,ind,nrc,sol;

int lev[205],low[205],v[205],c[205],ok[205];

vector<int> l[205];

stack<int> s;



void read()

{

    int x,y,t;

    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)

    {

        scanf("%d%d%d",&x,&y,&t);

        if(!t)

        {

            l[x+n].push_back(y); l[y+n].push_back(x);

            continue;

        }

        if(t==1)

        {

            l[x+n].push_back(y+n); l[y].push_back(x);

            continue;

        }

        if(t==2)

        {

            l[x].push_back(y); l[y+n].push_back(x+n);

            continue;

        }

        l[x].push_back(y+n); l[y].push_back(x+n);

    }

}



void get(int k)

{

    for(nrc++;s.top()!=k;s.pop()) c[s.top()]=nrc,v[s.top()]=0;

    c[k]=nrc; v[k]=0; s.pop();

}



void dfs(int k)

{

    lev[k]=low[k]=++ind; v[k]=1; s.push(k);

    for(unsigned int i=0;i<l[k].size();i++)

     if(!lev[l[k][i]])

     {

         dfs(l[k][i]);

         low[k]=min(low[k],low[l[k][i]]);

     }

     else if(v[l[k][i]]) low[k]=min(low[k],lev[l[k][i]]);



    if(low[k]==lev[k]) get(k);

}



void solve()

{

    for(int i=1;i<=2*n;i++) if(!lev[i]) dfs(i);

    for(int i=1;i<=n;i++)

     if(c[i]<c[i+n]) ok[i]=1,sol++;

}



void print()

{

    printf("%d\n",sol);

    for(int i=1;i<=n;i++)

     if(ok[i]) printf("%d\n",i);

}



int main()

{

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);



    read();

    solve();

    print();



    fclose(stdin);

    fclose(stdout);

    return 0;

}
