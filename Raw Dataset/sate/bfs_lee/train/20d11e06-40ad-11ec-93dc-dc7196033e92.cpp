#include <stdio.h>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define NN 30010
#include <queue>
using namespace std;

ifstream in("sate.in");ofstream out("sate.out");
 int n , m , ni, nf;
struct nod{
int dist, info;
nod *next;
}*L[NN];


void adaug(int x , int y,int cost)
{
    //adaug pe y la lista lui x

nod * aux = new nod;
aux -> info = y;
aux->dist=cost;
aux-> next = L[x];
L[x]=aux;
}

void citire()
{
      in >> n >> m>> ni >>nf;

      for(int i = 0 ; i< m ; ++i )
      {
          int x, y,c;
          in >> x>> y>>c;
          adaug(x,y,c);
          adaug(y,x,c);
      }
}
bool viz[NN];

void bfs(int NOD, int D)
{viz[NOD]=true;
    if(NOD==nf){out<<D; exit(0);}

    else {
            for( nod * aux = L[NOD]; aux ; aux = aux -> next)
            if(!viz[aux->info])
            {
                if(NOD- aux->info >0)
                  {
                      D-=aux->dist;
                      bfs(aux->info,D);
                      D+=aux->dist;}
                      else {
                        D+=aux->dist;
                        bfs(aux->info,D);
                        D-=aux->dist;

                      }


                  }
    }
}





int main()
{ citire();
 bfs(ni,0);


    return 0;
}
