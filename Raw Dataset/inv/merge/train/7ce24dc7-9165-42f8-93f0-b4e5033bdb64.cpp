#include <iostream>
#include <fstream>
#include <vector>




using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");



int n;

vector <int> v, M;

long long int inv;

void citire()

{

 int i;

 f >> n;

 v.resize(n + 3);

 M.resize(n + 3);

 for (i = 1; i <= n; i++)

 {

  f >> v[i];

 }

 f.close();

}

void merge(int l1, int r1, int l2, int r2)

{

 int i, j, k;

 i = l1; j = l2; k = 1;

 while (i <= r1 && j <= r2)

 {

  if (v[j] < v[i])

   {

    M[k] = v[j];

    k++; j++;

    inv += (r1 - i + 1);

   }

  else

   {

    M[k] = v[i];

    i++; k++;

   }

 }

 while (i <= r1)

 {

  M[k] = v[i];

  k++; i++;

 }

 while (j <= r2)

 {

  M[k] = v[j];

  k++; j++;

 }

 for (i = l1, j = 1; i <= r2; j++, i++)

 {

  v[i] = M[j];

  M[j] = 0;

 }

}

void divide(int left, int right)

{

 if (right == left)

 {

  return;

 }

 int mid = (left + right) / 2;

 divide(left, mid);

 divide(mid + 1, right);

 merge(left, mid, mid + 1, right);

}

int main()

{

 citire();

 divide(1, n);

 g << inv % 9917;

 g.close();

 return 0;

}
