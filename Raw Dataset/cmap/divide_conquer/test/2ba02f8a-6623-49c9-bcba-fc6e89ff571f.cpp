#include<fstream>
#include<vector>
#include<algorithm>
#include<stack>
#include<iomanip>
#include<climits>
#include<limits>
#include<cmath>
using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");

const int DN=1e5+5;

int n;

typedef pair<long long,long long> pii;

pii a[DN],b[DN],r[DN];

long long rez;

double sol;

long long dist(pii A,pii B)

{

 return 1LL*(A.first-B.first)*(A.first-B.first)+1LL*(A.second-B.second)*(A.second-B.second);

}

long long solve(int st,int dr)

{

 if(st==dr)

  return numeric_limits<long long>::max();

 int mij=(st+dr)/2,ls=st,ld=mij+1,pz=st,m=0;

 long long rez;

 rez=min(solve(st,mij),solve(mij+1,dr));

 for(int i=st;i<=dr;i++)

 {

  if(ls>mij||(ld<=dr&&a[ld].second<a[ls].second))

  {

   b[pz]=a[ld];

   ld++;

   pz++;

   continue;

  }

  b[pz]=a[ls];

  pz++;

  ls++;

 }

 for(int i=st;i<=dr;i++)

 {

  a[i]=b[i];

  if(abs(a[i].first-b[mij].first)<=rez)

  {

   m++;

   r[m]=a[i];

  }

 }

 for(int i=1;i<=m;i++)

  for(int j=i+1;j<=min(m,i+7);j++)

   rez=min(rez,dist(r[i],r[j]));

 return rez;

}

int main()

{

 fin>>n;

 for(int i=1;i<=n;i++)

  fin>>a[i].first>>a[i].second;

    sort(a+1,a+n+1);

 rez=solve(1,n);

 sol=rez;

 sol=sqrt(sol);



 fout<<fixed<<setprecision(6)<<sol;

}
