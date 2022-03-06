#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
using namespace std;



bool check_possible(const string& from, const string& to){

 array<int, 26> cnt_from = {}, cnt_to = {};

 for(const auto x : from){

  ++cnt_from[x-'a']; }

 for(const auto x : to){

  ++cnt_to[x-'a']; }

 return cnt_from == cnt_to; }



void mk_permut(const string& from, const string& to, vector<int>& permut){

 array<vector<int>, 26> pozitii;

 for(int i = 0; i < from.size(); ++i){

  pozitii[from[i]-'a'].push_back(i); }

 for(auto& x : pozitii){

  reverse(begin(x), end(x)); }



 for(int i = 0; i < to.size(); ++i){

  permut[pozitii[to[i]-'a'].back()] = i;

  pozitii[to[i]-'a'].pop_back(); } }



class aib{

 int n;

 vector<int> buf;

public:

 aib(const int N): n(N), buf(n, 0){}

 void update(int poz){

  for( ; poz < n; poz += (poz+1)&(-poz-1)){

   ++buf[poz]; } }

 int query(int poz){

  int rez = 0;

  for( ; poz >= 0; poz -= (poz+1)&(-poz-1)){

   rez += buf[poz]; }

  return rez; } };



int cnt_inversiuni(const vector<int>& permut){

 aib a(permut.size());

 int rez = 0;

 for(int i = permut.size()-1; i >= 0; --i){

  rez += a.query(permut[i]);

  a.update(permut[i]); }

 return rez; }



int main(){

 ifstream f("swap.in");

 ofstream g("swap.out");

 string from, to;

 f >> from >> ws >> to;



 if(!check_possible(from, to)){

  g << -1;

  return 0; }



 vector<int> permut(from.size());

 mk_permut(from, to, permut);

 g << cnt_inversiuni(permut);

 return 0; }
