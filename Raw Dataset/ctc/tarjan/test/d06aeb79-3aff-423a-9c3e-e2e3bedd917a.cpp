#include<bits/stdc++.h>
using namespace std;



const int maxN=(1e5)+5;



int niv,lvl[maxN],low[maxN],st[maxN],vf,ctc;



vector<int> v[maxN],C[maxN];

bool inStack[maxN];

void dfs(int nod)

{

    niv++;

    low[nod]=niv;

    lvl[nod]=niv;

    st[++vf]=nod;

    inStack[nod]=1;



    for(auto it:v[nod])

    {

        if(!lvl[it])

        {

            dfs(it);

            low[nod]=min(low[nod],low[it]);

        }

            else

        if(inStack[it])

        {

            low[nod]=min(low[nod],low[it]);

        }

    }



    if(low[nod]==lvl[nod])

    {

        ctc++;

        int x=-1;

        while(x!=nod)

        {

            x=st[vf];

            inStack[x]=0;

            vf--;

            C[ctc].push_back(x);

        }

    }

}

int n,m,x,y;

int main()

{

    freopen("ctc.in","r",stdin);

    freopen("ctc.out","w",stdout);



    scanf("%d%d",&n,&m);



    for(int i=1;i<=m;i++)

    {

        scanf("%d%d",&x,&y);

        v[x].push_back(y);

    }



    for(int i=1;i<=n;i++)

        if(!lvl[i]) dfs(i);



    printf("%d\n",ctc);



    for(int i=1;i<=ctc;i++)

    {

        for(auto it:C[i])

            printf("%d ",it);



        printf("\n");

    }

    return 0;

}
