#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream cin("apm.in");

ofstream cout("apm.out");

const int lim=2e5+3;

struct Op

{

    int src;

    int dest;

    int cost;

};

vector<pair<int,int> > sol;

vector<Op> edge;

int link[lim];

int dim[lim];

int tata(int x)

{

    int cpy=x,aux;

    while(x!=link[x]) x=link[x];

    while(cpy!=link[cpy]) aux=cpy,cpy=link[cpy],link[aux]=x;

    return x;

}

void unite(int x,int y)

{

    x=tata(x);

    y=tata(y);

    if(dim[x]<dim[y]) swap(x,y);

    link[y]=x;

    dim[x]+=dim[y];

}

bool mycmp(Op a,Op b)

{

    return a.cost<b.cost;

}

int n,m,x,y,c,ans;

int main()

{

    cin>>n>>m;

    for(int i=1;i<=m;++i)

    {

        cin>>x>>y>>c;

        edge.push_back({x,y,c});

    }

    sort(edge.begin(),edge.end(),mycmp);

    for(int i=1;i<=n;++i)

    {

        link[i]=i;

        dim[i]=1;

    }

    for(auto t:edge)

    if(tata(t.src)!=tata(t.dest))

    {

        ans+=t.cost;

        sol.push_back({t.src,t.dest});

        unite(t.src,t.dest);

    }

    cout<<ans<<'\n'<<sol.size()<<'\n';

    for(auto t:sol)

        cout<<t.first<<' '<<t.second<<'\n';

    return 0;

}
