#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

long n,m,i,x,y,z,nod,nod2,nr[1501];

char iq[1501];

double c,d[1501],dif;

vector <int>v[1501];

vector <double>cost[1501];



void bellman(){

     queue<int>Q;

     for (i=2;i<=n;++i)d[i]=1<<30; d[1]=0; nr[1]=1;

     Q.push(1);iq[1]=1;

     while (!Q.empty()){

           nod=Q.front(); Q.pop(); iq[nod]=0;

           int l=v[nod].size();

           for (int i=0;i<l;++i){

               nod2=v[nod][i];

               dif=d[nod]+cost[nod][i]-d[nod2];

               if (dif>(-0.00000000001) && dif<0.00000000001){

                  nr[nod2]+=nr[nod];nr[nod2]=(nr[nod2]>104659)?(nr[nod2]-104659):(nr[nod2]);

                  if (!iq[nod2]){ iq[nod2]=1; Q.push(nod2); }

               }

               else

                  if (dif<(-0.00000000001)){

                     d[nod2]=d[nod]+cost[nod][i];

                     nr[nod2]=nr[nod];

                     if (!iq[nod2]){ iq[nod2]=1; Q.push(nod2); }



                  }

           }

     }

}



int main(){

    freopen("dmin.in","r",stdin);

    freopen("dmin.out","w",stdout);

    scanf("%ld %ld",&n,&m);

    while (m--){

          scanf("%ld %ld %ld",&x,&y,&z);

          c=log(z);

          v[x].push_back(y);v[y].push_back(x);

          cost[x].push_back(c);cost[y].push_back(c);

    }

    bellman();

    for (i=2;i<=n;++i)

        printf("%ld ",nr[i]);

    printf("\n");

return 0;

}
