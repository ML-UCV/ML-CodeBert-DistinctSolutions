#include<fstream>
#include<vector>
#include<set>
#include<queue>
#include<cmath>


using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");
int n, m;

vector <pair <int, double> > g[1503];

queue < int >q;

bool use[1503];

void read(){

    fin >> n >> m;

    for(int i = 1; i <= m; i++){

        int x, y;

        double c;

        fin >>x >>y >>c;

        c = log(c);

        g[x].push_back(make_pair(y,c));

        g[y].push_back(make_pair(x,c));



    }

}



void Dijkstra(int r){

    int nr_drumuri[1503];

    double dist[1503];

    for(int i = 1; i <= n; i++) nr_drumuri[i] = 0, dist[i] = (1<<30);;



    dist[r] = 0;

    q.push(r);

    nr_drumuri[r] = 1;

    use[r] = true;

    while(! q.empty()){

        int nod = q.front();

        q.pop();

        use[nod] = false;



        for(int i = 0 ; i < g[nod].size(); i++){

            double cost = g[nod][i].second;

            int y = g[nod][i].first;

             if(fabs (dist[y] - dist[nod] - cost) < 0.0000001 ){

                nr_drumuri[y] = (nr_drumuri[y] + nr_drumuri[nod] ) %104659;

            }

            if(dist[y] - dist[nod] - cost>0.0000001 ){



                if(use[y] == false)

                    q.push(y), use[y] = true;

                dist[y] = dist[nod] + cost;

                nr_drumuri[y] = nr_drumuri[nod] %104659;

            }





        }

    }

    for(int i = 2; i<= n ;i++)

        fout << nr_drumuri[i] <<" ";

}

int main(){

    read();

    Dijkstra(1);

    fin.close();

    return 0;



}
