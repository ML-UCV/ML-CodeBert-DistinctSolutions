#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;



ifstream cin("apm.in");

ofstream cout("apm.out");



int ds[200005];

pair <int , pair <int,int>> pr[200005];

vector < pair < int , int > > ans;

int N, M, minCost;



void init()

{

    for(int i = 1; i <= N; i++){

        ds[i] = i;

    }

}



int root(int x)

{

    while(ds[x] != x){

        ds[x] = ds[ds[x]];

        x = ds[x];

    }

    return x;

}



void Union(int x, int y)

{

    int px = root(x);

    int py = root(y);

    ds[px] = ds[py];

}



int Kursk()

{

    int cost, x, y;

    for(int i = 1; i <= M; i++){

        x = pr[i].second.first;

        y = pr[i].second.second;



        cost = pr[i].first;

        if(root(x) != root(y)){



            minCost += cost;

            Union(x,y);

            ans.push_back(make_pair(x,y));

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

    sort (pr + 1, pr + M + 1);

    init();

    Kursk();

    cout << minCost << "\n" << ans.size() << "\n";

    for(int i = 0; i < ans.size(); i++){

        cout << ans[i].first << " " << ans[i].second << "\n";

    }

    return 0;

}
