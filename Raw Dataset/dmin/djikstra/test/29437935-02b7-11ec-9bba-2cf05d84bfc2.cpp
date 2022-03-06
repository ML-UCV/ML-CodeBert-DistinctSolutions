#include <fstream>
#include <cmath>




using namespace std;
typedef struct nod {

        int vf;

        double dist;

        nod* next;

} *PNOD, NOD;



PNOD L[1501];

double lg;

int m, n, nod_p, k, tur;

double d[1501], dis, minim;

int s[1501], nr[1501];



void Read();

void Add(int,int,double);

void Dijkstra(int);



FILE *fout = fopen( "dmin.out", "w" );



int main()

{

    Read();

    Dijkstra( nod_p );



    for ( int i = 2; i <= n; ++i )

         fprintf( fout, "%d ", (nr[i]%104659) );

    fprintf( fout, "\n" );







    fclose( fout );

    return 0;

}



void Read()

{

     FILE *fin = fopen( "dmin.in", "r" );

     fscanf( fin, "%d%d", &n, &m );

     int i, j, v1, v2;

     double cost;

     for ( i = 1; i <= m; ++i )

     {

         fscanf( fin, "%d%d%lf", &v1, &v2, &cost );

         lg = (double)(log(cost));

         Add(v1,v2,lg);

         Add(v2,v1,lg);

         d[v1] = d[v2] = 300000001;

     }

     nod_p = 1;

     fclose( fin );

}



void Add( int i, int j, double cost )

{

     PNOD p = new NOD;

     p->vf = j;

     p->dist = cost;

     p->next = L[i];

     L[i] = p;

}



void Dijkstra( int sursa )

{

     s[sursa] = 0;

     d[sursa] = 0;

     nr[sursa] = 1;

     int i;
     for ( tur = 1; tur <= n; ++tur )

     {

         minim = 20000000.;

         for ( i = 1; i <= n; ++i )

         {

             if ( !s[i] && d[i] < minim )

             {

                  minim = d[i];

                  k = i;

             }

         }



         s[k] = 1;

         for ( PNOD j = L[k]; j; j = j->next )

         {

             if ( !s[j->vf] )

             {

                  dis = j->dist;

                  if ( d[j->vf] - (d[k] + dis ) > 1e-10 )

                  {

                       d[j->vf] = d[k] + dis;

                       nr[j->vf] = nr[k]%104659;

                  }

                  else if ( fabs(d[j->vf] - (d[k] + dis)) < 1e-10 )

                  {

                       nr[j->vf] += nr[k];

                  }

             }

         }

     }

}
