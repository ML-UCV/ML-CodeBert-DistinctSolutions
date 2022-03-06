#include <bits/stdc++.h>
using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



pair<int, int> v[100005], aux[100005], local[100005];



inline double dist(pair<int, int> A, pair<int, int> B) {

 return sqrt(1LL*(A.first-B.first)*(A.first-B.first)+1LL*(A.second-B.second)*(A.second-B.second));

}



bool comp(pair<int, int> A, pair<int, int> B) {

 return B.second > B.first;

}



double solve(int left, int right) {

 if(right - left == 1) {

  if(aux[left].second > aux[right].second)

   swap(aux[left], aux[right]);



  return dist(aux[left], aux[right]);

 }

 else if(right - left == 2) {

  sort(aux+left, aux+right+1, comp);



  return min(dist(aux[left], aux[left+1]), min(dist(aux[left+1], aux[left+2]), dist(aux[left], aux[left+2])));

 }



  int mid=(left+right)/2,ind1=left,ind2=mid+1,ind=left,i,j;

 double first = solve(left, mid);

 double second = solve(mid+1, right);

 double d=min(first, second);



 while(ind1 <= mid && ind2 <=right) {

  if(aux[ind1].second < aux[ind2].second)

   local[ind++] = aux[ind1++];

  else local[ind++] = aux[ind2++];

 }



 while(ind1<=mid)

  local[ind++]=aux[ind1++];



 while(ind2<=right)

  local[ind++]=aux[ind2++];



 for(i=left;i<=right;++i) aux[i]=local[i];



 vector<pair<int, int> > candidates;

 for(i=left;i<=right;++i)

  if(abs(aux[i].first-v[mid].first)<=d)

   candidates.push_back(aux[i]);



 for(i=0;i<candidates.size();++i)

  for(j=i+1;j<candidates.size() && j-i<8;++j)

   d=min(d,dist(candidates[i],candidates[j]));



 return d;

}



int main() {

 int n,i;



 fin>>n;



 for(i=1;i<=n;++i) fin>>v[i].first>>v[i].second;



 sort(v+1,v+n+1);

 for(i=1;i<=n;++i) aux[i]=v[i];



 fout<<fixed<<setprecision(6)<<solve(1,n)<<'\n';



 return 0;

}
