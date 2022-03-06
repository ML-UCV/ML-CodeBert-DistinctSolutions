#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>




using namespace std;

const double eps=1e-10;

const double INFINIT=9999999999;

vector< pair<int,double> > Graf[1505];

queue<int> Q;

int N,M,x,y,z,D[1505];

bool InCoada[1505];

double Dmin[1505];



void Read()

{

    ifstream g("dmin.in");

    g>>N>>M;

    for(int i=1;i<=M;i++)

    {

        g>>x>>y>>z;

        double z1=log(z);

        Graf[x].push_back(make_pair(y,z1));

        Graf[y].push_back(make_pair(x,z1));

    }

}



void BellManFord()

{

    for(int i=1;i<=N;i++)

        Dmin[i]=INFINIT;



    Q.push(1);

    D[1]=1;Dmin[1]=0.0;InCoada[1]=true;

    while(!Q.empty())

    {

        int nod=Q.front();

        Q.pop();

        InCoada[nod]=false;

        for(vector<pair<int,double> >::iterator it=Graf[nod].begin();it!=Graf[nod].end();it++)

        {

            int vecin=it->first;

            double cost=it->second;

            if(Dmin[nod]+cost-Dmin[vecin]< -eps)

            {

                D[vecin]=D[nod];

                Dmin[vecin]=Dmin[nod]+cost;

                if(!InCoada[vecin])

                {

                    Q.push(vecin);

                    InCoada[vecin]=true;

                }

            }

            else

            {

                if(fabs(Dmin[nod]+cost-Dmin[vecin])<=eps)

                {

                    D[vecin]=(D[vecin]+D[nod])%104659;

                    if (!InCoada[vecin])

                    {

                        Q.push(vecin);

                        InCoada[vecin]=true;

                    }

                }

            }

        }

    }

}



void Write()

{

    ofstream f("dmin.out");

    for(int i=2;i<=N;i++)

        f<<D[i]<<' ';

}



int main()

{

    Read();

    BellManFord();

    Write();

}
