#include <iostream>
#include <fstream>
#include <deque>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>






using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



stack<int> S;



vector<int> G[100005], GT[100005], CTC[100005];



int N, M, nrCTC;

int checked[100005];



void Read() {

 fin >> N >> M;



 for (int i = 1; i <= M; ++i) {

  int x, y;

  fin >> x >> y;

  G[x].push_back(y);

  GT[y].push_back(x);

 }

}



void DFSP(int nod) {

 checked[nod] = 1;



 for (int i = 0; i < G[nod].size(); ++i) {

  int vecin = G[nod][i];



  if (!checked[vecin])

   DFSP(vecin);

 }

 S.push(nod);

}



void DFSM(int nod) {

 checked[nod] = 2;

 CTC[nrCTC].push_back(nod);



 for (int i = 0; i < GT[nod].size(); ++i) {

  int vecin = GT[nod][i];



  if (checked[vecin] == 1)

   DFSM(vecin);

 }

}



void Solve() {

 for (int i = 1; i <= N; ++i)

  if (!checked[i])

   DFSP(i);



 while (!S.empty()) {

  int nod = S.top();

  if (checked[nod] == 1) {

   nrCTC++;

   DFSM(nod);

  }

  S.pop();

 }

}



void Print() {

 fout << nrCTC << " ";



 for (int i = 1; i <= nrCTC; ++i) {

  for (unsigned int j = 0; j < CTC[i].size(); ++j)

   fout << CTC[i][j] << " ";

  fout << "\n";

 }

}



int main() {



 Read();

 Solve();

 Print();



 return 0;

}
