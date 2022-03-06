#include <bits/stdc++.h>






using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");

int aux;

int v[100001], u[100001];



void interclasare(int st, int dr)

{

 int mij = (st + dr) / 2;

 int i = st;

 int j = mij + 1;

 int k = 0;



 while (i <= mij && j <= dr)

 {

  if (v[i] <= v[j])

  {

   u[k] = v[i];

   i++;

   k++;

  }

  else {

   aux = (aux + mij - i + 1) % 9917;

   u[k] = v[j];

   k++;

   j++;



  }

 }



 while (i <= mij)

 {

  u[k] = v[i];

  i++;

  k++;

 }



 while (j <= mij)

 {

  u[k] = v[j];

  j++;

  k++;

 }



 for (int i = 0; i < k; i++)

  v[i + st] = u[i];

}





void mergesort(int st, int dr)

{

 if (st < dr)

 {

  int mij = (st + dr) / 2;

  mergesort(st, mij);

  mergesort(mij + 1, dr);

  interclasare(st, dr);

 }

}



int main()

{

 int n;



 f >> n;



    for(int i = 0; i < n; i++)

        f >> v[i];



 mergesort(0, n - 1);



    g << aux << '\n';

 return 0;

}
