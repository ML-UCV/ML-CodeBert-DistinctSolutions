#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <memory>
#include <cassert>
using namespace std;



int S[18][250001];



using namespace std;





class Input_Reader {

private:

 FILE *__inputFile;

 long long fileSize, buffSize;

 unique_ptr < char[] > buffer;

 int Poz = 0;



 inline long long min(const long long &a, const long long &b) { return a < b ? a : b; }



 inline void CountBytes(const string &fileName) {

  FILE * fin = fopen(fileName.c_str(), "r");

  fseek(fin, 0, SEEK_END);

  fileSize = ftell(fin);

  fclose(fin);

 }



 inline bool isFigure(char x) {

  return x >= '0' && x <= '9';

 }



 inline void JumpOver() {

  while (!isFigure(buffer[Poz])) {

   if (Poz + 1 == 100000)fread(buffer.get(), sizeof(char), min(fileSize, 100000), __inputFile), buffSize = strlen(buffer.get()), Poz = -1;

   ++Poz;

  }

 }



 inline int Parse() {

  int number = 0;

  while (!isFigure(buffer[Poz]))JumpOver();

  while (isFigure(buffer[Poz])) {

   number = number * 10 + buffer[Poz] - '0';

   ++Poz;

   if (Poz == 100000)fread(buffer.get(), sizeof(char), min(fileSize, 100000), __inputFile), buffSize = strlen(buffer.get()), Poz = 0;

  }

  return number;

 }



public:



 explicit Input_Reader(const string &str, const string &mode) {

  __inputFile = fopen(str.c_str(), mode.c_str());



  buffer = move(make_unique<char[]>(100000));

  CountBytes(str);

  fread(buffer.get(), sizeof(char), min(fileSize, 100000), __inputFile);



  buffSize = strlen(buffer.get());



 }



 Input_Reader &operator >> (int &value) {

  value = Parse();

  return *this;

 }



};





class Solver {



public:



 explicit Solver(string&& in, string&& out) {



  FILE *fout = fopen(out.c_str(), "w");

  Input_Reader fin{ in.c_str(), "r" };



  int Q;

  vector <int> ancestors;



  fin >> N >> Q;





  ancestors.resize(N + 1);

  for (int i = 1; i <= N; ++i) {

   fin >> ancestors[i];

  }





  __process(ancestors);





  int P, X;

  while (Q--) {

   fin >> X >> P;

   fprintf(fout, "%d\n", __solve(X, P));

  }

 }



private:



 int __lg(int number) const {

  return floor(log2(number));

 }



 void __process(const vector<int>& ancestors) {
  int log = __lg(N);

  for (int i = 1; i <= N; ++i) {



   S[0][i] = ancestors[i];





   for (int j = 1; j <= log; ++j) {

    if (!S[j - 1][i]) {

     break;

    }

    S[j][i] = S[j - 1][S[j - 1][i]];

   }

  }



 }



 int __solve(int Q, int P) {



  for (int j = 18; j >= 0 && Q; --j) {

   if (!(P & (1 << j))) {

    continue;

   }

   Q = S[j][Q];

  }



  return Q;

 }



 int N;

};





int main() {

 Solver{

  "stramosi.in",

  "stramosi.out"

 };

}
