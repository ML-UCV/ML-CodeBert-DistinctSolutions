#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
const double eps = 0.00001;

const int mod = 104659;

const int maxn = 1505;

using namespace std;



int i , j , n , m , a , b, c, nr[maxn];

bool in[maxn];

vector <pair <int , double> > G[maxn];

double d[maxn];



struct cmp {

 bool operator () ( const int & a , const int & b ) {

  return ( d[a] > d[b]);

 }

};

priority_queue < int , vector <int> , cmp > Q;



void Dijkstra()

{

 int i;

 for( i = 2 ; i <= n ; ++i )

  d[i] = 10000000.00;



 Q.push(1) , in[1] = 1, nr[1] = 1;



 while( !Q.empty() ) {

  int act = Q.top();

  Q.pop() ;

  in[act] = false;

  for( i = 0 ; i < G[act].size() ; ++i ) {

    if ( d[act] + G[act][i].second < d[G[act][i].first] ) {

     d[G[act][i].first] = d[act] + G[act][i].second;

     if ( !in[G[act][i].first] ) Q.push(G[act][i].first) , in[G[act][i].first] = true;

    }

    if ((d[G[act][i].first] + G[act][i].second - d[act]) <= eps)

     nr[act] = (nr[act] + nr[G[act][i].first]) % mod;

   }

 }

}



int main()

{

 freopen("dmin.in","r",stdin);

 freopen("dmin.out","w",stdout);



 scanf("%d %d",&n,&m);

 for( i = 1 ; i <= m ; ++i ) {

  scanf("%d %d %d",&a,&b,&c);

  G[a].push_back(make_pair(b,log((double)c)));

  G[b].push_back(make_pair(a,log((double)c)));

 }



 Dijkstra();

 for( i = 2 ; i <= n ; ++i )

  printf("%d ",nr[i]);



return 0;

}
