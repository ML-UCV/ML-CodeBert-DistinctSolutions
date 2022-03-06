#include <bits/stdc++.h>
#include <iostream>


using namespace std;



ifstream in ("apm.in");

ofstream out ("apm.out");





vector<pair<int,int>>adiacenta[200000];

int n,m;

int total = 0;

priority_queue< pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>> > pq;

vector<int>vizitat;

vector <int> parinte;

vector <int> cost;





void Prim(int i)

{



    pq.push(make_pair(0, i));

    cost[i] = 0;





    int varf;

    while (!pq.empty())

    {

        varf = pq.top().second;

        vizitat[varf] = true;







        pq.pop();



        for (pair<int,int> e : adiacenta[varf])

        {

            int vecin = e.first;

            int c = e.second;



            if (!vizitat[vecin] && c < cost[vecin])

            {







                cost[vecin] = c;

                pq.push(make_pair(cost[vecin], vecin));







                parinte[vecin] = varf;



            }



        }





    }





}





int main()

{





    in>>n>>m;

    int x,y,c;



    for(int i = 0; i<m ; i++)

    {

        in>>x>>y>>c;



        adiacenta[x-1].push_back(make_pair(y-1, c));

        adiacenta[y-1].push_back(make_pair(x-1, c));



    }



    vizitat.assign(n, false);

    cost.assign(n,10000);

    parinte.assign(n,-1);



    Prim(0);







    for(int i = 1; i <n; i++)

    {





        total+= cost[i];



    }

    out<<total<<"\n";



    out<<parinte.size() - 1<<"\n";



    for(int i = 1; i <n; i++)

    {





        out<<parinte[i] + 1<<" "<<i + 1<<"\n";



    }
    return 0;

}
