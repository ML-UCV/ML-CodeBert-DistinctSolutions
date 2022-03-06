#include <bits/stdc++.h>




using namespace std;

ifstream r("inv.in");

ofstream w("inv.out");

int v[500003], sol=0;

const int mod=9917;

void unire(int a, int mij, int b){

    int n1 = mij - a + 1, n2 = b - mij, g[n1], h[n2], nr=0, rasp=0;

    for(int i=0;i<n1;i++){

        g[i]=v[a+i];

    }

    for(int i=0;i<n2;i++){

        h[i]=v[mij+i+1];

    }

    int i=0, j=0, k=a;

    while(i<n1 && j<n2){

        if(g[i]<=h[j]){

            v[k]=g[i];

            i++;

            rasp+=nr;

        }

        else{

            v[k]=h[j];

            j++;

            nr++;

        }

        k++;

    }

    while (i < n1)

    {

        v[k] = g[i];

        i++;

        k++;

        rasp+=nr;

    }

    while (j < n2)

    {

        v[k] = h[j];

        j++;

        k++;

    }

    sol=sol+rasp;

    sol%=mod;

}

void mergesort(int a, int b)

{

    if(a<b){

        int mij=(a+b)/2;

        mergesort(a, mij);

        mergesort(mij+1, b);

        unire(a, mij, b);

    }

}

int main()

{

    int n;

    r>>n;

    for(int i=0; i<n; i++)

    {

        r>>v[i];

    }

    mergesort(0, n-1);

    w<<sol;

    return 0;

}
