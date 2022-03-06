#include<stdio.h>#include <cstring>
#include<vector>
#include<algorithm>




using namespace std;



int P[50002],P2[50002];



char S1[50002],S2[50002];

int C[32];



vector< int > V2[ 32 ];

bool viz[50002];



int N,ANS;



bool check_up()

{

  int i;

  for(i=0; i<N; ++i)

  {

  ++C[ S1[i]-'a' ];

  --C[ S2[i]-'a' ];

 }



  for(i=0; i<=32; ++i)

  {

   if( C[i] )

   {

   printf("-1\n");

   return 0;

   }

  }

 return 1;

}


void impera(int left, int right)
{

 if (left >= right)
  return;

 int mij=(left+right)>>1;

 impera(left,mij);
 impera(mij+1,right);

 int i1,i2,i3;
 i1=left,i2=mij+1,i3=left-1;

 while( i1<=mij && i2<=right )
 {
  if( P[i1]>P[i2] )
  {
   ANS+=(mij-i1+1);
   P2[++i3]=P[i2];
   ++i2;
  }
  else
   P2[++i3]=P[i1++];
 }

 if(i1<=mij)
 {
  for(i2=i1; i2<=mij; ++i2)
   P2[++i3]=P[i2];
 }
 else
 {
  for(i1=i2; i1<=right; ++i1)
   P2[++i3]=P[i1];
 }

 int i;
 for(i=left; i<=right; ++i)
  P[i]=P2[i];
}







int main()

{

 freopen("swap.in","r",stdin);

 freopen("swap.out","w",stdout);



 fgets( S1, 50002, stdin );

 fgets( S2, 50002, stdin );



 N=strlen(S1)-1;



 if( !check_up() )

  return 0;



 int i,aux;

 for(i=0; i<N; ++i)

  V2[ S2[i]-'a' ].push_back(i);



 for(i=0; i<32; ++i) C[i]=0;



 for(i=0; i<N; ++i)

 {

  aux=S1[i]-'a';



  ++C[ aux ];

  P[ i+1 ]= V2[ aux ][ C[aux]-1 ]+1;

 }



 impera( 1, N );



 printf("%d\n",ANS);



 return 0;

}
