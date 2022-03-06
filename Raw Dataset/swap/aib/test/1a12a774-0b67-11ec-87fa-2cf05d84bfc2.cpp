#include <fstream>
#include <cstring>
#include <queue>






using namespace std;



int N,AIB[50100],Sol;

char S[50100],S2[50100];

queue <int> Index[26];



int Query(int nod) {



 int Rez=0;



 while(nod>0) {

  Rez+=AIB[nod];

  nod-=(nod&-nod);

  }



 return Rez;



}

void Update(int nod) {



 while(nod<=N) {

  AIB[nod]++;

  nod+=(nod&-nod);

  }



}

void Afis() {



 ofstream out("swap.out");

 out<<Sol<<'\n';

 out.close();



}

void Solve() {



 int i,Val;



 for(i=1;i<=N;i++) {



  if(Index[(S2[i]-97)].empty())

   {Sol=-1;return;}



  Val=Index[(S2[i]-97)].front();

  Sol+=i-1-Query(Val-1);

  Update(Val);

  Index[(S2[i]-97)].pop();



  }



}

void Init() {



 for(int i=1;i<=N;i++)

  Index[(S[i]-97)].push(i);



}

void Citire() {



 ifstream in("swap.in");

 in.getline(S+1,50100);

 in.getline(S2+1,50100);

 N=strlen(S+1);

 in.close();



}

int main() {



 Citire();

 Init();

 Solve();

 Afis();



 return 0;



}
