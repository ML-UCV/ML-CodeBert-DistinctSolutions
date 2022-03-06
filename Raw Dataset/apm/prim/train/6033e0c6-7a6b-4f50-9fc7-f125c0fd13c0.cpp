#include <fstream>
#include <vector>
#include <queue>






using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



struct muc{

    int x;

    int y;

    int pret;



    bool operator<(const muc &other) const {

        if(pret != other.pret)

            return pret > other.pret;

        return y > other.y;

    }



};





int n, m, s;

int viz[200005];

muc fin[200005];

vector<muc> graph[200005];

priority_queue<muc> Q;



void read()

{

    int x, y, p;



    f>>n>>m;

    for(int i=1; i<=m; ++i)

    {

        f>>x>>y>>p;

        graph[x].push_back({x, y, p});

        graph[y].push_back({y, x, p});

    }

}



void addToQ(int nod)

{

    for(auto &v:graph[nod])

        Q.push(v);

}



void del_first()

{

    muc f = Q.top();

    while(viz[f.y] == 1)

    {

        Q.pop();

        f = Q.top();

    }

}





void solve()

{

    int muchii_act = 0;

    addToQ(1);

    viz[1] = 1;

    while(muchii_act < n-1)

    {

        del_first();

        muc f = Q.top();

        s += f.pret;

        viz[f.y] = 1;

        fin[muchii_act ++] = f;

        addToQ(f.y);

    }

}



void write()

{

    g<<s<<'\n'<<n-1<<'\n';

    for(int i=0; i < n-1; ++i)

    {

        g<<fin[i].x<<" "<<fin[i].y<<"\n";

    }

}
int main()

{

    read();

    solve();

    write();

    return 0;

}
