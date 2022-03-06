#include <fstream>
std::ifstream cin("stramosi.in");
std::ofstream cout("stramosi.out");


int rmq[19][250001];
int n,T;

int main()
{
 int nod,cnt,k,dist;
 cin>>n>>T;
 for(k=1;(1<<k)<=n;++k);
 for(int i=1;i<=n;++i) cin>>rmq[0][i];
 for(int i=1;(1<<i)<=n;++i)
  for(int j=1;j<=n;++j)
   rmq[i][j]=rmq[i-1][rmq[i-1][j]];
 for(;T--;){
  cin>>nod>>cnt;
  dist=k;
  while(nod&&dist--)
   if(cnt&(1<<dist))
    nod=rmq[dist][nod];
  cout<<nod<<'\n';
 }
}
