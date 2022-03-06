#include <bits/stdc++.h>
using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



stack < int > st;

int viz[100005];

vector < int > adiac[100005];

vector < int > adiactrans[100005];

vector < int > compconex[100005];

int n,m;

int nod1,nod2;

int conex;



void dfs(int nod) {

    viz[nod]=1;

    for (auto k=adiac[nod].begin(); k!=adiac[nod].end(); ++k) {

        if (viz[*k]==0) {

            dfs(*k);

        }

    }

    st.push(nod);

}



void dfs_t(int nod) {

    viz[nod]=2;

    compconex[conex].push_back(nod);

    for (auto k=adiactrans[nod].begin(); k!=adiactrans[nod].end(); ++k) {

        if (viz[*k]==1) {

            dfs_t(*k);

        }

    }

}



int main()

{

    f >> n >> m;

    for (int i=1;i<=m;i++) {

        f >> nod1 >> nod2;

        adiac[nod1].push_back(nod2);

        adiactrans[nod2].push_back(nod1);

    }

    for (int i=1;i<=n;i++) {

        if (viz[i]==0) {

            dfs(i);

        }

    }

    while (st.empty()==0) {

        if (viz[st.top()]==1) {

            conex++;

            dfs_t(st.top());

        }

        st.pop();

    }

    g << conex << '\n';

    for (int i=1;i<=conex;i++) {

        for (auto k=compconex[i].begin(); k!=compconex[i].end(); ++k) {

            g << *k <<" ";

        }

        g << '\n';

    }

    return 0;

}
