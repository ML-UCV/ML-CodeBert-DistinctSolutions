#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>






using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");



int findNode(int node, vector<int>& T)

{

    if(node != T[node])

        return T[node] = findNode(T[node], T);



    return node;

}



void uneste(int node1, int node2, vector<int>& T)

{

    int m1 = findNode(node1, T);

    int m2 = findNode(node2, T);



    T[m1] = m2;

}



bool cmp(const pair<pair<int,int>, int> x,const pair<pair<int,int>, int> y)

{

    return x.second < y.second;

}



void kruskal(vector<pair<pair<int,int>, int> >& V, vector<int>& T)

{

    int cost = 0;

    vector<pair<int,int> > sol;



    for(int i = 0; i < V.size(); ++i)

    {

        int x = V[i].first.first;

        int y = V[i].first.second;

        int c = V[i].second;



        if(findNode(x, T) != findNode(y, T))

        {

            uneste(x, y, T);

            cost += c;

            sol.push_back(make_pair(x,y));

        }

    }



    out << cost << '\n';

    out << sol.size() << '\n';

    for(int i = 0; i < sol.size(); ++i)

    {

        out << sol[i].first << " " << sol[i].second << '\n';

    }

}



int main()

{

    int n, m;

    in >> n >> m;



    vector<pair<pair<int,int>, int> > V;

    vector<int> T( n + 2);



    for(int i = 1; i<=n; ++i)

        T[i] = i;



    for(int x, y, cost; m; --m)

    {

        in >> x >> y >> cost;

        V.push_back(make_pair(make_pair(x, y), cost));

    }



    sort(V.begin(), V.end(), cmp);

    kruskal(V, T);

    return 0;

}
