#include<bits/stdc++.h>




typedef long long ll;

typedef long double ld;



const int nmax=1e5+3;

const int mod=998244353;

const ll inf=0x3f3f3f3f3f3f3f3f;
using namespace std;



int gcdex(int a,int b,int &x,int &y) {

  if(!b) {

    x=1;

    y=0;

    return a;

  }

  else {

    int d,x1,y1;

    d=gcdex(b,a%b,x1,y1);

    x=y1;

    y=x1-(a/b)*y1;

    return d;

  }

}



int a,b,x,y,d;

int main()

{

  freopen("inversmodular.in","r",stdin);

  freopen("inversmodular.out","w",stdout);

  ios_base::sync_with_stdio(0); cin.tie(0);

  cin>>a>>b;

  d=gcdex(a,b,x,y);

  if(x<=0)

   x=b+x%b;

  cout<<x;

}
