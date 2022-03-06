#include <bits/stdc++.h>
using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int n,m,nrOrd;

vector<int> ord;

vector<int> lowLink;

vector<bool>inStack;

stack<int> st;



vector<vector<int>> v;

vector<vector<int>> sccs;



void Read()

{

    f>>n>>m;

    v.resize(m+1);

    ord.resize(n+1);

    lowLink.resize(n+1);

    inStack.resize(n+1);

    for(int i=1;i<=m;i++)

    {

        int x,y;

        f>>x>>y;

        v[x].emplace_back(y);

    }

    f.close();

}



void dfs(int nod)

{

    st.push(nod);

    inStack[nod] = true;

    lowLink[nod] = ord[nod] = ++nrOrd;



    for(auto& vecin : v[nod])

    {

        if(!ord[vecin])

        {

            dfs(vecin);

            lowLink[nod] = min(lowLink[nod], lowLink[vecin]);

        }

        else if(inStack[vecin])

            lowLink[nod] = min(lowLink[nod], lowLink[vecin]);

    }



    if(lowLink[nod] == ord[nod])

    {

        sccs.emplace_back();

        while(true)

        {

            int top = st.top();

            st.pop();

            inStack[top] = false;



            lowLink[top] = ord[nod];

            sccs.back().push_back(top);

            if(top == nod)

                break;

        }

    }

}



int main()

{

    Read();

    dfs(1);

    for(int i=1;i<=n;i++)

        if(!ord[i])

            dfs(i);



    g<<sccs.size()<<"\n";

    for(auto& vec : sccs)

    {

        for(auto& it : vec)

            g<<it<<" ";

        g<<"\n";

    }

    g.close();

    return 0;

}
