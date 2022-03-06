#include <bits/stdc++.h>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

int n,m,i,x,y,ctc,vecin,nod,nivel,niv[100010],low[100010];

bitset<100010> f,instack;

vector<int> L[100010],c[100010];

stack<int> st;

void dfs(int nod) {

    nivel++;

    f[nod]=1;

    low[nod]=niv[nod]=nivel;

    st.push(nod);

    instack[nod]=1;

    for (auto vecin:L[nod]) {

        if (f[vecin]==0) {

            dfs(vecin);

            low[nod]=min(low[nod],low[vecin]);

        }

        else

            if (instack[vecin])

                low[nod]=min(low[nod],niv[vecin]);

    }

    if (low[nod]==niv[nod]) {

        ctc++;

        do {

            x=st.top();

            st.pop();

            instack[x]=0;

            c[ctc].push_back(x);

        } while (x!=nod);

    }

}

int main() {

    fin>>n>>m;

    for (i=1;i<=m;i++) {

        fin>>x>>y;

        L[x].push_back(y);

    }

    for (i=1;i<=n;i++)

        if (f[i]==0)

            dfs(i);

    fout<<ctc<<"\n";

    for (i=1;i<=ctc;i++) {

        for (auto it:c[i])

            fout<<it<<" ";

        fout<<"\n";

    }

    return 0;

}
