#include <bits/stdc++.h>
std::ifstream fin ("party.in");

std::ofstream fout ("party.out");



int guest[105];

bool found_solution = false;



std::vector < std::pair < int, int > > edge[105];

std::vector < std::pair < int, int > > reverse[105];



bool OR (int node1, int node2){

    return guest[node1] | guest[node2];

}



bool result (int node1, int node2){

    if (guest[node1] == 1 and guest[node2] == 0)

        return 0;

    return 1;

}



bool AND (int node1, int node2){

    return guest[node1] & guest[node2];

}



bool verif (int node){

    for (int i=0; i<edge[node].size(); i++){

        int next = edge[node][i].first;

        int type = edge[node][i].second;

        if (guest[next] != -1){

            if (type == 0 and OR (node, next) == 0)

                return false;

            if (type == 2 and result (node, next) == 0)

                return false;

            if (type == 4 and AND (node, next) == 0)

                return false;

        }

    }



    for (int i=0; i<reverse[node].size(); i++){

        int parent = reverse[node][i].first;

        int type = reverse[node][i].second;

        if (guest[parent] != -1){

            if (type == 0 and OR (parent, node) == 0)

                return false;

            if (type == 2 and result (parent, node) == 0)

                return false;

            if (type == 4 and AND (parent, node) == 0)

                return false;

        }

    }

    return true;

}



int DFS (int node){

    guest[node] = 0;

    if (verif (node) == 1){

        bool good = 1;

        for (int i=0; i<edge[node].size(); i++){

            int next = edge[node][i].first;

            int type = edge[node][i].second;

            if (guest[next] == -1){

                good = good & DFS (next);

            }

        }

        if (good == true)

            return good;

    }

    guest[node] = 1;

    if (verif (node) == 1){

        bool good = 1;

        for (int i=0; i<edge[node].size(); i++){

            int next = edge[node][i].first;

            int type = edge[node][i].second;

            if (guest[next] == -1){

                good = good & DFS (next);

            }

        }

        if (good == false)

            guest[node] = -1;

        return good;

    }

    else{

        guest[node] = -1;

        return 0;

    }



}



int main()

{

    int V, E, src, dest, type, i;

    fin >> V >> E;

    for (i=1; i<=E; i++){

        fin >> src >> dest >> type;

        if (type == 1){

            type = 2;

            std::swap (src, dest);

        }

        edge[src].push_back ({dest, type});

        reverse[dest].push_back ({src, type});

    }



    for (i=1; i<=V; i++)

        guest[i] = -1;



    for (i=1; i<=V; i++){

        if (guest[i] == -1){

            DFS (i);



        }

    }



    int ans = 0;

    for (i=1; i<=V; i++){

        if (guest[i] == 1)

            ans ++;

    }

    fout << ans << '\n';

    for (i=1; i<=V; i++)

        if (guest[i] == 1)

        fout << i << '\n';





    return 0;

}
