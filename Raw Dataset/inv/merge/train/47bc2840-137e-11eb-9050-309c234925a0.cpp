#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair< ll , ll > PII;

ll n, ans;
vector < int > a;

void divide(int st, int dr){
 if (st >= dr) return ;

 int mid = (st + dr) >> 1;

 divide(st, mid); divide(mid + 1, dr);

 vector < int > c;
 int p1 = st, p2 = mid + 1;

 while (p1 <= mid && p2 <= dr){
  if (a[p1] <= a[p2]){
   c.push_back(a[p1]);
   ans = (ans + p2 - mid - 1) % 9917;
   p1++;
  }else{
   c.push_back(a[p2]);
   p2++;
  }
 }

 while (p1 <= mid){
  c.push_back(a[p1++]);
  ans = (ans + p2 - mid - 1) % 9917;
 }

 while (p2 <= dr) c.push_back(a[p2++]);

 int pos = 0;
 for (int i = st; i <= dr; i++){
  a[i] = c[pos++];
 }
}

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);

 ifstream cin("inv.in");
 ofstream cout("inv.out");

 cin >> n;
 a.push_back(0);

 for (int i = 1, x; i <= n; i++){
  cin >> x;
  a.push_back(x);
 }

 divide(1, n);

 cout << ans;

 return 0;
}
