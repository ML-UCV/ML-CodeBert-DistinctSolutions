#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

constexpr int my_negate(const int x, const int n){
 return (x < n) ? x+n : x-n; }

constexpr int undecided = 2, fa = 0, tr = 1;

class managed_stack{
 stack<int> st;
 vector<bool> v;
 void cl(){
  while(!st.empty() && !v[st.top()]){
   st.pop(); } }
public:
 managed_stack(const int n): v(n, false){}
 int top(){
  cl();
  return st.top(); }
 void push(const int x){
  st.push(x);
  v[x] = true; }
 void pop(){
  v[st.top()] = false;
  st.pop(); }
 void remove(const int x){
  v[x] = false; }
 bool check(const int x){
  return v[x]; } };

void dfs1(const vector<vector<int> >& v, const int cur, managed_stack& st,
 vector<bool>& e_folosit){
 for(const auto next : v[cur]){
  if(!e_folosit[next]){
   e_folosit[next] = true;
   dfs1(v, next, st, e_folosit); } }
 st.push(cur); }

void dfs2(const vector<vector<int> >& v, const int cur, managed_stack& st,
 vector<int>& componenta, vector<int>& which_comp, const int comp_cur){
 componenta.push_back(cur);
 which_comp[cur] = comp_cur;
 st.remove(cur);
 for(const auto next : v[cur]){
  if(st.check(next)){
   dfs2(v, next, st, componenta, which_comp, comp_cur); } } }

void do_print(const int x, const int n){
 if(x < n){
  cout << x+1; }
 else{
  cout << '!' << x-n+1; } }

class graf{
 vector<vector<int> > v;
 vector<vector<int> > tr;
public:
 void print(const int n){
  cout << v.size() << '\n';
  for(int i = 0; i < v.size(); ++i){
   do_print(i, n);
   cout << " -> ";
   for(const auto next : v[i]){
    do_print(next, n);
    cout << ' '; }
   cout << endl; } }
 graf(const int sz):
  v(sz), tr(sz){}
 int size(){
  return v.size(); }
 void resize(const int nsz){
  v.resize(nsz);
  tr.resize(nsz); }
 void add(const int a, const int b){
  v[a].push_back(b);
  tr[b].push_back(a); }
 void fix(){
  for(auto& x : v){
   sort(begin(x), end(x));
   x.erase(unique(begin(x), end(x)), end(x)); }
  for(auto& x : tr){
   sort(begin(x), end(x));
   x.erase(unique(begin(x), end(x)), end(x)); } }
 void mk_condensation(vector<vector<int> >& componente,
  vector<int>& which_comp,
  graf& cond){
  managed_stack st(v.size());
  {
   vector<bool> e_folosit(v.size(), false);
   for(int i = 0; i < v.size(); ++i){
    if(!e_folosit[i]){
     e_folosit[i] = true;
     dfs1(v, i, st, e_folosit); } } }
  for(int i = 0; i < v.size(); ++i){
   if(st.check(i)){
    const int comp_cur = componente.size();
    componente.push_back({});
    dfs2(tr, i, st, componente.back(), which_comp, comp_cur); } }
  cond.resize(componente.size());
  for(int i = 0; i < componente.size(); ++i){
   for(const auto cur : componente[i]){
    for(const auto next : v[cur]){
     if(i != which_comp[next]){
      cond.add(i, which_comp[next]); } } } }
  cond.fix(); }

  void toposort(vector<int>& ordine){
   ordine.reserve(v.size());
   vector<int> in_deg(v.size());
   for(const auto& y : v){
    for(const auto x : y){
     ++in_deg[x]; } }
   stack<int> de_viz;
   for(int i = 0; i < v.size(); ++i){
    if(in_deg[i] == 0){
     de_viz.push(i); } }
   while(!de_viz.empty()){
    const int cur = de_viz.top();
    de_viz.pop();
    ordine.push_back(cur);
    for(const auto next : v[cur]){
     --in_deg[next];
     if(in_deg[next] == 0){
      de_viz.push(next); } } } }

 const vector<int>& get_adiac(const int x)const{
  return v[x]; } };

int main(){
 ifstream f("party.in");
 int n, m;
 f >> n >> m;
 const int graf_sz = 2*n;
 graf g(graf_sz);

 for(int i = 0, a, b, t; i < m; ++i){
  f >> a >> b >> t;
  --a, --b;
  switch(t){
  case 0:
   g.add(my_negate(a, n), b);
   g.add(my_negate(b, n), a);
   break;
  case 1:
   g.add(my_negate(a, n), my_negate(b, n));
   g.add(b, a);
   break;
  case 2:
   g.add(my_negate(b, n), my_negate(a, n));
   g.add(a, b);
   break;
  case 3:
   g.add(a, my_negate(b, n));
   g.add(b, my_negate(a, n));
   break; } }


 vector<vector<int> > componente;
 vector<int> which_comp(2*n);
 graf cond(0);
 g.mk_condensation(componente, which_comp, cond);
 vector<int> topo;
 cond.toposort(topo);
 reverse(begin(topo), end(topo));
 vector<int> e_invitat(g.size(), undecided);
 for(const auto comp : topo){
  if(e_invitat[componente[comp].front()] == undecided){
   for(const auto x : componente[comp]){
    do_print(x, n);
    e_invitat[x] = tr;
    e_invitat[my_negate(x, n)] = fa; } } }
 {
  ofstream g("party.out");
  g << count(begin(e_invitat), begin(e_invitat)+n, tr) << '\n';
  for(int i = 0; i < n; ++i){
   if(e_invitat[i]){
    g << i+1 << '\n'; } } }
 return 0; }
