#include <bits/stdc++.h>
using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



string s, t;



int main()

{

  fin>>s>>t;

  int n=s.size(), m=t.size();

  string p=s+'$'+t;

  int l=p.size();

  vector<int> pi(l+1, 0), sol;

  for(int i=1;i<l;++i){

    int j=pi[i-1];

    while(j&&p[i]!=p[j]) j=pi[j-1];

    if(p[i]==p[j]) j++;

    pi[i]=j;

    if(pi[i]==n){

      sol.push_back(i-2*n);

    }

  }

  int bnd=min(1000, (int)sol.size());

  fout<<sol.size()<<"\n";

  for(int i=0;i<bnd;++i) fout<<sol[i]<<" ";

  fout<<"\n";

  return 0;

}
