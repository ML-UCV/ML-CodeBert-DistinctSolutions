#include <bits/stdc++.h>




using namespace std;



ifstream in("swap.in");

ofstream out("swap.out");



string s1, s2; long long ans; int arb[100100];

queue <int> q[30];



void add(int i){

 for(; i <= 100000; i += (i & (-i))) arb[i]++;

}



int get(int i){

 int ans = 0;

 for(; i; i -= (i & (-i))) ans += arb[i];

 return ans;

}



int main(){

 getline(in, s1);

 getline(in, s2);

 for(int i = 0; i < s1.size(); i++) q[s1[i] - 'a'].push(i+1);

 for(int i = 0; i < s2.size(); i++){

  if(q[s2[i] - 'a'].empty()) return out << -1, 0;

  int pos = q[s2[i] - 'a'].front();

  q[s2[i] - 'a'].pop();

  ans += pos - i - 1 + get(s2.size()) - get(pos);

  add(pos);

 }

 out << ans;

 return 0;

}
