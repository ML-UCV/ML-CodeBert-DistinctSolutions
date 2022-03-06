#include<stdio.h>
#include<vector>


using namespace std;



int n,m,i,a,b,tip,sol[210],invitati,viz[210],S[210],nn,p ;



vector<int> G[210], T[210];



int non ( int x )

{

 if( x <= n ) return x+n;

 return x - n ;

}



void sortaret ( int nod )

{

 int N = G[nod].size(),i;



 viz[nod] = 1 ;



 for( i = 0 ; i < N ; i++ )

  if( !viz[ G[nod][i] ] ) sortaret( G[nod][i] ) ;



 S[--nn] = nod ;

}



void dfs ( int nod )

{

 int N = T[nod].size(),i;



 viz[nod] = 0 ;



 sol[ non(nod) ] = 1 ;

 if( nod > n ) invitati++;



 for( i = 0 ; i < N ; i++ )

  if( viz[ T[nod][i] ] ) dfs( T[nod][i] ) ;

}



int main()

{

 freopen("party.in","r",stdin);

 freopen("party.out","w",stdout);



 scanf("%d %d",&n,&m);



 for( i = 1 ; i <= m ; i++ )

 {

  scanf("%d %d %d",&a,&b,&tip);



  if( tip == 0 )

  {

   G[non(a)].push_back(b);

   G[non(b)].push_back(a);

   T[a].push_back(non(b));

   T[b].push_back(non(a));

  }

  else if( tip == 1 )

  {

   G[non(a)].push_back(non(b));

   G[b].push_back(a);



   T[non(b)].push_back(non(a));

   T[a].push_back(b);

  }

  else if( tip == 2 )

  {

   G[non(b)].push_back(non(a));

   G[a].push_back(b);



   T[non(a)].push_back(non(b));

   T[b].push_back(a);

  }

  else

  {

   G[a].push_back(non(b));

   G[b].push_back(non(a));

   T[non(a)].push_back(b);

   T[non(b)].push_back(a);

  }

 }



 while( !invitati )

 {

  for( i = 1 ; i <= n+n ; i++ )

   viz[i] = sol[i] = 0 ;



  p++; nn = n + n + 1 ;



  for( i = p ; i <= n+n ; i++ )

   if( !viz[i]) sortaret(i);

  for( i = 1 ; i < p ; i++ )

   if( !viz[i]) sortaret(i);



  for( i = 1 ; i <= n+n ; i++ )

   if( viz[ S[i] ] && viz[ non(S[i]) ] )

    dfs( S[i] ) ;

 }



 printf("%d\n",invitati);



 for( i = 1 ; i <= n ; i++ )

  if( sol[i] ) printf("%d\n",i);



 return 0;

}
