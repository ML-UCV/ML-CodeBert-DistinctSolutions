#include <bits/stdc++.h>


using namespace std;



ifstream fin ("ctc.in");

ofstream fout ("ctc.out");



void usain_bolt()

{

    ios::sync_with_stdio(false);

    fin.tie(0);

}



const int N = 1e5 + 5;



vector < int > a[N];

vector < vector < int > > sol;

stack < int > st;



int disc[N], low[N], temp;

bool in_stack[N];



void tarjan(int k)

{

    disc[k] = low[k] = ++temp;

    st.push(k);

    in_stack[k] = true;

    for(auto v : a[k]) {

        if(disc[v] == 0) {

            tarjan(v);

            low[k] = min(low[k], low[v]);

        }

        else if(in_stack[v] == true) low[k] = min(low[k], low[v]);

    }

    if(disc[k] == low[k]) {

        vector < int > add;

        int node = k;

        do {

            node = st.top();

            add.push_back(node);

            in_stack[node] = false;

            st.pop();

        }

        while(node != k);

        sol.push_back(add);

    }

}

int main()

{

    usain_bolt();



    int n, m;



    fin >> n >> m;

    for(int i = 1; i <= m; ++i) {

        int x, y;



        fin >> x >> y;

        a[x].push_back(y);

    }

    for(int i = 1; i <= n; ++i)

        if(disc[i] == 0) tarjan(i);

    fout << sol.size() << "\n";

    for(auto x : sol) {

        for(auto y : x) {

            fout << y << " ";

        }

        fout << "\n";

    }

    return 0;

}
