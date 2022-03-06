#include<cstdio>
#include<fstream>
#include<vector>
#include<queue>
#include<cmath>


using namespace std;



const int MaxN = 1501;

const double eps = 1e-10;

const int Mod = 104659;

const double InF = 100000000;



const char InFile[] = "dmin.in";

const char OutFile[] = "dmin.out";



int N,M,sol[MaxN];

double d[MaxN];

bool inQ[MaxN];

vector< pair<int,double> > G[MaxN];

queue<int> Q;



double modul( double x )

{

 return x > 0 ? x : -x;

}



void BellMan_Ford()

{

 int nod;

 vector< pair<int,double> >::iterator it,iend;

 for( nod = 1 ; nod <= N ; ++nod )

  {

   d[nod] = InF;

   sol[nod] = 0;

   inQ[nod] = false;

  }

 d[1] = 0;

 sol[1] = 1;

 Q.push(1);

 inQ[1] = true;

 while( !Q.empty() )

  {

   nod = Q.front();

   Q.pop();

   inQ[nod] = false;

   iend = G[nod].end();

   it = G[nod].begin();

   for( ; it != iend ; ++it )

    {

     if( modul(d[it->first] - d[nod] - it-> second) < eps )

      {

       sol[it->first] = ( sol[it->first]+sol[nod] ) % Mod;

       if( !inQ[it->first] )

        {

         Q.push(it->first);

         inQ[it->first] = true;

        }

      }

     if( d[it->first] - d[nod] - it->second > eps )

      {

       d[it->first] = d[nod] + it->second;

       sol[it->first] = sol[nod];

       if( !inQ[it->first] )

        {

         Q.push(it->first);

         inQ[it->first] = true;

        }

      }

    }

  }

}



int main()

{

 ifstream fin( InFile );

 ofstream fout( OutFile );

 fin >> N >> M;

 int i,x,y;

 double z;

 for( i = 0 ; i < M ; ++i )

  {

   fin >> x >> y >> z;

   G[x].push_back(make_pair(y,log(z)));

   G[y].push_back(make_pair(x,log(z)));

  }

 BellMan_Ford();

 for( i = 2 ; i <= N ; ++i )

  fout << sol[i] << ' ';

 fout << '\n';

 fin.close();fout.close();

 return 0;

}
