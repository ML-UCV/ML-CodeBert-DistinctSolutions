#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



int n, m,sum=0;

int tree[200005];



struct muchie{

    int x, y, cost;

    bool operator<(const muchie &other) const {

        if(cost == other.cost)

        {

            if(x == other.x)

                return y<other.y;

            return x<other.x;

        }

        return cost<other.cost;

    }

}muchii[400005], rez[400005];



int hai(int x){

    if(tree[x] == x)

        return x;



    int aux = hai(tree[x]);

    tree[x]=aux;

    return aux;



}



void rezolvare(){

    int nrmuchii = 0;

    for(int i=1; i<=m && nrmuchii <n-1; i++){

        int r1 = hai(muchii[i].x), r2 = hai(muchii[i].y);

        if(r1 != r2){

            tree[r1]=r2;

            rez[nrmuchii++]={muchii[i].x, muchii[i].y};

            sum+=muchii[i].cost;

        }

    }

}

void citire(){

    f>>n>>m;

    for(int i=1; i<=n; i++)

        tree[i] = i;

    for(int i=1; i<=m; i++){

        f >> muchii[i].x >> muchii[i].y >> muchii[i].cost;

    }

}

int main()

{

    citire();

    sort(muchii + 1, muchii + m + 1);

    rezolvare();

    g<<sum<<'\n'<<n-1<<'\n';

    for(int i=0; i<n-1; i++)

        g << rez[i].x << " " << rez[i].y << '\n';

    return 0;

}
