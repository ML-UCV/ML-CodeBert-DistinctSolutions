#include <bits/stdc++.h>

using namespace std;

ifstream in("strmatch.in");
ofstream out("strmatch.out");

string a,b;
int n,m,kmp[2000005];
vector<int> ans;
void prefix()
{
 int m=0;
 for(int i=1;i<a.size();i++)
 {
  if(a[i]==a[m]) kmp[i]=++m;
  else if(m!=0)
  {
   m=kmp[m-1];
   i--;
  }
  else kmp[i]=0;
 }
}


void KMP()
{
 int j=0,i=0;
 while(j<b.size())
 {
  if(a[i]!=b[j])
   if(i==0) j++;
   else i=kmp[i-1];
  else
  {
   i++;
   j++;
   if(i==a.size())
   {
    ans.push_back(j-i);
    i=kmp[i-1];
   }
  }
 }
}


int main()
{
 in>>a>>b;
 prefix();
 KMP();
 out<<ans.size()<<"\n";
 int marime=min(1000,(int) ans.size());
 for(int i=0;i<marime;i++)
  out<<ans[i]<<" ";
 return 0;
}
