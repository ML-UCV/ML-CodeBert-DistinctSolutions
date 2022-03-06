#include <cstdio>
#include <vector>


using namespace std;



vector<int> v[210],vt[210];

int q[210],n,nr;

char vaz[210],sol[210];



int neg(int x)

{

    if(x<=n) return x+n;

    else return x-n;

}

void dfs_dir(int nod)

{

    vaz[nod]=1;

    for(vector<int>::iterator it=v[nod].begin();it!=v[nod].end();it++)

        if(!vaz[*it]) dfs_dir(*it);

    q[++nr]=nod;

}

void add_edge(int x,int y)

{

    v[x].push_back(y);

    vt[y].push_back(x);

}

void dfs_indir(int nod)

{

    vaz[nod]=sol[nod]=0;

    sol[neg(nod)]=1;

    for(vector<int>::iterator it=vt[nod].begin();it!=vt[nod].end();it++)

        if(vaz[*it]) dfs_indir(*it);

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

            add_edge(neg(x),y);

            add_edge(neg(y),x);

        }

        else if(a==1)

        {

            add_edge(neg(x),neg(y));

            add_edge(y,x);

        }

        else if(a==2)

        {

            add_edge(x,y);

            add_edge(neg(y),neg(x));

        }

        else

        {

            add_edge(x,neg(y));

            add_edge(y,neg(x));

        }

    }

    for(int i=1;i<=2*n;i++) if(!vaz[i]) dfs_dir(i);

    for(int i=nr;i;i--) if(vaz[q[i]] && vaz[neg(q[i])]) dfs_indir(q[i]);

    nr=0;

    for(int i=1;i<=n;i++) if(sol[i]) nr++;

    printf("%d\n",nr);

    for(int i=1;i<=n;i++) if(sol[i]) printf("%d\n",i);

    return 0;

}
