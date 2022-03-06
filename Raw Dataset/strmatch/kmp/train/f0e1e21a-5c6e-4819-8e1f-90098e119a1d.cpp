#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.first << ' ' << p.second << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
const long double PI = acos(-1);

vector<int> prefix(string const &A){
  vector<int> pr(A.size()+1, 0);
  int k = 0;

  for (int i=2;i<=A.size();i++){
    while (k && A[k] != A[i-1]) k = pr[k];
    if (A[k] == A[i-1]) k++;
    pr[i] = k;
  }
  return pr;
}

vector<int> KMP(string const &A, string const &B){
  vector<int> pr = prefix(B), ans;
  int k = 0;
  for (int i=1;i<=A.size();i++){
    while (k && B[k] != A[i-1]) k = pr[k];
    if (B[k] == A[i-1]) k++;
    if (k == B.size()){
      ans.push_back(i - k);
    }
  }

  return ans;
}


int main(){
  ios::sync_with_stdio(false);

  freopen("strmatch.in","r",stdin);
  freopen("strmatch.out","w",stdout);

  string A,B;
  cin >> B >> A;
  vector<int> ans = KMP(A,B);
  cout << ans.size() << '\n';
  while (ans.size() > 1000) ans.pop_back();
  for (auto it : ans) cout << it << ' ';
  cout << '\n';
  return 0;
}
