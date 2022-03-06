#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>






using namespace std;



int answers[300001];

int level[250002];

int n, m;





struct Query

{

    int degree;

    int ord;



    Query(int _deg, int _ord) : degree(_deg), ord(_ord) {}

};



struct Node

{

    vector<Query> queries;

    vector<int> descendants;

} nodes[250002];



void read()

{

    scanf("%d", &n);

    scanf("%d", &m);

    for(int i = 1; i <= n; ++i)

    {

        int parent;

        scanf("%d", &parent);

        nodes[parent].descendants.push_back(i);

    }



    for(int i = 0; i < m; ++i)

    {

        int p, q;



        scanf("%d", &q);

        scanf("%d", &p);



        nodes[q].queries.push_back(Query(p, i));

    }

}



void solve(int node, int depth)

{

    level[depth] = node;



    Node & currentNode = nodes[node];

    for(int i = 0; i < currentNode.queries.size(); ++i)

    {

        Query & currentQuery = currentNode.queries[i];

        answers[currentQuery.ord] = level[max(depth - currentQuery.degree, 0)];

    }



    for(int i = 0; i < currentNode.descendants.size(); ++i)

    {

        solve(currentNode.descendants[i], depth + 1);

    }

}



void printAnswers()

{

    for(int i = 0; i < m; ++i)

        printf("%d\n", answers[i]);

}



int main() {

    freopen("stramosi.in", "r", stdin);

    freopen("stramosi.out", "w", stdout);



    read();

    solve(0, 0);

    printAnswers();



    return 0;

}
