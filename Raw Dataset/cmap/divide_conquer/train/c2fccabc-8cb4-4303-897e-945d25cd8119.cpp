#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

typedef long double db;

typedef long long ll;



ll n;

pair<ll,ll> a[100010],vp[100010],va[100010];



db dis(pair<ll,ll> p1, pair<ll,ll> p2){

  return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));

}



bool cmp(pair<ll,ll> p1, pair<ll,ll> p2){

  return p1.second<p2.second;

}



ll mod(ll nr){

  return (nr>=0?nr:-nr);

}



void interclaseaza(ll st,ll dr,ll mij){

  for(ll i=1,i1=st,i2=mij+1;i<=dr-st+1;i++){

    if(i1==mij+1){

      va[i]=vp[i2++];

      continue;

    }

    if(i2==dr+1){

      va[i]=vp[i1++];

      continue;

    }

    if(cmp(vp[i1],vp[i2]))va[i]=vp[i1++];

    else va[i]=vp[i2++];

  }

  for(ll i=1;i<=dr-st+1;i++)

    vp[st+i-1]=va[i];

}



db rez(ll st,ll dr){

  if(dr-st+1<=3){

    db ansa;

    ansa=dis(a[st],a[st+1]);

    if(dr-st+1==3)

      ansa=min(ansa,min(dis(a[st],a[dr]),dis(a[dr],a[dr-1])));

    sort(vp+st,vp+dr+1,cmp);

    return ansa;

  } else {

    ll mij=(st+dr)/2;

    db ans1=rez(st,mij);

    db ans2=rez(mij+1,dr);

    db ansa=min(ans1,ans2);

    ll drd=a[mij].first;

    interclaseaza(st,dr,mij);
    ll sz=0;

    for(ll i=st;i<=dr;i++)

      if(mod(vp[i].first-drd)<=ansa)va[++sz]=vp[i];



    for(ll i=1;i<=sz;i++)

      for(ll j=i+1;j<=i+7&&j<=sz;j++)

        ansa=min(ansa,dis(va[i],va[j]));

    return ansa;

  }

}



int main()

{

    ifstream f ("cmap.in");

    ofstream g ("cmap.out");

    f>>n;

    for(ll i=1;i<=n;i++)

      f>>a[i].first>>a[i].second,

      vp[i]=a[i];

    sort(a+1,a+n+1); sort(vp+1,vp+n+1);

    g<<fixed<<setprecision(6)<<rez(1,n)<<'\n';

    f.close ();

    g.close ();

    return 0;

}
