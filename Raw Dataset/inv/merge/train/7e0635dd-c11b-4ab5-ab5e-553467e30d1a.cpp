#include <iostream>
#include <stdio.h>
using namespace std;



int n,i;

int v[100003];

int a[100003];



int interclasare(int st,int dr){

    int mid=(st+dr)/2,i=st,j=mid+1,nr=0,s=0;



    while(i<=mid && j<=dr){

        if(v[i]<=v[j])

            a[++nr]=v[i++];

        else

            a[++nr]=v[j++],s=s+mid-i+1;

    }



    while(i<=mid)

        a[++nr]=v[i++];



    while(j<=dr)

        a[++nr]=v[j++];



    for(i=1;i<=nr;i++)

        v[st+i-1]=a[i];



    return s;



}



int mergesort(int st,int dr){

    int mid=(st+dr)/2,s=0;



    if(st<dr){

        s=s+mergesort(st,mid);

        s=s+mergesort(mid+1,dr);

        s=s+interclasare(st,dr);

    }



    return s%9917;



}



int main()

{

    freopen("inv.in","r",stdin);

    freopen("inv.out","w",stdout);



    scanf("%d",&n);



    for(i=1;i<=n;i++)

        scanf("%d",&v[i]);



    printf("%d",mergesort(1,n));
    return 0;

}
