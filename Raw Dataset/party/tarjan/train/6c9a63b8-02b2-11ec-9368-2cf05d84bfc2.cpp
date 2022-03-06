#include<stdio.h>
#include <stdlib.h>


bool take[103];



struct exp

{

    int x,y,z;

    bool check()

    {

        if(z==0)return take[x]||take[y];

        if(z==1)return take[x]||!take[y];

        if(z==2)return !take[x]||take[y];

        if(z==3)return !(take[x]&&take[y]);

    }

    void rSwitch()

    {

        int v=rand()%2;

        if(v==0)take[x]=!take[x];

        else take[y]=!take[y];

    }

};

exp exps[1003];

int n,m;



int main()

{

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;++i)take[i]=1;

    for(int i=0;i<m;++i)scanf("%d%d%d",&exps[i].x,&exps[i].y,&exps[i].z);

    for(int i=0;i<m;++i)

      if(!exps[i].check()){exps[i].rSwitch();i=-1;}

    int nr=0;

    for(int i=1;i<=n;++i)if(take[i])++nr;

    printf("%d\n",nr);

    for(int i=1;i<=n;++i)if(take[i])printf("%d\n",i);

    return 0;

}
