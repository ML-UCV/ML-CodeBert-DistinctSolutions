#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");



const int kMax = 100005;

const int kMod = 9917;

int v[kMax], rez[kMax];



int merge_halves(int a[], int b[], int left, int right, int m) {

 int size_a = m - left + 1;

 int size_b = right - m;
 int idxa = 0, idxb = 0, nrInv = 0, idxRez = 0;



 for(idxa = 0; idxa < size_a && idxb < size_b; idxRez++) {

  if(a[idxa] > b[idxb]) {

   rez[idxRez] = b[idxb++];

   nrInv += size_a - idxa;

  } else {

   rez[idxRez] = a[idxa++];

  }

 }



 for(; idxa < size_a; idxRez++, idxa++) {

  rez[idxRez] = a[idxa];

 }



 for(; idxb < size_b; idxRez++, idxb++) {

  rez[idxRez] = b[idxb];

 }
 for(int i = 0; i < size_b + size_a; i++) {

  a[i] = rez[i];

 }



 return nrInv;

}



int merge_sort(int left, int right) {

 if(left == right)

  return 0;



 int middle = (left + right) / 2;

 int inv_left = merge_sort(left, middle);

 int inv_right = merge_sort(middle + 1, right);



 int crt_inv = merge_halves(v + left, v + middle + 1, left, right, middle);

 return (crt_inv + inv_right + inv_left) % kMod;

}



int main() {

 int n;

 f >> n;

 for(int i = 0; i < n; i++) {

  f >> v[i];

 }



 g << merge_sort(0, n - 1);

 return 0;

}
