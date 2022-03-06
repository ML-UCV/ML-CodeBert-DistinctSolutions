#include <iostream>
#include <fstream>


using namespace std;



ifstream in("inv.in");

ofstream out("inv.out");



const int N = 100000;

int v[N], aux[N];

long long inv=0;



void MergeSort(int v[], int st, int dr);

void Merge(int v[], int st, int dr);



int main()

{

    int n;

    in >> n;

    for(int i=0; i<n; i++) in >> v[i];



    MergeSort(v, 0, n-1);



    out << inv%9917;

    return 0;

}



void MergeSort(int v[], int st, int dr)

{

    if(st==dr) return;

    int m=(st+dr)/2;

    MergeSort(v, st, m);

    MergeSort(v, m+1, dr);

    Merge(v, st, dr);

}



void Merge(int v[], int st, int dr)

{

    int m=(st+dr)/2;

    int i=st, k=st, j=m+1;

    while(i<=m && j<=dr)

    {

        if(v[j]<v[i])

        {

            aux[k++]=v[j++];

            inv+=m-i+1;

        }

        else aux[k++]=v[i++];

    }

    while(i<=m) aux[k++]=v[i++];

    while(j<=dr) aux[k++]=v[j++];



    for(k=st; k<=dr; k++) v[k]=aux[k];

}
