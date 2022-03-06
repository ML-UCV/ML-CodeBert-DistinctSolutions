#include <cstdio>
#include <vector>


using namespace std;



vector<int> v[210],vt[210];

int q[210],n,nr;

char vaz[210],sol[210];



int non(int x)

{

    if(x<=n) return x+n;

    else return x-n;

}



void add_edge(int x,int y)

{

    v[x].push_back(y);

    vt[y].push_back(x);

}



void dfs1(int nod)

{

    vaz[nod]=1;

    for(vector<int>::iterator it=v[nod].begin();it!=v[nod].end();it++)

        if(!vaz[*it]) dfs1(*it);

    q[++nr]=nod;

}



void dfs2(int nod)

{

    vaz[nod]=sol[nod]=0;

    sol[non(nod)]=1;

    for(vector<int>::iterator it=vt[nod].begin();it!=vt[nod].end();it++)

        if(vaz[*it]) dfs2(*it);

}



int main()

{

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);

    int m,x,y,a;

    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)

    {

        scanf("%d%d%d",&x,&y,&a);

        if(a==0)

        {

            add_edge(non(x),y);

            add_edge(non(y),x);

        }

        else if(a==1)

        {

            add_edge(non(x),non(y));

            add_edge(y,x);

        }

        else if(a==2)

        {

            add_edge(x,y);

            add_edge(non(y),non(x));

        }

        else

        {

            add_edge(x,non(y));

            add_edge(y,non(x));

        }

    }

    for(int i=1;i<=2*n;i++) if(!vaz[i]) dfs1(i);

    for(int i=nr;i;i--) if(vaz[q[i]] && vaz[non(q[i])]) dfs2(q[i]);

    nr=0;

    for(int i=1;i<=n;i++) if(sol[i]) nr++;

    printf("%d\n",nr);

    for(int i=1;i<=n;i++) if(sol[i]) printf("%d\n",i);

    return 0;

}
