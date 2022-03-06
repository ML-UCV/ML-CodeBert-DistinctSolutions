#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(const int cur, const vector<vector<int>>& graf, vector<bool>& e_viz,
  vector<int>& rez){
 e_viz[cur] = true;
 for(const auto next : graf[cur]){
  if(!e_viz[next]){
   dfs(next, graf, e_viz, rez); } }
 rez.push_back(cur); }

void kosoraju(const vector<vector<int>>& graf, const vector<vector<int>>& graf_t,
  vector<vector<int>>& rez){

 const int n = graf.size();
 vector<bool> e_viz(n, false);
 vector<int> st;
 for(int i = 0; i < n; ++i){
  if(!e_viz[i]){
   dfs(i, graf, e_viz, st); } }
 fill(begin(e_viz), end(e_viz), false);
 while(!st.empty()){
  const int cur = st.back();
  st.pop_back();
  if(!e_viz[cur]){
   rez.emplace_back(0, 0);
   dfs(cur, graf_t, e_viz, rez.back()); } } }

void sat2(const vector<vector<int>>& graf, const vector<vector<int>>& graf_t,
  vector<bool>& rez){
 const int n = graf.size();

 vector<vector<int>> comps;

 kosoraju(graf, graf_t, comps);

 for(const auto& c : comps){
  if(none_of(begin(c), end(c), [&rez](const int x){ return rez[x]; })){
   for(const auto x : c){
    rez[x^1] = true; } } } }

int main(){
 ifstream f("party.in");
 ofstream g("party.out");

 int n, m;

 f >> n >> m;

 vector<vector<int>> graf(2*n), graf_t(2*n);

 auto add_muc = [&graf, &graf_t](const int a, const int b){
  graf[a].push_back(b);
  graf_t[b].push_back(a); };

 auto add_implication = [&add_muc](const int a, const int b){
  add_muc(a, b);
  add_muc(b^1, a^1); };

 for(int i = 0, a, b, x; i < m; ++i){
  f >> a >> b >> x;
  --a, --b;
  a *= 2, b *= 2;
  if(x == 0){
   add_implication(a, b+1);
   add_implication(b, a+1); }
  else if(x == 1){
   add_implication(a, b); }
  else if(x == 2){
   add_implication(b, a); }
  else if(x == 3){
   add_implication(a+1, b);
   add_implication(b+1, a); } }

 vector<bool> e_invitat(2*n, false);

 sat2(graf, graf_t, e_invitat);

 vector<int> rez;

 for(int i = 0; i < n; ++i){
  if(e_invitat[2*i+1]){
   rez.push_back(i+1); } }

 g << rez.size() << '\n';

 for(const auto x : rez){
  g << x << '\n'; }

 return 0; }
