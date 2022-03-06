#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<utility>
#include<bitset>
#include<cmath>
FILE *f=fopen("dmin.in","r");

FILE *g=fopen("dmin.out","w");



using namespace std;



vector<pair <int,double> >G[50005];

vector<int>::iterator it;

int n,m;

double dist[50005];

int res[50005];

priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > > HEAP;

bool used[50005];



void read( void )

{

    fscanf(f,"%d%d",&n,&m);



    for(int i(1); i <=m ; ++i )

    {

        int a,b;

        double c;

        fscanf(f,"%d%d%lf",&a,&b,&c);

        c=log(c);

        G[a].push_back(make_pair(b,c));

        G[b].push_back(make_pair(a,c));

    }

    fclose(f);



}

void DIJKSTRA( void )

{

    for(int i(1); i<=n ; dist[i++]=0x3f3f3f3f);



  dist[1]=0;

  res[1]=1;

  HEAP.push(make_pair(0,1));



  while(!HEAP.empty())

  {

      int node=HEAP.top().second;

      HEAP.pop();

     if( used[node])

        continue;

     used[node]=1;



      for(int i(0); i <G[node].size(); ++i )

      {

       int newnode=G[node][i].first;

       double dis=G[node][i].second;





       if( dist[newnode] > dist[node]+dis + 1e-10)

          {

              dist[newnode]=dist[node]+dis;

                res[newnode]=res[node];

              HEAP.push(make_pair(dist[newnode],newnode));

     continue;

          }



        if( abs (dist[newnode] - dist[node]-dis ) <= 1e-10 )

        {

            res[newnode]+=res[node];

            res[newnode]%=104659;

   continue;

        }



      }



  }





}

void write( void )

{

    for(int i(2); i <=n; ++i )



        fprintf(g,"%d ",res[i]);



    fclose(g);

}





int main( void )

{

    read();

    DIJKSTRA();

    write();

    return 0;

}
