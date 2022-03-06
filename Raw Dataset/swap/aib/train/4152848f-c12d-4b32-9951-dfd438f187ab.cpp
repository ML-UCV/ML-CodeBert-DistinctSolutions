#include<bits/stdc++.h>


using namespace std;

int arb[100020];

queue<int> q[26];

void add(int i){

 for(;i<100000;i+=(i&(-i))) arb[i]++;

}

int get(int i){

 int ans =0;

 for(;i;i-=(i&(-i))) ans+=arb[i];

 return ans;

}

int main(){

 string a, b;

 int rs=0;

 ifstream f("swap.in");

 ofstream g("swap.out");

 f>>a>>b;

 int n=a.length();

 int m=b.length();

 for(int i=0;i<n;i++)q[a[i]-'a'].push(i+1);

 for(int i=0;i<m;i++){

  if(q[b[i]-'a'].empty()) {

  g<<-1;

  return 0;

  }

  int pos;

  pos=q[b[i]-'a'].front();

  q[b[i]-'a'].pop();

  rs+=pos-i-1+get(a.length())-get(pos);

  add(pos);

 }

 g<<rs;

 return 0;

}
