#include <cstdio>
#include <iostream>#include <math.h>
#include <queue>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstring>
#include <map>
#include <iomanip>
#include <stack>
#include <bitset>
#include <cctype>
#include <set>
using namespace std;



typedef pair<long long, long long> pii;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



pii p[100005],aux[100005];

int n;



inline double dist(pii a, pii b) {

 return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));

}



bool compy(pii a, pii b) {return a.second<b.second;}

pii jeg[100005];



double solve(int st, int dr, pii aux[]) {

 if(dr-st<=1) return 0x3f3f3f3f;

 if(dr-st==2) {

  if(aux[st].second>aux[st+1].second) swap(aux[st],aux[st+1]);

  return dist(p[st],p[st+1]);

 }

 else if(dr-st==3) {

  sort(aux+st,aux+dr,compy);

  return min(dist(p[st],p[st+1]),min(dist(p[st],p[st+2]),dist(p[st+2],p[st+1])));

 }

 int mid=(st+dr)/2,i,j,pos=st,ind1,ind2;

 double delta=solve(st, mid,aux);

 delta=min(delta,solve(mid, dr,aux));



 ind1=st;

 ind2=mid;



 while(ind1<mid && ind2<dr) {

  if(aux[ind1].second<aux[ind2].second) {

   jeg[pos++]=aux[ind1];

   ++ind1;

  }

  else {

   jeg[pos++]=aux[ind2];

   ++ind2;

  }

 }



 while(ind1<mid) {

  jeg[pos++]=aux[ind1];

  ++ind1;

 }

 while(ind2<dr) {

  jeg[pos++]=aux[ind2];

  ++ind2;

 }





 for(i=st;i<dr;++i) aux[i]=jeg[i];



 vector<pii> v;

 for(i=st;i<dr;++i)

  if(abs(aux[i].first-p[mid].first)<=delta) v.push_back(aux[i]);



 for(i=0;i<v.size();++i)

  for(j=i+1;j<v.size()&&j-i<8;++j)

   delta=min(delta,dist(v[i],v[j]));



 return delta;

}



int main() {

 int i;



 fin>>n;

 for(i=1;i<=n;++i) fin>>p[i].first>>p[i].second;



 sort(p+1,p+n+1);

 for(i=1;i<=n;++i) aux[i]=p[i];



 fout<<fixed<<setprecision(6)<<solve(1,n+1,aux);



 return 0;

}
