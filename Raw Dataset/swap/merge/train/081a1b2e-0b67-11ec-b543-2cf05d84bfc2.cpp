#include <bits/stdc++.h>






using namespace std;

char a[50005],b[50005];

int n,i,j,aux;

int x[50005],y[50005];

int cat1[150][50005];

int ap[150];

int A[150][50005];

pair<int,int> v[50005];

int sol;

char c;

void Merge(int st,int mij,int dr)

{

    int k=0;

    int i=st,j=mij+1;

    while(i<=mij && j<=dr)

        if(x[i]<=x[j])

            y[++k]=x[i++];

        else

           y[++k]=x[j++],sol+=mij+1-i;

    while(i<=mij)

        y[++k]=x[i++];

    while(j<=dr)

        y[++k]=x[j++];

    for(k=1,i=st;i<=dr;i++,k++)

        x[i]=y[k];

}

void MergeSort(int st,int dr)

{

    int mij;

    if(st<dr)

    {

        mij=(st+dr)/2;

        MergeSort(st,mij);

        MergeSort(mij+1,dr);

        Merge(st,mij,dr);

    }

}

int main()

{

    freopen("swap.in","r",stdin);

    freopen("swap.out","w",stdout);

    fgets(a+1, 50001, stdin);

    fgets(b+1, 50001, stdin);

    n=strlen(a+1);

    for(i=1;i<=n;i++)

    {

        c=((a[i])-'a'+1);

        cat1[c][0]++;

        A[c][cat1[c][0]]=i;

    }

    for(i=1;i<=n;i++)

    {

        c=((b[i])-'a'+1);

        ap[c]++;

        aux=ap[c];

        x[i]=A[c][aux];

        if(!x[i])

        {

            printf("-1");

            return 0;

        }

    }

    MergeSort(1,n);

    printf("%d",sol);

    return 0;

}
