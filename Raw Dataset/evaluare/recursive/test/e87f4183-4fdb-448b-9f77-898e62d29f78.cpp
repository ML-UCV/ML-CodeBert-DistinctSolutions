#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



string sir;



int poz;



int termen();

int factor();



int expr() {

 int val = termen();



 while (poz < sir.size()) {

  if (sir[poz] == '+') {

   poz++;

   val += termen();

  }

  else if (sir[poz] == '-') {

   poz++;

   val -= termen();

  }

  else break;

 }

 return val;

}



int termen() {

 int val = factor();



 while (poz < sir.size()) {

  if (sir[poz] == '*') {

   poz++;

   val *= factor();

  }

  else if (sir[poz] == '/') {

   poz++;

   val /= factor();

  }

  else break;

 }

 return val;

}



int factor() {

 int val = 0;



 if (sir[poz] == '(') {

  ++poz;

  val = expr();

  ++poz;

 }

 else {

  while (poz < sir.size() && '0' <= sir[poz] && sir[poz] <= '9') {

   val = val * 10 + int(sir[poz] - '0');

   ++poz;

  }

 }

 return val;

}



int main() {



 fin >> sir;



 fout << expr();



 return 0;

}
