#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream cin("cmap.in");

ofstream cout("cmap.out");





const long long inf=4e18;



int n;

vector<pair<long long,long long> > x;

long long calc(const pair<long long,long long> a,const pair<long long,long long> b){

 return ((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));

}



long long solve(int st,int dr)

{

 if(dr-st<=3){

  long long ans=inf;

  for (int i=st;i<dr;i++)

   for (int j=i+1;j<=dr;j++)

    ans=min(ans,calc(x[i],x[j]));

  return ans;

 }

 int mij=(st+dr)/2;

 long long best=min(solve(st,mij),solve(mij+1,dr));



 vector<pair<int,int> > aux;

 for(int i=st;i<=dr;++i)

  if(best>=abs(x[i].first-x[mij].first))

   aux.push_back(x[i]);

 int counter=aux.size();

 sort(aux.begin(),aux.end(), [](auto &left, auto &right) {

    return left.second < right.second;

});

 for(int i=0;i<counter-1;++i)

  for(int j=i+1;j<counter&&(j-i<8);++j)

   best=min(calc(aux[i],aux[j]),best);

 return best;

}



int main()

{

  int i;

  cin>>n;

  x.resize(n+1);

  for(i=1;i<=n;i++)

   cin>>x[i].first>>x[i].second;

  sort(x.begin(),x.end());

  cout<<fixed<<setprecision(6)<<sqrt(solve(1,n));

  return 0;

}
