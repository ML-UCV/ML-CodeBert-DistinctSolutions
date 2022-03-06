#include <bits/stdc++.h>
using namespace std;



const int MAXN = (int) 2e6 + 5;



char str[2 * MAXN + 1];

int z[2 * MAXN + 1];



int main() {
 ifstream cin("strmatch.in");

 ofstream cout("strmatch.out");

 int i;

 ios::sync_with_stdio(false);

 cin.tie(0), cout.tie(0);



 cin >> (str + 1);

 int n = strlen(str + 1);

 str[n + 1] = '@';

 cin >> (str + n + 2);

 int m = strlen(str + n + 2);



 int sz = n + m + 1, pos = 0;

 z[1] = sz;

 for(i = 2; i <= sz; i++) {

  if(pos + z[pos] >= i) {

   z[i] = min(pos + z[pos] - i, z[i - pos + 1]);

  }

  while(i + z[i] <= sz && str[i + z[i]] == str[z[i] + 1]) {

   z[i]++;

  }

  if(i + z[i] > pos + z[pos]) {

   pos = i;

  }

 }

 vector <int> sol;

 int ans = 0;

 for(i = n + 2; i <= sz; i++) {

  if(z[i] == n) {

   ans++;

   if(sol.size() < 1000) {

    sol.push_back(i - n - 2);

   }

  }

 }

 cout << ans << "\n";

 for(auto it : sol) {

  cout << it << " ";

 }



 return 0;

}
