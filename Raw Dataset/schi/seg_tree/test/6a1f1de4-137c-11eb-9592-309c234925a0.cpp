#include <iostream>
using namespace std;







int output[30050];

int v[30050];

int tree[4 * 30050];



void buildTree(int node, int L, int R) {

 if (L == R) {

  tree[node] = 1;

 }

 else {

  int mid = (L + R) / 2;

  buildTree(node * 2, L, mid);

  buildTree(node * 2 + 1, mid + 1, R);

  tree[node] = tree[node * 2] + tree[node * 2 + 1];

 }

}



void update(int node, int L, int R, int pos, int val) {

 if (L == R) {

  output[R] = val;

  tree[node] = 0;

 }

 else {

  int mid = (L + R) / 2;

  if (tree[node * 2] >= pos) {

   update(node * 2, L, mid, pos, val);

  }

  else {

   update(node * 2 + 1, mid + 1, R, pos - tree[node * 2], val);

  }

  tree[node] = tree[node * 2] + tree[node * 2 + 1];

 }

}



FILE * fin, * fout;



int main() {

    fin = fopen("schi.in","r");

    fout = fopen("schi.out","w");

 int N;

 fscanf(fin,"%d",&N);



 buildTree(1, 0, N-1);



 for (int i = 0; i < N; i++) {

  fscanf(fin,"%d",v+i);

 }



 for (int i = N - 1; i >= 0; i--) {

  update(1, 0, N - 1, v[i], i + 1);

 }



 for (int i = 0; i < N; i++) {

  fprintf(fout,"%d\n",output[i]);

 }



 fclose(fin);

 fclose(fout);

 return 0;



}
