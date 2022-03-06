#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



ifstream cin("apm.in");

ofstream cout("apm.out");



pair < int , pair < int , int > > pr[200005 * 2];

vector < pair < int , int > > Answer;

int ds[200005], N, M, minCost;



int root(int x)

{

    while(ds[x] != x){

        ds[x] = ds[ds[x]];

        x = ds[x];

    }

    return x;

}



void UnionFind(int x, int y)

{

    int px = root(x);

    int py = root(y);

    ds[px] = ds[py];

}



int Kruskal()

{

    int x, y, cost;

    for(int i = 1; i <= M; i++){

        x = pr[i].second.first;

        y = pr[i].second.second;

        cost = pr[i].first;

        if(root(x) != root(y)){

            UnionFind(x,y);

            Answer.push_back(make_pair(x,y));

            minCost += cost;

        }

    }

    return minCost;

}



int main()

{



    int x, y, c;

    cin >> N >> M;

    for(int i = 1; i <= M; i++){

        cin >> x >> y >> c;

        pr[i] = make_pair(c,make_pair(x,y));

    }

    sort(pr + 1, pr + M + 1);

    for(int i = 1; i <= N; i++){

        ds[i] = i;

    }

    Kruskal();

    cout << minCost << "\n" << Answer.size() << "\n";

    for(int i = 0; i < Answer.size(); i++){

        cout << Answer[i].first << " " << Answer[i].second << "\n";

    }

    return 0;

}
