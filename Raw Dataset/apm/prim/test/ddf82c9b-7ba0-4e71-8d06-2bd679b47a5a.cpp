#include <fstream>
#include <vector>
#include <queue>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



int n, m;

int x, y, c, sum;

int viz[200005], nrmuchii;





struct muchie{

    int x;

    int y;

    int cost;



    bool operator<(const muchie &other) const {

        if(cost!=other.cost)

            return cost>other.cost;

        return y>other.y;

    }

};

muchie sol[200005];

vector<muchie> graph[200005];

priority_queue<muchie> Q;



void solve(){

    for(int i=2; i<=n; i++){

        muchie minima = Q.top();

        while(viz[minima.y] == 1){

            Q.pop();

            minima = Q.top();

        }



        sol[nrmuchii++] = {minima.x, minima.y};

        viz[minima.y]=1;



        sum =sum + minima.cost;

        for(auto &v:graph[minima.y])

            Q.push(v);

    }

}

int main()

{

    f>>n>>m;

    for(int i=1; i<=m; i++){

        f>>x>>y>>c;

        graph[x].push_back({x, y, c});

        graph[y].push_back({y, x, c});

    }

    for(auto &v:graph[1])

        Q.push(v);

    viz[1] = 1;

    solve();

    g<<sum<<'\n'<<n-1<<'\n';

    for(int i=0; i<n-1; i++)

        g<<sol[i].x<<" "<<sol[i].y<<'\n';

    return 0;

}
