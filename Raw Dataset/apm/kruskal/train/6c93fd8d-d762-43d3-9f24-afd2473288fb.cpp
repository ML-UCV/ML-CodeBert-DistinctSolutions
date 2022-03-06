#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

pair <int, pair<int,int> > c[400010];

pair <int,int> sol[400010];

int t[400010];

int i,n,m,u,rx,ry,cost,x,y;



int aflareRadacina(int i) {

    while (t[i]>0) {

        i=t[i];

    }

    return i;

}



int main() {

    ifstream fin("apm.in");

    ofstream fout("apm.out");

    fin>>n>>m;

    for (i=1;i<=m;i++) {

        fin>>c[i].second.first>>c[i].second.second;

        fin>>c[i].first;

    }

    sort(c+1,c+m+1);

    for (i=1;i<=n;i++) {

        t[i]=-1;

    }

    for (i=1;i<=m;i++) {

        x=c[i].second.first;

        y=c[i].second.second;

        rx=aflareRadacina(x);

        ry=aflareRadacina(y);

        if (rx!=ry) {

            if (t[rx]>t[ry]) {

                t[ry]+=t[rx];

                t[rx]=ry;

            }

            else {

                t[rx]+=t[ry];

                t[ry]=rx;

            }

            sol[++u]={x,y};

            cost+=c[i].first;

        }

    }

    fout<<cost<<"\n"<<u<<"\n";

    for (i=1;i<=u;i++) {

        fout<<sol[i].first<<" "<<sol[i].second<<"\n";

    }

    return 0;

}
