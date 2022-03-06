#include<cstdio>
#include<cstdlib>#include <cstring>
#include<vector>
using namespace std;





char Viz[256];

int St[256],A[256],n,k;

vector<int> G[256],Gt[256];



void read()

{

    int m,x,y,z;



    freopen("party.in","r",stdin);

    scanf("%d%d",&n,&m);

    while(m--)

    {

        scanf("%d%d%d",&x,&y,&z);

        x+=n*((z&2)!=0); y+=n*(z&1);

        G[((x)>n?(x)-n:(x)+n)].push_back(y);

        Gt[y].push_back(((x)>n?(x)-n:(x)+n));

        G[((y)>n?(y)-n:(y)+n)].push_back(x);

        Gt[x].push_back(((y)>n?(y)-n:(y)+n));

    }

}



void DFS(int x)

{

    vector<int>::iterator it;



    Viz[x]=1;

    for(it=G[x].begin();it!=G[x].end();++it)

        if(!Viz[*it])

            DFS(*it);

    St[++k]=x;

}



void DFST(int x)

{

    vector<int>::iterator it;



    Viz[x]=1; A[k++]=x;

    for(it=Gt[x].begin();it!=Gt[x].end();++it)

        if(!Viz[*it])

            DFST(*it);

}



void solve()

{

    int i,j;



    for(i=1;i<=n<<1;++i)

        if(!Viz[i])

            DFS(i);



    memset(Viz,0,256*sizeof(char));

    for(i=k;i;--i)

        if(!Viz[St[i]])

        {

            k=0;

            DFST(St[i]);

            for(j=0;j<k;++j)

            {

                Viz[A[j]]=1;

                Viz[((A[j])>n?(A[j])-n:(A[j])+n)]=2;

            }

        }



    for(k=0,i=1;i<=n;++i)

        if(Viz[i]==2)

            A[k++]=i;

}



void write()

{

    int i;



    freopen("party.out","w",stdout);

    printf("%d\n",k);

    for(i=0;i<k;++i)

        printf("%d\n",A[i]);

}



int main()

{

    read();

    solve();

    write();

    return 0;

}
