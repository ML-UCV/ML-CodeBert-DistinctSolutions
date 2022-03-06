#include <iostream>
#include <fstream>


using namespace std;



ifstream in("schi.in");

ofstream out("schi.out");



const int NMAX = 30020;

int tree[4 * NMAX], rez[NMAX], v[NMAX];



void buildArbInt(int node, int st, int dr) {

 if (st == dr) {

  tree[node] = 1;

 }

 else {

  int mid = (st + dr) / 2;

  buildArbInt(node * 2, st, mid);

  buildArbInt(node * 2 + 1, mid + 1, dr);



  tree[node] = tree[node * 2] + tree[node * 2 + 1];

 }

}



void update(int node, int st, int dr, int pos, int val) {

 if (st == dr) {

  rez[st] = val;

  tree[node] = 0;

 }

 else {

  int mid = (st + dr) / 2;

  if (tree[node * 2] >= pos) {

   update(node * 2, st, mid, pos, val);

  }

  else {

   update(node * 2 + 1, mid + 1, dr, pos - tree[node * 2], val);

  }

  tree[node] = tree[node * 2] + tree[node * 2 + 1];

 }

}



int main() {

 int n;

 in >> n;

 buildArbInt(1, 0, n-1);

 for (int i = 0; i < n; i++) {

  in >> v[i];

 }

 for (int i = n - 1; i >= 0; i--) {

  update(1, 0, n - 1, v[i], i + 1);

 }

 for (int i = 0; i < n; i++) {

  out << rez[i] << '\n';

 }

 return 0;

}
