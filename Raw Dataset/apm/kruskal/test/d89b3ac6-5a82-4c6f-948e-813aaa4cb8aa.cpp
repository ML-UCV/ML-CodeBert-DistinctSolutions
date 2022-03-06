#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("apm.in");

ofstream fout ("apm.out");

int T[200010], S[200010];

int a,b,Ra,Rb,n,m,i,sol,nr;

int R(int x)

{

    while(T[x]>0)

        x=T[x];



    return x;

}



pair< int, pair<int, int> > V[400010];



int main ()

{

    fin>>n>>m;

    for(i=1;i<=m;i++)

        fin>>V[i].second.first>>V[i].second.second>>V[i].first;

    sort(V+1,V+m+1);



    for(i=1;i<=n;i++)

        T[i]=-1;

    for(i=1;i<=m;i++)

    {

        a=V[i].second.first;

        b=V[i].second.second;



        Ra=R(a);

        Rb=R(b);



        if(Ra!=Rb)

        {

            if(-T[Ra]>-T[Rb])

            {

                T[Ra]=T[Ra]+T[Rb];

                T[Rb]=Ra;

            }

            else

            {

                T[Rb]=T[Rb]+T[Ra];

                T[Ra]=Rb;

            }

            sol=sol+V[i].first;



            nr++;

            S[nr]=i;

            if(nr==n-1)

                break;

        }

    }

    fout<<sol<<"\n"<<n-1<<"\n";

    for(i=1;i<=nr;i++)

        fout<<V[S[i]].second.second<<" "<<V[S[i]].second.first<<"\n";

    return 0;

}
