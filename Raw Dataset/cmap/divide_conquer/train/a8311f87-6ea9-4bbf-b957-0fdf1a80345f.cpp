#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <iomanip>
#include <complex>
#include <cassert>
using namespace std;







typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef complex<double> base;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<class T> ostream& operator<<(ostream& stream, const vector<T> v){ stream << "[ "; for (int i=0; i<(int)v.size(); i++) stream << v[i] << " "; stream << "]"; return stream; }
ll fpow(ll x, ll p, ll m){ll r=1; for (;p;p>>=1){ if (p&1) r=r*x%m; x=x*x%m; } return r;}
int gcd(int a, int b){ if (!b) return a; return gcd(b,a%b);}
ll gcd(ll a, ll b){ if (!b) return a; return gcd(b,a%b);}


struct point{
 int x,y;
 point(int x=0, int y=0) : x(x), y(y) {}
};

double dist(point A, point B){
 return sqrt(1LL*(A.x-B.x)*(A.x-B.x)+1LL*(A.y-B.y)*(A.y-B.y));
}

int N; point a[100100];
point v[100100]; int K;

double mind(int l, int r){
 if (r-l+1<=1) return (1LL<<30);
 if (r-l+1==2){
  if (a[l].y>a[r].y) swap(a[l],a[r]);
  return dist(a[l],a[r]);
 }

 double ans=(1LL<<30);
 int mid=(l+r)/2,mx=a[mid].x;
 ans=min(ans,mind(l,mid));
 ans=min(ans,mind(mid+1,r));



 int i,j;
 merge(a+l,a+mid+1,a+mid+1,a+r+1,v,[](point A, point B){return A.y<B.y; });
 memcpy(a+l,v,(r-l+1)*sizeof(point));

 vector<point> med;
 for (i=l; i<=r; i++)
  if (abs(a[i].x-mx)<=ans)
   med.push_back(a[i]);


 for (i=0; i<(int)med.size(); i++)
  for (j=i+1; j<(int)med.size() && med[j].y-med[i].y<=ans; j++)
   ans=min(ans,dist(med[i],med[j]));


 return ans;
}



int main(){
 ios::sync_with_stdio(0);
 cin.tie(0);
 ifstream fin("cmap.in");
 ofstream fout("cmap.out");
 fin >> N;

 int i;
 for (i=1; i<=N; i++)
  fin >> a[i].x >> a[i].y;

 sort(a+1,a+N+1,[](point A, point B){return A.x<B.x; });
 fout << fixed << setprecision(10) << mind(1,N) << "\n";
 return 0;
}
