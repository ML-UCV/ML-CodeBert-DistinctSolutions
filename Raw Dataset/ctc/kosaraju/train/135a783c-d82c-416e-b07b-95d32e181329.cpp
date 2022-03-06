#include <fstream>
#include <vector>
#include <unordered_set>
#include <stack>



using namespace std;

vector<int> G[100001], GT[100001];
unordered_set<int> viz;
stack<int> st;
vector<vector<int>> result;

int n, m;

void DFS(int nod)
{
    viz.insert(nod);

    for (const int& vec : G[nod])
        if (viz.find(vec) == viz.end())
            DFS(vec);

    st.push(nod);
}

void DFST(int nod, vector<int>& v)
{
    viz.insert(nod);

    v.push_back(nod);

    for (const int& vec : GT[nod])
        if (viz.find(vec) == viz.end())
            DFST(vec, v);
}


int main(int argc, const char * argv[]) {

    ifstream fin("ctc.in");
    fin >> n >> m;
    int x, y;

    for (int i = 0; i < m; ++i)
    {
        fin >> x >> y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }

    fin.close();

    for (int nod = 1; nod <= n; ++nod)
        if (viz.find(nod) == viz.end())
            DFS(nod);

    viz.clear();

    for (; !st.empty(); )
    {
        int nod = st.top();
        st.pop();

        if (viz.find(nod) != viz.end())
            continue;

        vector<int> v;

        DFST(nod, v);

        result.push_back(v);
    }

    ofstream fout("ctc.out");

    fout << result.size() << '\n';

    for (int i = 0; i < result.size(); ++i)
    {
        for (const int& nod : result[i])
            fout << nod << ' ';
        fout << '\n';
    }

    fout.close();

    return 0;
}
