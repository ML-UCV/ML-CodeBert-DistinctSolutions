#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;





vector<pair<long long,long long>> v,x,y;
int n,i,q=-1;


char u[20000000];

inline long long A()

{

   long long s=0,b=1;

   q++;

   if(u[q]==45)

        b=-1,q++;

   for(;u[q]>47;q++)

    s=s*10+u[q]-48;

   return s*b;

}
inline long long G(int s,int d)
{
    if(d-s<2)
        return 4e18;
    if(d-s==2)
 {
        if(y[s]>y[s+1])
            swap(y[s],y[s+1]);
        return ((x[s].first-x[s+1].first)*(x[s].first-x[s+1].first)+(x[s].second-x[s+1].second)*(x[s].second-x[s+1].second));
    }
    int m=(s+d)/2,e=0,i,j;
    long long b=min(G(s,m),G(m,d));
    for(sort(y.begin()+s,y.begin()+d),i=s;i<d;i++)
  if(abs(y[i].second-x[m].first)<=b)
         v[e++]=y[i];
    for(i=0;i<e-1;i++)
        for(j=i+1;j<e&&j-i<8;j++)
            b=min(b,((v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second)));
    return b;
}
int main()
{
 freopen("cmap.in","r",stdin),freopen("cmap.out","w",stdout),fread(u,1,20000000,stdin),n=A(),x.resize(n),y.resize(n),v.resize(n);
    for(i=0;i<n;i++)
     x[i].first=A(),x[i].second=A();
    for(sort(x.begin(),x.end()),i=0;i<n;i++)
        y[i]=make_pair(x[i].second,x[i].first);
    printf("%.6lf",sqrt(G(0,n)));
}
