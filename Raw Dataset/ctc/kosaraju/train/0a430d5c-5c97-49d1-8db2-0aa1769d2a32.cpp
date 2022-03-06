#include <fstream>
#include <vector>


using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");



vector <int> graph[100002], grapht[100002],sol[100002];

int st[100002];

bool viz[100002];



void so(int nod, int nr)

{

    viz[nod]=1;

    for(int i=0;i<grapht[nod].size();++i)

        if(!viz[grapht[nod][i]])

            so(grapht[nod][i],nr);

    sol[nr].push_back(nod);

}

void sortt(int nod)

{

    viz[nod]=1;

    for(int i=0;i<graph[nod].size();++i)

        if(!viz[graph[nod][i]])

            sortt(graph[nod][i]);

    st[++st[0]]=nod;

}

int main()

{

    int m,n,x,y,nr=0;

    f>>n>>m;

    for(int i=1;i<=m;++i)

    {

        f>>x>>y;

        graph[x].push_back(y);

        grapht[y].push_back(x);

    }

    for(int i=1;i<=n;++i)

        if(!viz[i])

            sortt(i);

    for(int i=1;i<=n;++i) viz[i]=0;

    for(int i=n;i>=1;--i)

        if(!viz[st[i]])

            so(st[i],++nr);

    g<<nr<<'\n';

    for(int i=1;i<=nr;++i)

    {

        for(int j=0;j<sol[i].size();++j)

            g<<sol[i][j]<<' ';

        g<<'\n';

    }

    return 0;

}
