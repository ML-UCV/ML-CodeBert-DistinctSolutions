#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("apm.in");

ofstream cout("apm.out");

struct muchie{

    int x,y,c;

}v[400005];

pair<int, int> p[400005];

int t[200005], nr[200005];

int radacina(int x){

    if(t[x]==0){

        return x;

    }

    t[x]=radacina(t[x]);

    return t[x];



}

void reuniune(int x, int y){

    int rx=radacina(x);

    int ry=radacina(y);

    if(nr[rx]<nr[ry]){

        t[rx]=ry;

        nr[ry]+=nr[rx];

    }

    else{

        t[ry]=rx;

        nr[rx]+=nr[ry];

    }

}

bool cmp(muchie a, muchie b){

    return(a.c<b.c);

}

int main()

{

    int n,m, total=0;

    cin>>n>>m;



    for(int i=1;i<=m;i++){

        cin>>v[i].x>>v[i].y>>v[i].c;

    }

    sort(v+1,v+m+1,cmp);

    int k=0;

    for(int i=1;i<=m;i++){

        if(radacina(v[i].x)!=radacina(v[i].y)){

            reuniune(v[i].x,v[i].y);

            p[++k].first=v[i].x;

            p[k].second=v[i].y;

        total+=v[i].c;

        }

    }

    cout<<total<<'\n'<<k<<'\n';

    for(int i=1;i<=k;i++){

        cout<<p[i].first<<" "<<p[i].second<<'\n';

    }

    return 0;

}
