#include <cstdio>






using namespace std;



int a[3*30005],v[30005];



inline void Build(int nod, int st, int dr)

{

    if(st==dr)

    {

        a[nod]=1;

        return ;

    }

    int mij=(st+dr)/2;

    Build(2*nod,st,mij);

    Build(2*nod+1,mij+1,dr);

    a[nod]=a[2*nod]+a[2*nod+1];

}



inline void Update(int nod, int st, int dr, int poz)

{

    if(st==dr)

    {

        a[nod]=0;

        return ;

    }

    int mij=(st+dr)/2;

    if(poz<=mij)

        Update(2*nod,st,mij,poz);

    else

        Update(2*nod+1,mij+1,dr,poz);

    a[nod]=a[2*nod]+a[2*nod+1];

}



inline int Query(int nod, int st, int dr, int x)

{

    if(st==dr)

        return st;

    int mij=(st+dr)/2;

    if(x<=a[2*nod])

        return Query(2*nod,st,mij,x);

    else

        return Query(2*nod+1,mij+1,dr,x-a[2*nod]);

}



int main()

{

    freopen ("schi.in","r",stdin);

    freopen ("schi.out","w",stdout);

    int i,poz,sol[30005],N;

    scanf("%d", &N);

    Build(1,1,N);

    for(i=1; i<=N; ++i)

        scanf("%d", &v[i]);

    for(i=N; i>0; --i)

    {

        poz=Query(1,1,N,v[i]);

        sol[poz]=i;

        Update(1,1,N,poz);

    }

    for(i=1; i<=N; ++i)

        printf("%d\n", sol[i]);

    return 0;

}
