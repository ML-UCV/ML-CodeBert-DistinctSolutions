#include<fstream>
#include<set>
#include<cmath>
#include<vector>
using namespace std;

ifstream in("dmin.in");

ofstream out("dmin.out");



struct dij{

 int nr;

 double cost;

};



struct classcomp {

  bool operator() (const dij& lhs, const dij& rhs) const

  {return lhs.cost<rhs.cost;}

};



const int nmax = 1506, mod = 104659;

const double eps = 0.000001;

int n, m, d[nmax];

vector<dij> vecini[nmax];

double vcost[nmax];

multiset<dij, classcomp> s;

bool poz[nmax];



void dijkstra(int x)

{

    vcost[x] = 0;

    poz[x] = 1;



    for(int i = 0; i<(int)vecini[x].size(); i++)

    {

        dij aux;



        aux.nr = vecini[x][i].nr;

        aux.cost = vecini[x][i].cost;



        s.insert(aux);

    }



    while(s.empty()==0)

    {

        dij aux = *s.begin();



        if(poz[aux.nr]==0)

        {

            vcost[aux.nr] = aux.cost;

            poz[aux.nr] = 1;



            for(int i = 0; i<(int)vecini[aux.nr].size(); i++)

            {

                if(poz[vecini[aux.nr][i].nr]==0)

                {

                    dij aux2;



                    aux2.cost = aux.cost + vecini[aux.nr][i].cost;

                    aux2.nr = vecini[aux.nr][i].nr;



                    s.insert(aux2);

                }

            }

        }



        s.erase(s.begin());

    }

}



void dijkstra2(int x)

{

    vcost[x] = 0;

    poz[x] = 1;

 d[x] = 1;



    for(int i = 0; i<(int)vecini[x].size(); i++)

    {

        dij aux;



        aux.nr = vecini[x][i].nr;

        aux.cost = vecini[x][i].cost;



  if(aux.cost - vcost[aux.nr]<eps && aux.cost - vcost[aux.nr]>-eps)

  {

   d[aux.nr] += d[x];

   d[aux.nr] %= mod;

  }



        s.insert(aux);

    }



    while(s.empty()==0)

    {

        dij aux = *s.begin();



        if(poz[aux.nr]==0)

        {

            vcost[aux.nr] = aux.cost;

            poz[aux.nr] = 1;



            for(int i = 0; i<(int)vecini[aux.nr].size(); i++)

            {

    dij aux2;



                    aux2.cost = aux.cost + vecini[aux.nr][i].cost;

                    aux2.nr = vecini[aux.nr][i].nr;



     if(aux2.cost - vcost[aux2.nr]<eps && aux2.cost - vcost[aux2.nr]>-eps)

     {

      d[aux2.nr] += d[aux.nr];

      d[aux2.nr] %= mod;

     }



                if(poz[vecini[aux.nr][i].nr]==0)

                {



                    s.insert(aux2);

                }

            }

        }



        s.erase(s.begin());

    }

}



int main(){

 int player_unu=0;



 in>>n>>m;

 for(int i = 0; i<m; i++)

 {

  int a, b;

  double cost;



  in>>a>>b>>cost;



  cost = log(cost);



  dij aux1;

  aux1.nr = b;

  aux1.cost = cost;

  vecini[a].push_back(aux1);



  dij aux2;

  aux2.nr = a;

  aux2.cost = cost;

  vecini[b].push_back(aux2);

 }



 dijkstra(1);



 for(int i = 1; i<=n; i++)

  poz[i] = 0;

 s.clear();



 dijkstra2(1);



 for(int i = 2; i<=n; i++)

  out<<d[i]<<' ';



 return player_unu;

}
