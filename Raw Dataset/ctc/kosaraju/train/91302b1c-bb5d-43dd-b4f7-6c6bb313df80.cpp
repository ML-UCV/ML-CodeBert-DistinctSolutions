#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream cin("ctc.in");

ofstream cout("ctc.out");



const int NMAX = 1e5;



int N, M;

vector <int> g[NMAX + 2], r[NMAX + 2];



bool vis[NMAX + 2];

stack <int> st;



vector < int > comp;

vector < vector <int> > scc;



void dfs(int node) {

    vis[node] = true;



    for(auto it : g[node])

        if(!vis[it])

            dfs(it);



    st.push(node);

}



void dfs2(int node) {

    comp.push_back(node);

    vis[node] = true;



    for(auto it : r[node])

        if(!vis[it])

            dfs2(it);

}



int main()

{

    cin >> N >> M;



    for(int i = 1; i <= M; i++) {

        int x, y;

        cin >> x >> y;



        g[x].push_back(y);

        r[y].push_back(x);

    }



    for(int i = 1; i <= N; i++)

        if(vis[i] == 0) dfs(i);



    for(int i = 1; i <= N; i++)

        vis[i] = 0;



    while(!st.empty()) {

        int node = st.top();

        st.pop();



        if(!vis[node]) {

            comp.clear();

            dfs2(node);

            scc.push_back(comp);

        }

    }



    cout << (int)scc.size() << '\n';

    for(auto comp : scc)

    {

        for(auto v : comp)

            cout << v << ' ';

        cout << '\n';

    }



    return 0;

}
