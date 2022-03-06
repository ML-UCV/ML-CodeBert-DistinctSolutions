#include <bits/stdc++.h>






using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct edge

{

    int x, y, c;

};

vector <edge> E;

vector <edge> S;



int T[200002];

int L[200002];

int N, M;

int i;



int find(int node)

{

    if(node == T[node])

        return node;

    return T[node] = find(T[node]);

}



void unite(int a, int b)

{

    a = find(a);

    b = find(b);

    if(L[a] < L[b])

        swap(a, b);

    L[a] += L[b];

    T[b] = a;

}



bool qx(edge a, edge b)

{

    return a.c < b.c;

}



int main()

{

    fin >> N >> M;

    for(i = 1; i <= M; i++)

    {

        int x, y, c;

        fin >> x >> y >> c;

        E.push_back({x, y, c});

    }

    for(i = 1; i <= N; i++)

    {

        T[i] = i;

        L[i] = 1;

    }

    int sol = 0;

    sort(E.begin(), E.end(), qx);

    for(i = 0; i < M; i++)

        if(find(E[i].x) != find(E[i].y))

        {

            sol += E[i].c;

            unite(E[i].x, E[i].y);

            S.push_back(E[i]);

        }

    fout << sol << "\n";

    fout << S.size() << "\n";

    for(i = 0; i < S.size(); i++)

        fout << S[i].x << " " << S[i].y << "\n";

    return 0;

}
