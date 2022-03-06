#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream in("ctc.in");

ofstream out("ctc.out");

int n,m,a1,b1,ap[100005],ind,indice[100005],t;

bool b[100005];

vector <int> v[100005];

vector <int>sol1[100005];

stack <int> s;

void sol(int nod)

{

    indice[nod]=++ind;

    ap[nod]=ind;

    s.push(nod);

    b[nod]=1;

    for(auto i:v[nod])

    {

        if(indice[i]==0)

        {

            sol(i);

            ap[nod]=min(ap[nod],ap[i]);

        }

        else if(b[i])

        {

            ap[nod]=min(ap[nod],ap[i]);

        }

    }

    if(ap[nod]==indice[nod])

    {

        t++;

        while(s.top()!=nod)

        {

            sol1[t].push_back(s.top());

            b[s.top()]=0;

            s.pop();

        }

        b[s.top()]=0;

        sol1[t].push_back(s.top());

        s.pop();

    }

}

int main()

{

    in>>n>>m;

    for(int i=1;i<=m;i++)

    {

        in>>a1>>b1;

        v[a1].push_back(b1);

    }

    for(int i=1;i<=n;i++)

    {

        if(indice[i]==0)

        {

            sol(i);

        }

    }

    out<<t<<'\n';

    for(int i=1;i<=t;i++)

    {

        for(auto j:sol1[i])out<<j<<' ';

        out<<'\n';

    }

    return 0;

}
