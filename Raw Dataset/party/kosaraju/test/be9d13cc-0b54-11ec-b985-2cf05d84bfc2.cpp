#include<stdio.h>
#include<assert.h>
#include<vector>
#include<stack>


using namespace std;
vector< int > G[256],GT[256];

stack< int > Q;

bool viz[256],SOL[256];

int N,M,ANS;



inline int faNegare( int value )

{

 return value<=N ? value+N : value-N;

}



inline void push_edge( int node1, int node2 )

{

 G[node1].push_back( node2 );

 GT[node2].push_back( node1 );

}



void DF1( int node )

{

 viz[node]=1;



 unsigned int i,v;

 for(i=0; i<G[node].size(); ++i)

 {

  v=G[node][i];

  if( !viz[v] )

   DF1(v);

 }



 Q.push( node );

}



void DF2( int node )

{

 viz[node]=0;

 SOL[ faNegare(node) ]=1;

 SOL[node]=0;



 unsigned int i,v;

 for(i=0; i<GT[node].size(); ++i)

 {

  v=GT[node][i];

  if( viz[v] )

   DF2(v);

 }

}



int main()

{

 assert( freopen("party.in","r",stdin)!=NULL );

 assert( freopen("party.out","w",stdout)!=NULL );



 assert( scanf("%d%d",&N,&M)!=EOF );



 int i,a1,a2,a3;

 for(i=1; i<=M; ++i)

 {

  assert( scanf("%d%d%d",&a1,&a2,&a3)!=EOF );

  switch( a3 )

  {

   case 0:

   {

     push_edge( faNegare(a1), a2 );

     push_edge( faNegare(a2), a1 );

     break;

   }

   case 1:

   {

     push_edge( faNegare(a1), faNegare(a2) );

     push_edge( a2, a1 );

     break;

   }

   case 2:

   {

     push_edge( faNegare(a2), faNegare(a1) );

     push_edge( a1, a2 );

     break;

   }

   case 3:

   {

     push_edge( a1, faNegare(a2) );

     push_edge( a2, faNegare(a1) );

     break;

   }

  }

 }



 for(i=1; i<=(N<<1); ++i)

 {

  if( !viz[i] )

   DF1( i );

 }



 int node;

 while( !Q.empty() )

 {

  node=Q.top();

  Q.pop();



  if( viz[node] && viz[ faNegare(node) ] )

   DF2( node );

 }



 for(i=1; i<=N; ++i)

  ANS+=SOL[i];



 printf("%d\n",ANS);



 for(i=1; i<=N; ++i)

  if( SOL[i] )

   printf("%d\n",i);



 return 0;

}
