#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
int sum;

int cost[200003];

int returns[200003];



bool marked[200003];



int N, M;



struct Edge

{

    int to;

    int cost;

};



vector<Edge> G[200003];

class CompareClass

{

public:

    bool operator() (const Edge& a, const Edge& b) const

    {

        if( a.cost < b.cost)

            return 0;

        return 1;

    }

};



priority_queue<Edge, vector<Edge>, CompareClass> pq;



void read(){

    ifstream fin("apm.in");



    fin >> N >> M;



    int X, Y, C;



    Edge aux;



    while( M-- )

    {

        fin >> X >> Y >> C;

        aux.cost = C;

        aux.to = Y;

        G[X].push_back(aux);

        aux.to = X;

        G[Y].push_back(aux);

    }



    fin.close();

}



void write(){

    ofstream fout("apm.out");

    fout << sum << "\n";

    fout << N-1 << "\n";



    for( int i = 2; i <= N; i++ )

        fout << i << " " << returns[i] << "\n";



    fout.close();

}



int main()

{

    read();



    marked[1] = true;





    for( int i = 1; i <= N; i++ )

        cost[i] = 5000;



    Edge aux;

    for( int i = 0; i < G[1].size(); i++ )

    {

        if( G[1][i].cost < cost[G[1][i].to] )

        {

            returns[G[1][i].to] = 1;

            cost[G[1][i].to] = G[1][i].cost;

            aux.to = G[1][i].to;

            aux.cost =G[1][i].cost;

            pq.push(aux);

        }

    }



    int i;



    for( int j = 1; j < N; j++ )

    {

        while( marked[pq.top().to] )

            pq.pop();



        aux = pq.top();

        i = aux.to;

        marked[i] = 1;

        sum += cost[i];

        for( int k = 0; k < G[i].size(); k++ ){

            if( !marked[G[i][k].to] ){

                if( cost[G[i][k].to] > G[i][k].cost )

                {

                    returns[G[i][k].to] = i;

                    cost[G[i][k].to] = G[i][k].cost;

                    aux.to = G[i][k].to;

                    aux.cost = G[i][k].cost;

                    pq.push(aux);

                }

            }

        }

    }



    write();



    return 0;



}
