#include <bits/stdc++.h>




using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

int a[100002];

int b[100002];

int n,ct;

void interclasare(int st,int m, int dr)

{

    int i=st,j=m+1,k=0;

    while(i<=m && j<=dr)

        if(a[i]<=a[j]) b[++k]=a[i++];

        else

        {

            b[++k]=a[j++];

            ct+=(m-i+1);

            ct=ct%9917;

        }

    while(i<=m)

        b[++k]=a[i++];

    while(j<=dr)

        b[++k]=a[j++];

    j=1;

    for(i=st;i<=dr;i++)

        a[i]=b[j++];

}

void MergeSort(int st, int dr)

{

    int m;

    if(dr-st<=1)

    {

        if(a[st]>a[dr])

            {

                swap(a[dr],a[st]);

                ct++;

            }

    }

    else

    {

        m=(st+dr)/2;

        MergeSort(st,m);

        MergeSort(m+1,dr);

        interclasare(st,m,dr);

    }

}

int main()

{

    fin>>n;

    for(int i=1; i<=n; i++)

        fin>>a[i];

    MergeSort(1,n);

    fout<<ct;

    return 0;

}
