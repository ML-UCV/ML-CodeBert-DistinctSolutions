#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;



vector< pair< int,int > > v[1502];

int H[1502],poz[1502],Nr[1502];

double D[1502];

int n,m,dh;



inline double Abs(double x){ return x>0 ? x:-x; }

inline int egal(double x,double first){

 return Abs(x-first) < 0.000001;

}

inline int mai_mare(double x,double first){

 return( x-first>0.000001 );

}



inline void swap(int i,int j){

 int aux=H[i]; H[i]=H[j]; H[j]=aux;

 poz[H[i]]=i;

 poz[H[j]]=j;

}

inline void Up(int k){

 while( k/2 && mai_mare(D[H[k/2]], D[H[k]]) ){

  swap(k,k/2);

  k=k/2;

 }

}

inline void Down(int k){

 int min=0;

 while( min != k ){

  min=k;

  if( 2*min<=dh && mai_mare(D[H[k]],D[H[2*min]]) ) k=2*min;

  if( 2*min+1<=dh && mai_mare(D[H[k]],D[H[2*min+1]])) k=2*min+1;

  swap(min,k);

 }

}



void Dijkstra(){

 vector< pair< int,int > >:: iterator it;

 int i,pmin;



 for(i=1;i<=n;++i) H[i]=poz[i]=i, D[i]=2147000000*1.00;

 D[1]=0.00; Nr[1]=1;

 dh=n;



 while( dh ){

  pmin=H[1];

  swap(1,dh);

  dh--;

  Down(1);



  for(it=v[pmin].begin(); it!=v[pmin].end(); ++it)

   if( mai_mare(D[it->first], D[pmin] + log(it->second)) ){

    D[it->first] = D[pmin] + log(it->second);

    Nr[it->first] = Nr[pmin];

    Up(poz[it->first]);

   }else

   if( egal(D[it->first],D[pmin] + log(it->second)) )

    Nr[it->first]=( Nr[it->first] + Nr[pmin]) % 104659;

 }

}



int main(){

 int i,x,first,z;

 freopen("dmin.in","r",stdin);

 freopen("dmin.out","w",stdout);

 scanf("%d%d",&n,&m);

 for(i=1;i<=m;++i){

  scanf("%d%d%d",&x,&first,&z);

  v[x].push_back(make_pair(first,z));

  v[first].push_back(make_pair(x,z));

 }



 Dijkstra();



 printf("%d",Nr[2]);

 for(i=3;i<=n;++i) printf(" %d",Nr[i]);

 printf("\n");

 fclose(stdin); fclose(stdout);

 return 0;

}
