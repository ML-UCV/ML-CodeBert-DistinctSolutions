#include <bits/stdc++.h>

int arb[100100],rs;
using namespace std;
int get(int i){
 int ans=0;
 for(;i;i-=(i & (-i))) ans+=arb[i];
 return ans;
}
void add(int i){
 for(;i<100000;i+=(i & (-i))) arb[i]++;
}
queue<int> Q[30];
string A,B;
int main(){
 ifstream cin("swap.in");
 ofstream cout("swap.out");
 cin >> A >> B;
 for(int i = 0;i<A.length();i++) Q[A[i]-'a'].push(i+1);
 for(int i = 0;i<B.length();i++){
  if(Q[B[i]-'a'].empty()) return cout << -1,0;
  int pos = Q[B[i]-'a'].front(); Q[B[i]-'a'].pop();
  rs+=pos-i-1+get(A.length())-get(pos);
  add(pos);
 }
 cout << rs;
}
