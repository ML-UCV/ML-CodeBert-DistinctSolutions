#include <cstdio>
#include <vector>#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
double a[1501][1501];

double d[1501];

int dp[1501];

vector<int>x[1501];

int n;



void read()

{

 int m, p, q, c;

 freopen("dmin.in","r",stdin);

 scanf("%d %d\n", &n, &m);



 while(m--)

 {

  scanf("%d %d %d\n", &p, &q, &c);

  x[p].push_back(q);

  x[q].push_back(p);

  a[p][q]=a[q][p]=(double) log((double)c);

 }

}



void BF()

{

 queue<int>Q;



 for(int i=0;i<=n;++i) d[i]=10000000;

 d[1]=0;

 int u,i;

 vector<int>::iterator it;

 Q.push(1);



 while(!Q.empty())

 {

  u=Q.front();

  Q.pop();



  for(it=x[u].begin();it!=x[u].end();++it)



   if(d[*it]-d[u]-a[u][*it]>1e-10)

    Q.push(*it),

    d[*it]=d[u]+a[u][*it];



 }



}



void solve()

{

 memset(dp, 0, sizeof(dp));

 dp[1]=1;

 queue<int>Q;

 int u, i;

 vector<int>::iterator it,jt;



 Q.push(1);

 bool use[1501];

 memset(use, 0,sizeof(use));

 use[1]=1;







 while(!Q.empty())

 {

  u=Q.front();

  Q.pop();



  for(it=x[u].begin();it!=x[u].end();++it)

   if(!use[*it])

   {

    Q.push(*it);

    use[*it]=1;





    for(jt=x[*it].begin();jt!=x[*it].end();++jt)



    if(fabs((double)(d[*jt]+a[*jt][*it])-d[*it])<1e-10)

     dp[*it]+=dp[u], dp[*it]%=104659;







   }





 }



 freopen("dmin.out","w",stdout);

 for(i=2;i<=n;++i)printf("%d ", dp[i]);



}

int main()

{

 read();

 BF();

 solve();



 return 0;

}
