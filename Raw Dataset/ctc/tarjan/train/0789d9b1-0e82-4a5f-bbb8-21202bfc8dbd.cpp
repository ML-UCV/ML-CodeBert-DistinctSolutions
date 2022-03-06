#include <fstream>
#include <vector>
#include <stack>


using namespace std;

ifstream in ("ctc.in");

ofstream out("ctc.out");



const int MAXN = 100000, MAXM = 200000;

int N, M, sccCount = 0, cnt = 0;

stack <int> st;

bool onSt[MAXN + 1];

int vis[MAXN + 1], low[MAXN + 1];

vector <int> adj[MAXN + 1], con;

vector <vector <int> > C;







void dfs(int curr)

{

    st.push(curr);

    onSt[curr] = true;

    ++cnt;

    vis[curr] = cnt;

    low[curr] = cnt;



    for (int nbh : adj[curr])

    {

        if (vis[nbh] == 0)

            dfs(nbh);

        if (onSt[nbh])

            low[curr] = min(low[nbh], low[curr]);

    }



    if (vis[curr] == low[curr])

    {

        ++sccCount;

        con.clear();

        while(st.top() != curr)

        {

            onSt[st.top()] = false;

            low[st.top()] = vis[curr];

            con.push_back(st.top());

            st.pop();

        }

        onSt[curr] = false;

        low[curr] = vis[curr];

        con.push_back(curr);

        st.pop();

        C.push_back(con);

    }

}



int main()

{

    in >> N >> M;

    int m1, m2;

    for (int i = 0; i < M; ++i)

    {

        in >> m1 >> m2;

        adj[m1].push_back(m2);

    }



    for (int i = 1; i <= N; ++i)

        if (vis[i] == 0)

            dfs(i);

    out << sccCount << "\n";

    for (int i = 0; i < C.size(); ++i)

    {

        for (int j = 0; j < C[i].size(); ++j)

            out << C[i][j]<< " ";

        out << "\n";

    }



    return 0;

}
