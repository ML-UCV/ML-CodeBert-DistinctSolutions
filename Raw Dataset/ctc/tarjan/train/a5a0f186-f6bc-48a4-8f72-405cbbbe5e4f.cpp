#include<bits/stdc++.h>
using namespace std;



const int maxN=(1e5)+5;



int lvl,niv[maxN],low[maxN],st[maxN],vf,ctc;

bool inStack[maxN];



vector<int> v[maxN],C[maxN];



void dfs(int nod)

{

    lvl++;

    niv[nod]=low[nod]=lvl;

    st[++vf]=nod;

    inStack[nod]=1;



    for(auto it:v[nod])

    {

        if(!niv[it])

        {

            dfs(it);

            low[nod]=min(low[nod],low[it]);

        }

            else

        if(inStack[it])

            low[nod]=min(low[nod],low[it]);

    }



    if(low[nod]==niv[nod])

    {

        int x=-1;

        ctc++;

        while(x!=nod)

        {

            x=st[vf];

            C[ctc].push_back(x);

            inStack[x]=0;

            vf--;

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

        if(!niv[i]) dfs(i);





    printf("%d\n",ctc);



    for(int i=1;i<=ctc;i++)

    {

        for(auto it:C[i])

            printf("%d ",it);



        printf("\n");

    }





    return 0;

}
