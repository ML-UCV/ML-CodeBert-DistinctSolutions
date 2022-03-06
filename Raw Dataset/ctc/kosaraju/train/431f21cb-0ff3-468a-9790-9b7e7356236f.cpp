#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



int n, m, ctc;

stack<int> s;

vector<vector<int>> graph, trans, ans;

bool fr[100100];



void DFS(int node)

{

    fr[node] = true;



    for(int i : graph[node])

        if(fr[i] == false)

            DFS(i);



    s.push(node);

}



void transDFS(int node)

{

    fr[node] = false;

    ans[ctc].push_back(node);



    cout << ctc << ' ' << node << '\n';



    for(int i : trans[node])

        if(fr[i] == true)

            transDFS(i);

}



void kosaraju()

{

    for(int i = 1; i <= n; i++)

        if(fr[i] == false)

            DFS(i);





    ans.resize(n + 5);



    while(!s.empty())

    {





        if(fr[s.top()] == true)

        {

            ctc++;

            transDFS(s.top());

        }



        s.pop();

    }

}



int main()

{

    in >> n >> m;



    graph.resize(n + 5);

    trans.resize(n + 5);



    for(int i = 1; i <= m; i++)

    {

        int x, y;

        in >> x >> y;



        graph[x].push_back(y);

        trans[y].push_back(x);

    }



    kosaraju();



    out << ctc << '\n';



    for(int i = 1; i <= ctc; i++)

    {

        for(int j : ans[i])

            out << j << ' ';



        out << '\n';

    }



    return 0;

}
