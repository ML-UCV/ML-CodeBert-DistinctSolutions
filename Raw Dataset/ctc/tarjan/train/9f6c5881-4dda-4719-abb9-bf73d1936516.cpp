#include <fstream>
#include <vector>
#include <stack>

const int NMAX = 1e5 + 1;

std :: ifstream in ("ctc.in");
std :: ofstream out("ctc.out");

std :: vector<int> graf[NMAX];
std :: vector<std :: vector<int>> sol;
std :: stack<int> stk;

int low[NMAX], id[NMAX];
bool inStack[NMAX];

int n, m, a, b;
int idc = 0;

void DFS (int);

int main()
{

    in >> n >> m;
    for( int i = 0; i < m; i++ ){
        in>>a>>b;
        graf[a-1].emplace_back(b-1);
    }

    for(int i = 0; i < n; i++ )
    {
        low[i] = 0;
        id[i] = -1;
        inStack[i] = 0;
    }

    for(int i = 0; i < n; i++)
        if ( id[i] == -1)
            DFS(i);


    out << sol.size() << "\n";
    for (auto list : sol){
        for (int elem : list)
            out << elem + 1 << " ";
        out << "\n";
    }
    return 0;
}

void DFS(int x)
{
    id[x] = low[x] = idc;
    idc += 1;
    stk.push(x);
    inStack[x] = 1;

    for (int elem : graf[x]){
        if(id[elem] == -1)
            DFS(elem);
        if(inStack[elem])
            low[x] = std :: min (low[x], low[elem]);
    }
    if(id[x] == low[x]){
        std :: vector<int> aux;

        while (stk.top() != x){
            aux.push_back( stk.top() );
            low[ stk.top() ] = id[x];
            inStack[ stk.top() ] = 0;
            stk.pop();
        }

        aux.push_back( stk.top() );
        low[ stk.top() ] = id[x];
        inStack[ stk.top() ] = 0;
        stk.pop();

        sol.push_back(aux);
    }

}
