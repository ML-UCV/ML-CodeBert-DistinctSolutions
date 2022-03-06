#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


using namespace std;



int N, M, viz[200005], cost_total;

vector <pair <int, int> > L[200005], sol;

priority_queue < pair <int, pair <int, int > > > pq;



int main()

{

    ifstream fin("apm.in");

    ofstream fout("apm.out");



    fin >> N >> M;



    int x,y,c;



    for (int i = 1; i <= M; i++)

    {

        fin >> x >> y >> c;

        L[x].push_back({y, c});

        L[y].push_back({x, c});

    }



    int r = 1;

    pair <int, pair <int, int> > minim;

    viz[r] = 1;

    for (int i = 0; i < L[r].size(); i++)

    {

        pq.push({-L[r][i].second, {r, L[r][i].first}});

    }



    while (!pq.empty())

    {

        minim = pq.top();

        pq.pop();



        int next = minim.second.second;



        if (viz[next] == 0)

        {

            viz[next] = 1;

            sol.push_back(minim.second);

            cost_total = cost_total - minim.first;



            for (int i = 0; i < L[next].size(); i++)

            {

                pq.push({-L[next][i].second, {next, L[next][i].first}});

            }

        }



    }



    fout << cost_total << "\n" << sol.size() << "\n";

    for (int i = 0; i < sol.size(); i++)

    {

        fout << sol[i].first << " " << sol[i].second << "\n";

    }



    fin.close();

    return 0;

}
