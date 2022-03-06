#include <bits/stdc++.h>

using namespace std;

ifstream in("strmatch.in");
ofstream out("strmatch.out");

unsigned long long B=127;

string a,b;
unsigned long long hashA,hashB,powe;
unsigned long long sol;
vector<unsigned int> ans;
void make_hash()
{
 powe=1;
 for(unsigned long long i=0;i<a.length();i++)
 {
  hashA=(hashA * B + a[i]);
  powe=(powe * B);
 }
 for(unsigned long long i=0;i<a.length();i++)
  hashB=(hashB * B + b[i]);
}

int main()
{
 in>>a>>b;
 if(a.size()>b.size())
 {
  out<<"0";
  return 0;
 }
 make_hash();
 if(hashA == hashB)
 {
  sol++;
  ans.push_back(0);
 }
 for(unsigned int i=1;i<=b.size()-a.size();i++)
 {
  hashB=(hashB * B+b[i+a.size()-1]);
  unsigned long long aux=(powe * b[i-1]);
  hashB=(hashB-aux);
  if(hashA==hashB)
  {
   sol++;
   if(ans.size()<=1000)
    ans.push_back(i);
  }
 }
 out<<sol<<"\n";
 for(int i=0;i<min(1000,(int)ans.size());i++)
  out<<ans[i]<<" ";
 return 0;
}
