#include<iostream>
#include <fstream>
#include<algorithm>
#include <vector>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



const int maxn = 400100;



int GR[maxn], X[maxn], Y[maxn], C[maxn];

int N, M, ANS, IND[maxn];

vector<pair<int, int>> add;

int grupa(int i) {

 if (GR[i] == i) return i;

 GR[i] = grupa(GR[i]);

 return GR[i];

}



void reuniune(int i, int j) {

 GR[grupa(i)] = grupa(j);

}



bool cmpf(int i, int j) {

 return(C[i] < C[j]);

}



int main() {

 fin >> N >> M;

 for (int i = 1; i <= M; ++i) {

  fin >> X[i] >> Y[i] >> C[i];

  IND[i] = i;

 }

 for (int i = 1; i <= N; ++i) GR[i] = i;

 sort(IND + 1, IND + M + 1, cmpf);



 for (int i = 1; i <= M; ++i) {



  if (grupa(X[IND[i]]) != grupa(Y[IND[i]])) {

   ANS += C[IND[i]];

   add.push_back({ X[IND[i]], Y[IND[i]] });

   reuniune(X[IND[i]], Y[IND[i]]);

  }

 }

 fout << ANS << "\n";

 fout << add.size() << "\n";

 for (int i = 0; i < add.size(); ++i)

  fout << add[i].first << " " << add[i].second << "\n";



 return 0;

}
