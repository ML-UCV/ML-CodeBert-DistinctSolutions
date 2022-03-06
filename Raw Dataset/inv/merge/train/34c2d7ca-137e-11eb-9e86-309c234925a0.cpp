#include<bits/stdc++.h>




using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



long v[100000];

int n,poz[100000],dreapta;

long long solutie;

void MergeSort(long a[],int st, int dr)

{

    if(st<dr)

    {

        int mijloc =(st+dr)/2;

        MergeSort(a,st,mijloc);

        MergeSort(a,mijloc+1,dr);

        int k=0,i=st,j=mijloc+1;

        int b[100000];

        dreapta=0;

        while(i<=mijloc && j<=dr)

            if(a[i]<=a[j])

            {

                b[k++]=a[i++];

                solutie+=dreapta;

            }

            else

            {

                b[k++]=a[j++];

                dreapta++;

            }

        while(i<=mijloc)

        {

            b[k++]=a[i++];

            solutie+=dreapta;

        }

        while(j<=dr)

            b[k++]=a[j++];

        for(i=st; i<=dr; i++)

            a[i]=b[i-st];

    }

}

int main()

{

    fin>>n;

    for(int i=0; i<n; ++i)

        fin>>v[i];

    MergeSort(v,0,n-1);

    fout<<solutie%9917;

    return 0;

}
