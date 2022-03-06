#include <iostream>
#include <fstream>
using namespace std;





int interclasare(int a[], int i, int j,int m)

{

    int nr=0;

    int aux[i+j-1];

    int p=i;

    int q=m+1;

    int k=0;

    while(p<=m && q<=j)

    {

        if(a[p]<=a[q])

            aux[k++]=a[p++];

        else

            {aux[k++]=a[q++];nr+=m-p+1;}

    }

    while(p<=m)

        aux[k++]=a[p++];

    while(q<=j)

        aux[k++]=a[q++];



    for(int l=i; l<=j; l++)

        a[l]=aux[l-i];



    return nr;



}



int mergesort(int a[],int i,int j)

{

    int nrinv=0;

    if(i<j)

    {

        int m=i+(j-i)/2;

        nrinv=mergesort(a,i,m);

        nrinv+=mergesort(a,m+1,j);

        nrinv+=interclasare(a,i,j,m);

    }

    return nrinv%9917;

}

int main()

{

    ifstream in("inv.in");

    ofstream out("inv.out");

    int N;

    in>>N;

    int a[100010];

    for(int i=0;i<N;i++)

        in>>a[i];

    out<<mergesort(a,0,N-1);



    return 0;

}
