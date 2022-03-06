#include<cstdio>
#include<vector>
#include<algorithm>
const int NMAX = 200000;

struct edge{

int from , to;

int cost;

bool operator <(const edge &other){

    return cost < other.cost;

}

};

struct dublu{

int x , y;

};

dublu Sol[NMAX + 1];

std::vector<edge> Edges;

int father[NMAX + 1];

int getFather(int x){

    if(father[x] == x)

        return x;

    father[x] = getFather(father[x]);

    return father[x];

}

void join(int x , int y){

    father[getFather(x)] = getFather(y);

}

int main()

{

    freopen("apm.in" ,"r",stdin);

    freopen("apm.out" ,"w",stdout);

    int n , m;

    scanf("%d%d" , &n , &m);

    for(int i = 1; i <= m ; i ++)

    {

        int x, y, cost;

        scanf("%d%d%d", &x, &y, &cost);

        Edges.push_back({x, y, cost});



    }

    std:: sort(Edges.begin(), Edges.end());

    int k = 0;

    for(int i = 1; i <= n ; i ++)

    {

        father[i] = i;

    }

    int totalCost = 0;

    for(int i = 0; i < m ; i ++){

        int x = Edges[i].from;

        int y = Edges[i].to;



        if(getFather(x) != getFather(y)){

            join(x , y);

            totalCost += Edges[i].cost;

            Sol[k ++ ] = {x , y};

        }

    }

    printf("%d\n" , totalCost);

    printf("%d\n" , k);

    for(auto x : Sol){

        printf("%d %d\n", x.x, x.y);

    }

}
