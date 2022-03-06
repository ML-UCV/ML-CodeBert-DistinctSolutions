#include <bits/stdc++.h>



typedef long long ll;



const ll mod=1e9+7;



const int dx[] = {0, 1, 0, -1};

const int dy[] = {1, 0, -1, 0};

const int nmax=1e7+5;
using namespace std;



ll t[nmax*4];

int a[nmax],b[nmax];



ifstream f("schi.in");

ofstream g("schi.out");



void build(int v, int tl, int tr) {

 if (tl==tr) {

  t[v]=1;

 }

 else {

  int tm=(tl+tr)/2;

  build(2*v,tl,tm);

  build(2*v+1,tm+1,tr);

  t[v]=t[2*v]+t[2*v+1];

 }

}



void update(int v, int tl, int tr, int val, int pos) {

 if (tl==tr) {

  t[v]=0;

  b[tl]=val;

  return;

 }

 else {

  int tm=(tl+tr)/2;

  if (pos<=t[2*v]) {

   update(2*v,tl,tm,val,pos);

  }

  else {

   update(2*v+1,tm+1,tr,val,pos-t[2*v]);

  }

  t[v]=t[2*v]+t[2*v+1];

 }

}



int main() {

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

 int n;

 f >> n;

 build(1,1,n);

 for (int i=1; i<=n; i++) {

  f >> a[i];

 }

 for (int i=n; i>=1; i--) {

  update(1,1,n,i,a[i]);

 }

 for (int i=1; i<=n; i++) {

  g << b[i] << '\n';

 }

}
