#include <bits/stdc++.h>
using namespace std;



ifstream fin("party.in");

ofstream fout("party.out");



int n, nr;

stack<int> st;

vector<int> G[205], GT[205];

bool viz[205], stare[205];



inline int negat(int first) {

 if(first<=n) return first+n;

 return first-n;

}



void DFSp(int first) {

 viz[first] = 1;



 for(auto it:G[first])

  if(!viz[it]) DFSp(it);

 st.push(first);

}



void DFSm(int first) {

 viz[first] = 0;



 if(first > n) {

  ++nr;

  stare[negat(first)] = 1;

 }



 for(auto it:GT[first])

  if(viz[it]) DFSm(it);

}



int main() {

 int m,i,first,second,t;



 fin>>n>>m;

 for(i=1;i<=m;++i) {

  fin>>first>>second>>t;



  if(t == 1) second = negat(second);

  else if(t == 2) first = negat(first);

  else if(t == 3) first = negat(first), second = negat(second);



  G[negat(first)].push_back(second);

  G[negat(second)].push_back(first);



  GT[first].push_back(negat(second));

  GT[second].push_back(negat(first));

 }



 for(i=1;i<=2*n;++i)

  if(!viz[i])

   DFSp(i);



 while(!st.empty()) {

  if(viz[st.top()] && viz[negat(st.top())])

   DFSm(st.top());

  st.pop();

 }



 fout << nr << '\n';

 for(i=1;i<=2*n;++i)

  if(stare[i]) fout << i << '\n';



 return 0;

}
