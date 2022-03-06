#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;







int N, M;



vector<int> links[100002];

vector<int> tlinks[100002];

stack<int> order;

bool visited[100002];



vector<int> components[100002];

int nr;



void dfs( int node ){

    visited[node] = true;

    for ( auto &x : links[node] ){

        if ( !visited[x] )

            dfs(x);

    }

    order.push(node);

}



void tdfs( int node ){

    components[nr].push_back(node);

    visited[node] = false;

    for ( auto &x : tlinks[node] ){

        if ( visited[x] )

            tdfs(x);

    }

}



int main(){

    ifstream fin("ctc.in");

    ofstream fout("ctc.out");



    fin >> N >> M;



    int a, b;

    for ( int i = 0; i < M; i++ ){

        fin >> a >> b;

        links[a].push_back(b);

        tlinks[b].push_back(a);

    }



    for ( int i = 1; i <= N; i++ ){

        if ( !visited[i] )

            dfs(i);

    }



    while(!order.empty()){

        int x = order.top();



        if ( visited[x] ){

            nr++;

            tdfs(x);

        }



        order.pop();

    }



    fout << nr << '\n';



    for ( int i = 1; i<= nr; i++ ){

        for ( auto &x : components[i] ){

            fout << x << ' ';

        }



        fout << "\n";

    }



}
