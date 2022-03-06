#include <bits/stdc++.h>


using namespace std;



ifstream fin ("ctc.in");

ofstream fout ("ctc.out");



const int DIM = 100000 + 5;



vector < int > a[DIM];

vector < vector < int > > sol;

stack < int > st;



int disc[DIM], low[DIM], temp;

bool in_stack[DIM];



void dfs(int k)

{

    disc[k] = low[k] = ++temp;

    st.push(k);

    in_stack[k] = true;

    for(auto v : a[k]) {

        if(disc[v] == 0) {

            dfs(v);

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

    int n, m;



    fin >> n >> m;

    for(int i = 1; i <= m; ++i) {

        int x, y;



        fin >> x >> y;

        a[x].push_back(y);

    }

    for(int i = 1; i <= n; ++i) {

        if(disc[i] == false) dfs(i);

    }

    fout << sol.size() << "\n";

    for(auto v : sol) {

        for(auto w : v) {

            fout << w << " ";

        }

        fout << "\n";

    }

    return 0;

}
