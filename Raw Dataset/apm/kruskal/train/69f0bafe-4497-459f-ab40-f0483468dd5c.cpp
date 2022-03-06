#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>






using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct Edge {

    int src, dest, weight;

};



int n, m;

Edge graph[400010];

int reps[400010];

vector<int> sol;

int sizes[400010];



int findRep(int x) {

    if(x != reps[x])

        reps[x] = findRep(reps[x]);

    return reps[x];

}



void unite(int x, int y) {

    int smaller = findRep(x);

    int larger = findRep(y);



    if(smaller == larger) {

        return;

    }



    if(sizes[smaller] > sizes[larger]) {

        swap(smaller, larger);

    }



    reps[smaller] = larger;

    sizes[larger] += sizes[smaller];

}



int main() {

    int totalWeight = 0;



    fin >> n >> m;

    for(int i = 1; i <= m; i++) {

        int x, y, weight;

        fin >> x >> y >> weight;

        graph[i] = {x, y, weight};

    }



    for(int i = 1; i <= n; i++) {

        reps[i] = i;

        sizes[i] = 1;

    }



    sort(graph + 1, graph + m + 1, [](Edge a, Edge b) { return a.weight < b.weight; });



    for(int i = 1; i <= m && sol.size() < n - 1; i++) {

        if(findRep(graph[i].src) != findRep(graph[i].dest)) {

            unite(graph[i].src, graph[i].dest);

            totalWeight += graph[i].weight;

            sol.push_back(i);

        }

    }



    fout << totalWeight << '\n' << sol.size() << '\n';

    for(auto vertex : sol) {

        fout << graph[vertex].dest << ' ' << graph[vertex].src << '\n';

    }

}
