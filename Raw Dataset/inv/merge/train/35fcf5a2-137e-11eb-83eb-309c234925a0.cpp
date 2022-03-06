#include <iostream>
#include <fstream>
#include <algorithm>




using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");

long X[100001],N,cnt,secv,nr,tmp[100001];



void MergeSort(long A[], int st, int dr)

{

 if(st < dr)

 {

  int m = (st + dr) / 2;

  MergeSort(A, st , m);

  MergeSort(A, m + 1 , dr);

  int i = st;

  int j = m + 1;

  int k = 0;

  while( i <= m && j <= dr )

   if( A[i] <= A[j])

    tmp[++k] = A[i++];

   else

    {

        tmp[++k] = A[j++];

        nr = (nr+m-i+1)%9917;

                }

  while(i <= m)

   tmp[++k] = A[i++];

  while(j <= dr)

   tmp[++k] = A[j++];

        j=1;

  for(i = st; i<=dr ; i++ , j++)

   A[i] = tmp[j];

 }

}

int main()

{

    f >> N;

    for ( int i=1;i<=N;i++ )

        f >> X[i];

    MergeSort(X,1,N);

    g << nr;

    return 0;

}
