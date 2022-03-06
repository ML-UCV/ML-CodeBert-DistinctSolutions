#include <fstream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
using namespace std;



ifstream f("dmin.in");

ofstream g("dmin.out");



int nodes, edges, roadsNum[1510];

double distances[1510];

vector < pair<int, double> > G[1510];

queue <int> QU;

bool mark[1510];



class cmp {

public:

    bool operator() (pair<int, double> d1, pair<int, double> d2)

    {

        return d1.second > d2.second;

    }

};

priority_queue< pair<int, double>, vector< pair<int, double> >, cmp > H;



void dijkstra(int node)

{

    roadsNum[node] = 1;



    for (int i = 2; i <= nodes; i++)

        distances[i] = 2000000000;



    H.push(make_pair(node, 0));



    while (!H.empty()) {

        int crtNode = H.top().first;

        H.pop();



        if (mark[crtNode])

            continue;

        mark[crtNode] = true;



        for (vector < pair<int, double> >::iterator it = G[crtNode].begin(); it != G[crtNode].end(); it++) {

            int q = it->first;

            if (!mark[it->first]) {

                if (distances[it->first] - (distances[crtNode] + it->second) > 1.e-10) {

                    distances[it->first] = distances[crtNode] + it->second;

                    H.push(make_pair(it->first, distances[it->first]));

                    roadsNum[it->first] = roadsNum[crtNode];

                }

                else if (abs(distances[it->first] - (distances[crtNode] + it->second)) <= 1.e-10)

                    roadsNum[it->first] = (roadsNum[it->first] + roadsNum[crtNode]) % 104659;

            }

        }

    }

}



int main()

{

    f >> nodes >> edges;



    int n1, n2, c;

    for (int i = 1; i <= edges; i++) {

        f >> n1 >> n2 >> c;



        G[n1].push_back(make_pair(n2, log10(c)));

        G[n2].push_back(make_pair(n1, log10(c)));

    }



    dijkstra(1);





    for (int i = 2; i <= nodes; i++)

        g << roadsNum[i] << " ";



    return 0;

}
