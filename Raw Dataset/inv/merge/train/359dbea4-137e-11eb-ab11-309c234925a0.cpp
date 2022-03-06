#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");



const int NR = 100001;

int temp[NR], nr_inv = 0;



void MergeSort(int v[], int l, int r)

{

 if(l < r)

 {

  int mid = (l + r) / 2;

  MergeSort(v, l , mid);

  MergeSort(v, mid + 1 , r);

  int i = l, j = mid + 1, k = 0;

  while( i <= mid && j <= r )

   if( v[i] <= v[j])

    temp[++k] = v[i++];

   else

   {

    temp[++k] = v[j++];

    nr_inv = (nr_inv + mid - i + 1)%9917;

   }

  while(i <= mid)

   temp[++k] = v[i++];

  while(j <= r)

   temp[++k] = v[j++];

  for(i = l , j = 1 ; i <= r ; i ++ , j ++)

   v[i] = temp[j];

 }

}



int main()

{



    int n, v[NR];



    f>>n;

    for(int i = 1; i <= n; i++)

        f>>v[i];



    MergeSort(v,1,n);



    g<<nr_inv;







    f.close();

    g.close();

    return 0;





}
