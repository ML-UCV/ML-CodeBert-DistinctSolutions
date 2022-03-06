#include <bits/stdc++.h>


using namespace std;



struct node {

    bool b, b2;

    vector<int> in;

    vector<int> out;

};

vector<node> g;

vector<vector<int>> v;

stack<int> s;



void d1(int n) {

    g[n].b=true;

    for(auto it:g[n].out)

        if(!g[it].b)

            d1(it);

    s.push(n);

}



void d2(int n) {

    v.back().push_back(n);

    g[n].b2=1;

    for(auto i:g[n].in)

        if(!g[i].b2)

            d2(i);

}



int main() {

    ifstream fin("ctc.in");

    ofstream fout("ctc.out");

    int n, m;

    fin>>n>>m;

    g.resize(n+1);

    for(; m; m--) {

        int a, b;

        fin>>a>>b;

        g[a].out.push_back(b);

        g[b].in.push_back(a);

    }

    for(m=1; m<=n; m++)

        if(!g[m].b)

            d1(m);

    while(true) {

        v.push_back({});

        while(!s.empty() && g[s.top()].b2)

            s.pop();

        if(s.empty())

            break;

        d2(s.top());

    }

    fout<<v.size()-1<<"\n";

    for(auto i:v) {

        for(auto j:i)

            fout<<j<<" ";

        fout<<"\n";

    }

    return 0;

}
