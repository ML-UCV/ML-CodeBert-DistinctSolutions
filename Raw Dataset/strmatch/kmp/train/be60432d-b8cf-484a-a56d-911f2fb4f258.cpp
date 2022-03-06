#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



string a, b;

int pr[2000041];

void precalc(){

 int q = 0;

 for(int i = 1; i < a.size(); ++i){

  while(a[i] != a[q] && q>0){

   q = pr[q-1];

  }

  if(a[i] == a[q]){

   q++;

  }

  pr[i] = q;

 }

}



int cer=0;

vector<int> sol;

void postcalc(){

 int i = 0;

 for(int j = 0; j < b.size(); ++j){

  while(a[i] != b[j] && i>0){

   i = pr[i-1];

  }

  if(a[i] == b[j]){

   i++;

  }

  if(i == a.size()){

   cer++;

   if(sol.size() < 1000){

    sol.push_back(j-a.size()+1);

   }

   i = pr[i-1];

  }

 }

}



int main(){

 fin >> a >> b;

 precalc();

 postcalc();

 fout << cer << "\n";

 for(auto a : sol){

  fout << a << " ";

 }

 return 0;

}
