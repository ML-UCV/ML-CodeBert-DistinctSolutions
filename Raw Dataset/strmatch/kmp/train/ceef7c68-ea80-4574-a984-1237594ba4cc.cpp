#include <bits/stdc++.h>
using namespace std;



const int MAXN = (int) 2e6 + 5;



char pat[MAXN + 1], str[MAXN + 1];

int pi[MAXN + 1];



int main() {
 ifstream cin("strmatch.in");

 ofstream cout("strmatch.out");

 int i;

 ios::sync_with_stdio(false);

 cin.tie(0), cout.tie(0);



 cin >> (pat + 1) >> (str + 1);

 int n = strlen(pat + 1), m = strlen(str + 1);

 int k = 0;

 for(i = 2; i <= n; i++) {

  while(k > 0 && pat[k + 1] != pat[i]) {

   k = pi[k];

  }

  k += (pat[k + 1] == pat[i]);

  pi[i] = k;

 }

 vector <int> sol;

 int ans = 0;

 k = 0;

 for(i = 1; i <= m; i++) {

  while(k > 0 && pat[k + 1] != str[i]) {

   k = pi[k];

  }

  k += (pat[k + 1] == str[i]);

  if(k == n) {

   ans++;

   if(sol.size() < 1000)

    sol.push_back(i - n);

  }

 }

 cout << ans << "\n";

 for(auto it : sol) {

  cout << it << " ";

 }



 return 0;

}
