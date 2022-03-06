#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



const int N = 30005;



int n;

int arb[4 * N], loc[N], clasament[N];



void build(int left = 1, int right = n, int node = 1)

{

 if (left == right)

 {

  arb[node] = 1;

  return;

 }



 int mid = (left + right) / 2;



 build(left, mid, node * 2);

 build(mid + 1, right, node * 2 + 1);

 arb[node] = arb[node * 2] + arb[node * 2 + 1];

}



int GetPlace(int val, int left = 1, int right = n, int node = 1)

{

 arb[node]--;



 if (left == right)

 {

  return left;

 }



 int mid = (left + right) / 2;



 if (val <= arb[node * 2])

 {

  return GetPlace(val, left, mid, node * 2);

 }

 else

 {

  return GetPlace(val - arb[node * 2], mid + 1, right, node * 2 + 1);

 }

}



int main()

{

 fin >> n;



 for (int i = 1; i <= n; i++)

 {

  fin >> loc[i];

 }



 build();



 for (int i = n; i >= 1; i--)

 {

  clasament[GetPlace(loc[i])] = i;

 }



 for (int i = 1; i <= n; i++)

 {

  fout << clasament[i] << '\n';

 }

}
