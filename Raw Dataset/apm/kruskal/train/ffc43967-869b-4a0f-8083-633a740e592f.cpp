#include <bits/stdc++.h>

using namespace std;

ifstream in("apm.in");
ofstream out("apm.out");

int a[400010],b[400010],c[400010],grupa[400010],ind[400010];
int ans;
vector<int> ANS;
int Grupa(int i)
{
 if(grupa[i]==i) return i;
 grupa[i]=Grupa(grupa[i]);
 return grupa[i];
}

void unite(int i,int j)
{
 grupa[Grupa(i)]=Grupa(j);
}


bool ok(int a,int b)
{
 return (c[a]<c[b]);
}


int main()
{
 int n,m;
 in>>n>>m;
 for(int i=1;i<=m;i++)
 {
  in>>a[i]>>b[i]>>c[i];
  ind[i]=i;
 }
 for(int i=1;i<=n;i++)
  grupa[i]=i;
 sort(ind+1,ind+m+1,ok);
 for(int i=1;i<=m;i++)
 {
  if(Grupa(a[ind[i]])!=Grupa(b[ind[i]]))
  {
   ans+=c[ind[i]];
   unite(a[ind[i]],b[ind[i]]);
   ANS.push_back(ind[i]);
  }
 }
 out<<ans<<"\n";
 out<<n-1<<"\n";
 for(int i=0;i<n-1;i++)
  out<<a[ANS[i]]<<" "<<b[ANS[i]]<<"\n";
 return 0;
}
