#include <bits/stdc++.h>
#include <fstream>


using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



int n , m;



int parent[200005];

int previous[200005];



struct redge

{

    int a , b;

};

vector<redge>rez;



struct edge

{

    int a , b , d;

};



bool xort(edge a , edge b)

{

    if(a.d < b.d)

        return true;

    return false;

}



vector<edge>edges;



int Find(int node)

{

    if(node == parent[node])

        return node;

    return parent[node] = Find(parent[node]);

}



int main()

{

    int a , b , d , price = 0;

    in >> n >> m;

    for(int i = 1; i <= m; ++i)

    {

        in >> a >> b >> d;

        edges.push_back({a , b , d});

    }

    sort(edges.begin(),edges.end(),xort);

    for(int i = 1; i <= n; ++i)

        parent[i] = i;

    for(auto &i : edges)

    {

        if(Find(i.a) != Find(i.b))

        {

            parent[Find(i.b)] = i.a;

            price += i.d;

            rez.push_back({i.a ,i.b});

        }

    }

    out << price << '\n' << n - 1 << '\n';

    for(auto &i : rez)

        out << i.a << " " << i.b << '\n';



}
