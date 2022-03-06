#include <bits/stdc++.h>


using namespace std;

bool in_stk[205];

int sol[205];

int n,m,i,j,x,y,z;

int stk[205],top,cntscc;

int low[205],idx[205],curr,scc[205];

vector<int> v[205],invite;

inline int opposite(int x)

{

    if(x>n)

        return x-n;

    return x+n;

}

void tarjan(int nod)

{

    low[nod]=idx[nod]=++curr;

    stk[++top]=nod;

    in_stk[nod]=true;



    for(auto it:v[nod])

        if(!idx[it]){

            tarjan(it);

            low[nod]=min(low[nod],low[it]);

        }

        else if(in_stk[it])

            low[nod]=min(low[nod],idx[it]);



    if(low[nod]==idx[nod])

    {

        int newn;

        ++cntscc;

        do

        {

            newn=stk[top--];

            in_stk[newn]=false;

            scc[newn]=cntscc;

            if(!sol[newn])

                sol[newn]=1,sol[opposite(newn)]=-1;

        }while(nod!=newn);

    }

}

int main()

{

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);

    scanf("%d %d",&n,&m);

    for(i=1;i<=m;i++)

    {

        scanf("%d %d %d",&x,&y,&z);

        if(z==0)

            v[opposite(x)].push_back(y),v[opposite(y)].push_back(x);

        if(z==1)

            v[opposite(x)].push_back(opposite(y)),v[y].push_back(x);

        if(z==2)

            v[opposite(y)].push_back(opposite(x)),v[x].push_back(y);

        if(z==3)

            v[x].push_back(opposite(y)),v[y].push_back(opposite(x));

    }

    for(i=1;i<=n;i++)

        if(!idx[i])

            tarjan(i);

    for(i=1;i<=n;i++)

        if(sol[i]==1)

            invite.push_back(i);

    printf("%d\n",invite.size());

    for(auto it:invite)

        printf("%d ",it);

    return 0;

}
