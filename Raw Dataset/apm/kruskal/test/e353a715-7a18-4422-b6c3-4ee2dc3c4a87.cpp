#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int h[200005],t[200005];

struct aj

{

    int x,y,c;

};

vector<aj>v;

bool cmp(aj a, aj b)

{

    if(a.c==b.c)

    {

        if(a.x==b.x) return a.y<b.y;

        return a.x<b.x;

    }

    return a.c<b.c;

}

int findt(int x)

{

    while(t[x]!=x)

        x=t[x];

    return x;

}

bool viz(int a)

{

    if(t[a]!=a||h[a]!=1) return 1;

    return 0;

}

void combine(int x, int y)

{

    int xx=findt(x),yy=findt(y);

    if(h[xx]>h[yy]) t[yy]=xx;

        else if(h[yy]>h[xx]) t[xx]=yy;

            else t[yy]=xx,h[xx]++;

}

struct ans

{

    int x,y;

};

vector<ans>an;

int main()

{

    aj ha;

    freopen("apm.in","r",stdin);

    freopen("apm.out","w",stdout);

    int n,m,x,x1,x2,cnt=0;

    scanf("%d%d",&n,&m);

    for(register int i=1;i<=m;i++)

    {

        scanf("%d%d%d",&x,&x1,&x2);

        ha.x=x;

        ha.y=x1;

        ha.c=x2;

        v.push_back(ha);

    }

    sort(v.begin(),v.end(),cmp);

    for(register int i=1;i<=n;i++)

    {

        t[i]=i;

        h[i]=1;

    }

    int cost=0;

    for(register int i=0;i<v.size();i++)

    {

        x1=v[i].x;

        x2=v[i].y;

        if(findt(x1)!=findt(x2))

        {

            ans help;

            help.x=x1;

            help.y=x2;

            an.push_back(help);

            cost+=v[i].c,combine(x1,x2);

            cnt++;

            if(cnt==n-1) break;

        }

    }

    printf("%d\n%d\n",cost,an.size());

    for(register int i=0;i<an.size();i++)

        printf("%d %d\n",an[i].x,an[i].y);

    return 0;

}
