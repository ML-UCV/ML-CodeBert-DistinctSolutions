#include <fstream>
#include <vector>
#include <stack>
#include <iterator>


using namespace std;
vector <int> adj[100000],con,idx,lowlink,in_stack;

vector <vector <int> > G;

stack <int> S;

int n,m,x,y,indecs;

void citire()

    {

    ifstream fin ("ctc.in");

    fin>>n>>m;

    for (int i=1;i<=m;i++)

        {

        fin>>x>>y;

        adj[x-1].push_back(y-1);

        }

    fin.close();

    }

void afisare()

    {

    ofstream fout ("ctc.out");

    int l1=G.size();

    fout<<l1<<"\n";

    for (int i=0;i<l1;i++)

        {

        int l2=G[i].size();

        for (int j=0;j<l2;j++)

            fout<<G[i][j]+1<<" ";

        fout<<"\n";

        }

    fout.close();

    }

void tarjan(int n)

    {

    idx[n]=lowlink[n]=indecs;

    indecs++;

    S.push(n),in_stack[n]=1;

    vector <int>::const_iterator it;

    for (it = adj[n].begin();it!=adj[n].end();it++)

        {

        if (idx[*it]==-1)

            {

            tarjan(*it);

            lowlink[n]=((lowlink[n]) < (lowlink[*it]) ? (lowlink[n]) : (lowlink[*it]));

            }

        else if (in_stack[*it])

            lowlink[n]=((lowlink[n]) < (lowlink[*it]) ? (lowlink[n]) : (lowlink[*it]));

        }

    if (idx[n] == lowlink[n])

        {

        con.clear();

        int node;

        do {

            node=S.top();

            con.push_back(node);

            S.pop();

            in_stack[node]=0;

            }

        while (node != n);

        G.push_back(con);

        }

    }

int main ()

    {

    citire();

    idx.resize(n);

    lowlink.resize(n);

    in_stack.resize(n);

    idx.assign(n,-1);

    in_stack.assign(n,0);

    for (int i=0;i<n;i++)

        if (idx[i]==-1)

            tarjan(i);

    afisare();

    return 0;

    }
