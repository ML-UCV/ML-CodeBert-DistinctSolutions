#include<fstream>
#include<vector>
#include<math.h>

using namespace std;
ifstream fi("dmin.in");
ofstream fo("dmin.out");
int n,m,a,b,c,nr[15001],k;

double d[15001];
char viz[15001];
vector <pair<int,double> > v[15001];
int comp (double a,double b){

 if((a-b<0.0000001&&a-b>-0.0000001)||(b-a<0.0000001&&b-a>-0.0000001))

  return 1;

 return 0;

}
void dijkstra(int x){
 double min=2000000000;
 for(int i=1;i<=n;++i)
  if(d[i]<min&&viz[i]==0){
   min=d[i];
   k=i;
  }
 if(min!=2000000000){
  viz[k]=1;
  for(int i=0;i<v[k].size();++i)
   if(comp(d[v[k][i].first],d[k]+v[k][i].second)){

    nr[v[k][i].first]+=nr[k];

    if(nr[v[k][i].first]>=104659)

     nr[v[k][i].first]-=104659;

   }

   else

    if(d[v[k][i].first]>d[k]+v[k][i].second){
     d[v[k][i].first]=d[k]+v[k][i].second;

     nr[v[k][i].first]=nr[k];

    }


  dijkstra(k);
 }
}
int main() {
 fi>>n>>m;
 for(int i=1;i<=m;++i){
  fi>>a>>b>>c;

  double lg=log(c);
  v[a].push_back(make_pair(b,lg));

  v[b].push_back(make_pair(a,lg));
 }
 nr[1]=1;
 for(int i=2;i<=n;++i)
  d[i]=2000000000;

 dijkstra(1);
 for(int i=2;i<=n;++i)

  fo<<nr[i]<<' ';


 fi.close();
 fo.close();
 return 0;
}
