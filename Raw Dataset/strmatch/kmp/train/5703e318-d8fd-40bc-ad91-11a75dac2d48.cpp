#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



int const maxim = 2000005;



vector<int> stocare;





void compute_lps(string model, int dimensiune_model, int* lps) {



 int len = 0;

 lps[0] = 0;



 int i = 1;

 while (i < dimensiune_model) {

  if (model[i] == model[len]) {

   len++;

   lps[i] = len;

   i++;

  }

  else {

   if (len != 0) {

    len = lps[len - 1];

   }

   else {

    lps[i] = 0;

    i++;

   }

  }

 }

}





void kmp(string model, string sir) {



 int dimensiune_model = model.size();

 int dimensiune_sir = sir.size();



 int* lps= new int[dimensiune_model];



 compute_lps(model, dimensiune_model, lps);



 int index_model = 0;

 int index_sir = 0;

 while (index_sir < dimensiune_sir) {

  if (model[index_model] == sir[index_sir]) {

   index_model++;

   index_sir++;

  }

  if (index_model == dimensiune_model) {

   stocare.push_back(index_sir - index_model);

   index_model = lps[index_model - 1];

  }

  else if (index_sir < dimensiune_sir && model[index_model] != sir[index_sir]) {

   if (index_model == 0) {

    index_sir++;

   }

   else {

    index_model = lps[index_model - 1];

   }

  }

 }

}



void afisare() {

 out << stocare.size() << endl;

 int x = stocare.size();

 for (size_t i = 0; i < min(x, 1000); i++) {

  out << stocare[i] << " ";

 }

}







int main() {

 string model;

 string sir;



 in >> model;

 in >> sir;



 kmp(model, sir);

 afisare();

 return 0;

}
