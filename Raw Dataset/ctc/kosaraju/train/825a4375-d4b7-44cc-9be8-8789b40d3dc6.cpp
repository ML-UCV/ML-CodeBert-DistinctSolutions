#include <bits/stdc++.h>
using namespace std;

ifstream in("ctc.in");

ofstream out("ctc.out");

const int lim=1e5+4;

vector<int> vec[lim];

vector<int> rev[lim];

stack<int> st;

bool ok[lim];

bool df(int nod)

{

    ok[nod]=true;

    for(int x:vec[nod])

    if(!ok[x]) df(x);

    st.push(nod);

}

vector<int> grupe[lim];

int cnt;

void df2(int nod)

{

    ok[nod]=true;

    grupe[cnt].push_back(nod);

    for(int x:rev[nod])

    if(!ok[x]) df2(x);

}

int main()

{

    int n,m,x,y;

    in>>n>>m;

    for(int i=1;i<=m;++i)

    {

        in>>x>>y;

        vec[x].push_back(y);

        rev[y].push_back(x);

    }

    for(int i=1;i<=n;++i)

    if(!ok[i]) df(i);

    for(int i=1;i<=n;++i)

        ok[i]=false;

    while(!st.empty())

    {

        int x=st.top(); st.pop();

        if(ok[x]) continue;

        ++cnt;

        df2(x);

    }

    out<<cnt<<'\n';

    for(int i=1;i<=cnt;++i)

    {

        for(auto x:grupe[i])

            out<<x<<' ';

        out<<'\n';

    }

    return 0;

}
