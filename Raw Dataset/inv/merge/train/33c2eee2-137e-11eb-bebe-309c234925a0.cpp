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



void MergeSort(int vectorr[], int stanga, int dreapta)

{

 if(stanga < dreapta)

 {

  int mijloc = (stanga + dreapta) / 2;

  MergeSort(vectorr, stanga , mijloc);

  MergeSort(vectorr, mijloc + 1 , dreapta);

  int i = stanga, j = mijloc + 1, k = 0;



  while( i <= mijloc && j <= dreapta )

   if( vectorr[i] <= vectorr[j])

    temp[++k] = vectorr[i++];

   else

   {

    temp[++k] = vectorr[j++];

    nr_inv = (nr_inv + mijloc - i + 1)%9917;

   }



  while(i <= mijloc)

   temp[++k] = vectorr[i++];



  while(j <= dreapta)

   temp[++k] = vectorr[j++];



  for(i = stanga , j = 1 ; i <= dreapta ; i ++ , j ++)

   vectorr[i] = temp[j];

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
