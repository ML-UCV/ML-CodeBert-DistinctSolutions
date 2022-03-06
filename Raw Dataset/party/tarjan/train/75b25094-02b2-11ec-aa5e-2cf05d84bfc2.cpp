#include<fstream>
#include<cstdlib>
#include<ctime>


using namespace std;





ifstream f("party.in");

ofstream g("party.out");

int C[10*102],n,m,i,Nr;

struct inv {

 int x,y;

 int c;

}

v[10*102];

int verificare( int k ) {



 if( k==0)

  return C[v[i].x] || C[v[i].y] ;



 if(k==1)

  return C[v[i].x] || !C[v[i].y];



 if(k==2)

  return C[v[i].y]||!C[v[i].x];



 if(k==3)

  return C[v[i].x]+C[v[i].y]!=2 ;



 return 0;

}

int main () {



 f>>n>>m;



 for(i=1;i<=m;i++)

  f>>v[i].x>>v[i].y>>v[i].c;

 for(i=1;i<=n;i++)

  C[i]=1;



 for(i=1;i<=m;i++){



  if(!verificare(v[i].c)) {

   int a=rand()%2;



   if( a==1 ) {

    C[v[i].y]=!C[v[i].y];

   }

   else {

    C[v[i].x]=!C[v[i].x];

   }

   i=0;

  }

 }

 for(i=1;i<=n;i++)

  if(C[i]){

   ++Nr;

  }

 g<<Nr<<"\n";

 for(i=1;i<=n;++i) {

  if(C[i])

   g<<i<<"\n";

 }

 return 0;

}
