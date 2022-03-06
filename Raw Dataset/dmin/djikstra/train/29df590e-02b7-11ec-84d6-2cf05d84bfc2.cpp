#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct nod

{

 int info;

 double c;

 struct nod * next;

}NOD;



NOD * A[1600];

FILE * fin, * fout;

int X, Y, N, M, i;

int SEL[1600], NR[1600];

double D[1600];

double C;



void ADD( int info, double c, NOD * &p )

{

 NOD * q;

 q = new NOD;

 q->info = info;

 q->c = c;

 q->next = p;

 p = q;

}

int equal( double a, double b )

{

 if ( fabs( a - b ) < 1e-10 ) return 1;

    else

      return 0;

}



void DIJKSTRA( int xp )

{

 int i, found, k = 0;

 double min;

 NOD * p;

 memset( SEL, 0, sizeof(SEL) );

 memset( NR, 0, sizeof(NR) );

 for( i = 1; i <= N; i++ ) D[i] = 1000000000;

 D[xp] = 0; NR[xp] = 1;

 do

 {

  min = 1000000000; found = 0;

  for( i = 1; i <= N; i++ )

   if (!SEL[i])

    if (D[i] < min )

    {

     min = D[i];

     k = i;

     found = 1;

    }

   if (found)

   {

    p = A[k];

    while (p!=NULL)

    {

     if (!SEL[p->info])

      if ( D[p->info] - (D[k] + p->c) > 1e-10 )

      {

       D[p->info] = D[k] + p->c;

       NR[p->info] = NR[k];

      }else

       if (equal( D[k] + p->c, D[p->info])) NR[p->info] = (NR[p->info] + NR[k])% 104659;

      p = p->next;

    }

          SEL[k] = 1;

   }

 }while (found);

}



int main()

{

 fin = fopen( "dmin.in", "r" );

 fout = fopen( "dmin.out", "w" );

 fscanf( fin, "%d %d\n", &N, &M );

 for( i = 1; i <= N; i++ ) A[i] = NULL;

 for( i = 0; i < M; i++ )

 {

  int T;

  fscanf( fin, "%d %d %d\n", &X, &Y, &T);

  C = T;

  ADD( X, log(C), A[Y] );

  ADD( Y, log(C), A[X] );

 }



    DIJKSTRA(1);

 for( i = 2; i <= N; i++) fprintf(fout, "%d ", NR[i] );

 fprintf( fout, "\n" );

 fclose( fin );

 fclose( fout );

 return 0;

}
