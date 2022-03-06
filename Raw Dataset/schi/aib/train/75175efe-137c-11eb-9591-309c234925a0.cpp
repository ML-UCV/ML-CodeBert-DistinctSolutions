#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int ey(int a){

 return a & -a;

}



int n;

int aib[30041];



void chit(int p, int a){

 for(int i = p; i <= n; i += ey(i)){

  aib[i] += a;

 }

}



int reit(int p){

 int s = 0;

 for(int i = p; i > 0; i -= ey(i)){

  s += aib[i];

 }

 return s;

}



int yo;

void shi(){

 yo = 1;

 while(yo < n){

  yo <<= 1;

 }

}



int bs(int a){

 int p = 0;

 int ap = 0;

 for(int i = yo; i > 0; i >>= 1){

  int np = p+i;

  if(np <= n){

   int na = a-aib[np];

   if(na > 0){

    a = na;

    p = np;

   }else if(na == 0){

    ap = np;

   }

  }

 }

 return ap;

}



int va[30041], sol[30041];



int main(){

 fin >> n;

 for(int i = 1; i <= n; ++i){

  fin >> va[i];

  chit(i, 1);

 }

 shi();

 for(int i = n; i >= 1; --i){

  int pos = bs(va[i]);

  sol[pos] = i;

  chit(pos, -1);

 }

 for(int i = 1; i <= n; ++i){

  fout << sol[i] << "\n";

 }

 return 0;

}
