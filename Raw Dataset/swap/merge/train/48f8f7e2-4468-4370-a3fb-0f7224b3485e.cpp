#include <fstream>
#include <queue>
#include <cstring>
using namespace std;
queue<int> A[28];

int Co[28];



char One[50011];int N;

char Two[50011];int M;



int Minus[50011*4],Rez,Semn;

int Solve;



void Update( int Nod,int St,int Dr,int Pos )

{

 if ( St==Dr )

 {

  Minus[Nod] += Semn;

  return;

 }



 int Mid=(St+Dr)/2;

 if ( Mid>=Pos )

  Update( Nod*2,St,Mid,Pos );

 else

  Update( Nod*2+1,Mid+1,Dr,Pos );

 Minus[Nod]=Minus[Nod*2]+Minus[Nod*2+1];

}



void Query( int Nod,int St,int Dr,int Begin,int Endin )

{

 if ( St>=Begin && Dr<=Endin )

 {

  Rez += Minus[Nod];

  return;

 }



 if ( St==Dr ) return;



 int Mid=(St+Dr)/2;

 if ( Begin <=Mid )

  Query( Nod*2, St, Mid, Begin , Endin );

 if ( Mid < Endin )

  Query( Nod*2+1 , Mid+1, Dr, Begin , Endin );

}



int main()

{

 freopen("swap.in","r",stdin);

 freopen("swap.out","w",stdout);



 fgets( One , 50001, stdin);N=strlen( One );

 fgets( Two , 50001, stdin);M=strlen( Two );



 for (int i=N;i;--i)

 {

  One[i]=One[i-1],++Co[ One[i]-'a'+1 ];

  Two[i]=Two[i-1],--Co[ Two[i]-'a'+1 ];

 }



 if ( N-M )

 {

  printf("-1\n");

  return 0;

 }

 for (int i=1;i<27;++i)

  if ( Co[i] )

  {

   printf("-1\n");

   return 0;

  }



 for (int i=1;i<=N;++i) A[ One[i]-'a'+1 ].push( i );



 for (int i=1;i<=N;++i)

 {

  Rez=0;

  int Last=A[Two[i]-'a'+1].front();



  Query( 1,1,N,1,Last );

  Solve += Last-i+Rez;



  Semn= 1;

  Update( 1,1,N,1 );



  Semn= -1;

  Update( 1,1,N,Last+1 );



  A[Two[i]-'a'+1].pop();

 }



 printf("%d\n",Solve);

}
