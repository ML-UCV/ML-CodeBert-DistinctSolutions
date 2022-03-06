#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <queue>




using namespace std;



ifstream f("party.in");

ofstream g("party.out");



int N, M, K;

int MinLevel[210], Level[210], Component[210];

int In[210], Out[210];

int Simetric[210], Value[210];

vector<int> G[210], NG[210];

bool InStack[210], E[210][210], Removed[210];

stack<int> S;

queue<int> Q;



int Negate (int x)

{

    return (x<=N?x+N:x-N);

}



void Build (int x, int y)

{

    G[Negate(x)].push_back(y);

    G[Negate(y)].push_back(x);

}



void Read ()

{

    int x, y, z;

    f >> N >> M;

    for (int i=1; i<=M; i++)

    {

        f >> x >> y >> z;



        if (z>1) x=Negate(x);

        if (z%2) y=Negate(y);

        Build(x, y);

    }

    M=0;



    f.close();

}



void DoTarjan (int node)

{

    Level[node]=MinLevel[node]=++K;

    S.push(node);

    InStack[node]=1;



    for (vector<int>::iterator it=G[node].begin(); it!=G[node].end(); ++it)

    {

        if (!Level[*it])

        {

            DoTarjan(*it);

            MinLevel[node]=min(MinLevel[node], MinLevel[*it]);

            continue;

        }

        if (InStack[*it])

            MinLevel[node]=min(MinLevel[node], Level[*it]);

    }



    if (Level[node]==MinLevel[node])

    {

        ++M;

        int cnode;

        do {

            cnode=S.top();

            InStack[S.top()]=0;

            Component[S.top()]=M;

            S.pop();

        } while (cnode!=node);

    }

}



void BuildComp ()

{

    for (int i=1; i<=2*N; i++)

        if (!Level[i])

            DoTarjan(i);



    for (int i=1; i<=2*N; i++)

        for (vector<int>::iterator it=G[i].begin(); it!=G[i].end(); ++it)

            if (Component[i]!=Component[*it])

                E[Component[i]][Component[*it]]=1;



    for (int i=1; i<=2*N; i++)

    {

        if (Component[i]==Component[Negate(i)])

        {

            g << 0 << '\n';

            g.close();

            exit(0);

        }



        Simetric[Component[i]]=Component[Negate(i)];

    }



    for (int i=1; i<=M; i++)

        for (int j=1; j<=M; j++)

            if (E[i][j])

            {

                NG[i].push_back(j);

                Out[i]++;

                In[j]++;

            }

}



void Solve ()

{

    for (int i=1; i<=M; i++)

        if (In[i]==0)

            Q.push(i);



    while (!Q.empty())

    {

        int node=Q.front();

        Q.pop();



        Removed[node]=1;

        Removed[Simetric[node]]=1;

        Value[node]=0;

        Value[Simetric[node]]=1;



        for (vector<int>::iterator it=NG[node].begin(); it!=NG[node].end(); ++it)

            if (!Removed[*it])

            {

                --In[*it];

                if (In[*it]<=0)

                    Q.push(*it);

            }

    }

}



void Print ()

{

    int ANS=0;



    for (int i=1; i<=N; i++)

        if (Value[Component[i]]==1)

            ANS++;



    g << ANS << '\n';



    for (int i=1; i<=N; i++)

        if (Value[Component[i]]==1)

            g << i << '\n';



    g.close();

}



int main ()

{

    Read();

    BuildComp();

    Solve();

    Print();



    return 0;

}
