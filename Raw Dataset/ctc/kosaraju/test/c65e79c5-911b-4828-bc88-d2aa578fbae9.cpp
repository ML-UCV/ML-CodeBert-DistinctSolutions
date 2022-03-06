#include <bits/stdc++.h>
using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

struct noduri{vector <int> out;vector <int> in;}v[100003];

struct comp{vector <int> nd;}emptyaux;

vector <comp> cmp;

stack <int> st;

int n,m,i;

bool trout[100003],trin[100003];

void dfsout(int nod)

{

    trout[nod]=1;

    for(int i=0;i<v[nod].out.size();i++)

    {

        int nextnode=v[nod].out[i];

        if(trout[nextnode]==0)

        {

            dfsout(nextnode);

        }

    }

    st.push(nod);

}

void dfsin(int nod,int root)

{

    trin[nod]=1;

    if(nod==root)cmp.push_back(emptyaux);

    cmp[cmp.size()-1].nd.push_back(nod);

    for(int i=0;i<v[nod].in.size();i++)

    {

        int prevnode=v[nod].in[i];

        if(trin[prevnode]==0)

            dfsin(prevnode,root);

    }

}

int main()

{

    f>>n>>m;

    for(i=1;i<=m;i++)

    {

        int x,y;

        f>>x>>y;

        v[x].out.push_back(y);

        v[y].in.push_back(x);

    }

    i=0;

    for(i=1;i<=n;i++)

        if(trout[i]==0)

            dfsout(i);

    while(st.size())

    {

        int nod=st.top();

        if(trin[nod]==0)

            dfsin(nod,nod);

        st.pop();

    }

    g<<cmp.size()<<'\n';

    for(i=0;i<cmp.size();i++)

    {

        for(int j=0;j<cmp[i].nd.size();j++)

            g<<cmp[i].nd[j]<<" ";

        g<<'\n';

    }

}
