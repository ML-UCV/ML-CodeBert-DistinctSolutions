#include <bits/stdc++.h>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

pair <int, pair <int, int> > input[400005];

int root[400005];



int top(int a) {

    if (root[a] == a)

        return a;

    return root[a] = top(root[a]);

}



bool comp(pair <int, pair <int, int> > a, pair <int, pair <int, int> > b) {

    return a.second.second < b.second.second;

}



void connect(int a, int b) {

    if (root[a] == a)

        return;

    connect(root[a], b);

    root[a] = b;

}



int main() {

    int n, m;



    fin >> n >> m;

    for (int i = 1; i <= m; i++)

        fin >> input[i].first >> input[i].second.first >> input[i].second.second;



    for (int i = 1; i <= n; i++)

        root[i] = i;



    sort(input + 1, input + m + 1, comp);



    long long result = 0;

    vector <pair <int, int> > edges;

    for (int i = 1; i <= m; i++)

        if (root[top(input[i].first)] != root[top(input[i].second.first)]) {

            result += input[i].second.second;



            root[top(input[i].second.first)] = top(input[i].first);

            edges.push_back(make_pair(input[i].first, input[i].second.first));

        }





    fout << result << '\n' << edges.size() << '\n';

    for (pair <int, int> edge : edges)

        fout << edge.first << ' ' << edge.second << '\n';



    return 0;

}
