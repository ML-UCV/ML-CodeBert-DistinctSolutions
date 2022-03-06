#include <fstream>
#include <iostream>
#include <string>
using namespace std;



int N, aib[60000];
string s1, s2;

ifstream fin("swap.in");
ofstream fout("swap.out");

void insert_aib(int poz, int elem) {
 while (poz <= N) {
  aib[poz] += elem;
  poz += poz & (-poz);
 }
}

int query (int poz) {
 int sum = 0;
 while (poz > 0) {
  sum += aib[poz];
  poz -= poz & (-poz);
 }
 return sum;
}

void doSol(int perm[60000]) {
 int rez = 0;

 for (int i = 1; i <= N; ++i) {
  rez += query (N) - query (perm[i]);
  insert_aib(perm[i], 1);
 }
 fout << rez;
}

int sol[30][60000], curPoz[30];
int perm[60000];

int main() {
 getline(fin, s1);
 getline(fin, s2);

 N = s1.size();

 for (int i = 0; i < s2.size(); ++i) {
  int v = s2[i] - 'a';
  sol[v][++sol[v][0]] = i + 1;
 }

 for (int i = 0; i < s1.size(); ++i) {
  int v = s1[i] - 'a';
  perm[i + 1] = sol[v][++curPoz[v]];
 }


 for (int i = 0; i < 30; ++i)
  if (curPoz[i] != sol[i][0]) {
   fout << -1;
   return 0;
  }

 doSol (perm);

 return 0;
}
