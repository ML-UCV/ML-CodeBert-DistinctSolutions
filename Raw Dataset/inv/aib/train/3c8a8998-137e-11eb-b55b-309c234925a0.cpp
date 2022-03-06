#include <cstdio>
#include <algorithm>
#include <vector>






using namespace std;

vector < pair< int,int > > V;

int A[100001];

int N,i,x,k;

long long sol;

void add(int x)

{

int i=0;

for (i=x;i<=N;i+=(i&(-i))) A[i]++;

}

int Sum(int x)

{

int i=0,S=0;

for (i=x;i>0;i-=(i&(-i))) S+=A[i];

return S;

}

int main()

{

freopen("inv.in","r",stdin);

freopen("inv.out","w",stdout);

scanf("%d",&N);

for (i=0;i<N;i++)

{

scanf("%d",&x);

V.push_back(make_pair(x,i+1));

}

sort(V.begin(),V.end());

sol=1LL*N*(N-1)/2;

for (i=0;i<N;i++)

{

x=V[i].second;

sol-=1LL*Sum(x);

add(x);

}

printf("%d\n",sol%9917);

return 0;

}
