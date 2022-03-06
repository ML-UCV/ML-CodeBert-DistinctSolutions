#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

vector <int > nodes[100005];

vector <int > nodes2[100005];

vector <int > ctc[100005];

stack < int > st;

int viz[100005], n, m;

void dfs(int node){

    viz[node] = 1;

    for (auto &it : nodes[node]) {

        if(viz[it] != 1){

            dfs(it);

        }

    }

    st.push(node);

}

void dfst(int node,int nr){

    viz[node] = 2;

    ctc[nr].push_back(node);

    for (auto &it : nodes2[node]) {

        if(viz[it]!= 2){

            dfst(it,nr);

        }

    }



}

int main()

{

     fin >> n >> m;

    for (int i = 0; i < m; ++i) {

        int x, y;

        fin >> x >> y;

        nodes[x].push_back(y);

        nodes2[y].push_back(x);

    }

    for (int i = 1; i <= n; ++i) {

        if(!viz[i]){

            dfs(i);

        }

    }

    int nr = 0;

    while(!st.empty())

    {

        int top = st.top();

        st.pop();

        if(viz[top] != 2)

        {

            nr++;

            dfst(top,nr);

        }

    }

    fout << nr << "\n";

    for(int i = 1; i <= nr; i++)

    {

         for(auto &v : ctc[i])

        fout << v << " ";

        fout << "\n";

    }







    return 0;

}
