#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;





int X[1000],Y[1000],Z[1000],XX[1000],YY[1000],ZZ[1000],V[101],A[101],n,m,mm,k;

vector<int> C[101];



void read()

{

    int i;



    freopen("party.in","r",stdin);

    scanf("%d%d",&n,&m);

    for(i=0;i<m;++i)

    {

        scanf("%d%d%d",X+i,Y+i,Z+i);

        C[X[i]].push_back(i);

        C[Y[i]].push_back(i);

    }

}



bool set(int x, int v)

{

    vector<int>::iterator it;



    V[x]=v;

    for(it=C[x].begin();it!=C[x].end();++it)

    {

        if(V[X[*it]] && V[Y[*it]])

            if(V[X[*it]]-1^((Z[*it]&2)!=0) || V[Y[*it]]-1^((Z[*it]&1)!=0))

                continue;

            else

            {

                V[x]=0;

                return 0;

            }

        else

        {

            if(X[*it]==x && !(V[x]-1^((Z[*it]&2)!=0)))

                if(!set(Y[*it],(1^((Z[*it]&1)!=0))+1))

                {

                    V[x]=0;

                    return 0;

                }

            if(Y[*it]==x && !(V[x]-1^((Z[*it]&1)!=0)))

                if(!set(X[*it],(1^((Z[*it]&2)!=0))+1))

                {

                    V[x]=0;

                    return 0;

                }

        }

    }

    return 1;

}



void solve()

{

    int i;



    while(m)

    {

        if(!set(X[0],1))

            set(X[0],2);

        for(i=1;i<=n;++i)

            C[i].clear();

        for(mm=i=0;i<m;++i)

            if(!V[X[i]] && !V[Y[i]])

            {

                XX[mm]=X[i];

                YY[mm]=Y[i];

                ZZ[mm++]=Z[i];

            }

        m=mm;

        memcpy(X,XX,1000*sizeof(int));

        memcpy(Y,YY,1000*sizeof(int));

        memcpy(Z,ZZ,1000*sizeof(int));

        for(i=0;i<m;++i)

        {

            C[X[i]].push_back(i);

            C[Y[i]].push_back(i);

        }

    }



    for(i=1;i<=n;++i)

        if(V[i]==2)

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
