#include<fstream>
#include<cstdio>
#include<vector>
#include<queue>
#include<bitset>
#include<cmath>
#include<utility>
using namespace std;

ofstream out("dmin.out");
vector<pair<int ,double > > G[1510];

typedef vector<pair<int,double> > ::iterator IT;

queue<int>Q;

bitset<1510>uz;



int drum[1510],n,m;

double d[1510],EPS=0.0000000001,c;



void read();

void BMF();

void write();



int main()

{

 read();

 BMF();

 write();

 return 0;

}



void read()

{

 ifstream in("dmin.in");

 in>>n>>m;

 for(int x,y,c ; m ; --m)

 {

  in>>x>>y>>c;

  G[x].push_back(make_pair(y,log( (double) c) ) );

  G[y].push_back(make_pair(x,log( (double) c) ) );

 }

}



void BMF()

{

 for(int i=1;i<=n;i++)

  d[i]=0x3f3f3f3f;

 d[1]=0;

 drum[1]=1;

 Q.push(1);

 uz[1]=1;

 int k;

 for(; Q.size(); Q.pop())

 {

   k=Q.front();

    for(IT I=G[k].begin();I!=G[k].end();++I)

    {

     int val=I->first;

     double cost=I->second;

     if( fabs( d[val] - d[k] - cost ) < EPS )

      drum[val]= (drum[val] + drum[k] ) %104659;

     else

      if( d[val] - d[k] - cost > EPS)

      {

       if(!uz[val])

       {

        Q.push(val);

        uz[val]=1;

       }

       d[val]=d[k] + cost;

       drum[val]= drum[k] ;

      }

    }

    uz[k]=0;

 }

}



void write()

{

 for(int i=2;i<=n;i++)

  out<<drum[i]<<" ";

}
