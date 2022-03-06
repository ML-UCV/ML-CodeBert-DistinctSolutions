#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef long long ll;
using namespace std;
ll ceildiv(ll one, ll two) {
 if (one % two == 0) {return one / two;}
 else {return one / two + 1;}
} ll power(ll n, ll pow, ll m) {
 if (pow == 0) return 1;
 if (pow % 2 == 0) {
  ll x = power(n, pow / 2, m);
  return (x * x) % m;
 }
 else return (power(n, pow - 1, m) * n) % m;
} ll gcd(ll a, ll b) {
 if (!b)return a;
 return gcd(b, a % b);
} ll factorial(ll n, ll mod) {
 if (n > 1)
  return (n * factorial(n - 1, mod)) % mod;
 else
  return 1;
} ll lcm(ll a, ll b) {
 return (a * b) / gcd(a, b);
} vector<ll> read(ll n) {vector<ll> a; for (ll i = 0; i < n; i++) { ll x; cin >> x; a.push_back(x);} return a;}vector<vector<ll>> adj;void init(ll n) {for (ll i = 0; i <= n; i++) { vector<ll> a; adj.push_back(a);}}

bool delim(char c) {
 return c == ' ';
}

bool is_op(char c) {
 return c == '+' || c == '-' || c == '*' || c == '/';
}

ll priority (char op) {
 if (op == '+' || op == '-')
  return 1;
 if (op == '*' || op == '/')
  return 2;
 return -1;
}

void process_op(stack<ll>& st, char op) {
 ll r = st.top(); st.pop();
 ll l = st.top(); st.pop();
 switch (op) {
  case '+': st.push(l + r); break;
  case '-': st.push(l - r); break;
  case '*': st.push(l * r); break;
  case '/': st.push(l / r); break;
 }
}

ll evaluate(string& s) {
 stack<ll> st;
 stack<char> op;
 for (ll i = 0; i < (ll)s.size(); i++) {
  if (delim(s[i]))
   continue;

  if (s[i] == '(') {
   op.push('(');
  } else if (s[i] == ')') {
   while (op.top() != '(') {
    process_op(st, op.top());
    op.pop();
   }
   op.pop();
  } else if (is_op(s[i])) {
   char cur_op = s[i];
   while (!op.empty() && priority(op.top()) >= priority(cur_op)) {
    process_op(st, op.top());
    op.pop();
   }
   op.push(cur_op);
  } else {
   ll number = 0;
   while (i < (ll)s.size() && isalnum(s[i]))
    number = number * 10 + s[i++] - '0';
   --i;
   st.push(number);
  }
 }

 while (!op.empty()) {
  process_op(st, op.top());
  op.pop();
 }
 return st.top();
}

int32_t main() {
 ios_base::sync_with_stdio(false);cin.tie(0);;
 freopen("evaluare.in", "r", stdin);
 freopen("evaluare.out", "w", stdout);
 string s;
 cin >> s;
 cout << evaluate(s) << '\n';
}
