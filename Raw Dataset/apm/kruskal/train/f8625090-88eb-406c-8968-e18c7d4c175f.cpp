#include <fstream>
#include <algorithm>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



struct muchie{

    int x, y;

    int cost;



    bool operator<(const muchie &other) const{

        if(cost==other.cost){

            if(x == other.x)

                return y<other.y;

            return x<other.x;

        }

        return cost<other.cost;

    }

}muchii[200005], sol[200005];



int T[200005], n, m;





void init_t(){

    for(int i=1; i<=n; i++)

        T[i] = i;

}



int opParc(int x){

    if(T[x] == x)

        return x;

    int ajut = opParc(T[x]);

    T[x]=ajut;

    return ajut;

}



int sum=0;

void solve(){

    int nrmuchii = 0;

    for(int i=0; i<m && nrmuchii <n-1; i++){

        int rad1 = opParc(muchii[i].x), rad2 = opParc(muchii[i].y);

        if(rad1!=rad2){

            T[rad1]=rad2;

            sol[nrmuchii++]={muchii[i].x, muchii[i].y};

            sum+=muchii[i].cost;

        }

    }

}



void citire(){

    f>>n>>m;

    for(int i=0; i<m; i++){

        f>>muchii[i].x>>muchii[i].y>>muchii[i].cost;

    }

}

int main()

{

    citire();

    init_t();

    sort(muchii, muchii+m);

    solve();

    g<<sum<<'\n'<<n-1<<'\n';

    for(int i=0; i<n-1; i++){

        g<<sol[i].x<<' '<<sol[i].y<<'\n';

    }

    return 0;

}
