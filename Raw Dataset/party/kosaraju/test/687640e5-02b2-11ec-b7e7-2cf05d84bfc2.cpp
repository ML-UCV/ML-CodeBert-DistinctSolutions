#include <algorithm>
#include <bitset>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 105;

vector<int> G[2 * Nmax], Gt[2 * Nmax];
bitset<2 * Nmax> V;
int SortedNodes[2 * Nmax], Cc[2 * Nmax];

int N, P, Ncc;

inline int Non(const int x)
{
    return (x > N ? x - N: x + N);
}

void Dfs(const int node)
{
    V[node] = 1;
    for (const int next: G[node])
        if (!V[next])
            Dfs(next);

    SortedNodes[++P] = node;
}

void Dfs1(const int node)
{
    Cc[node] = Ncc;
    for (const int next: Gt[node])
        if (!Cc[next])
            Dfs1(next);
}

int main()
{
    freopen("party.in", "r", stdin);
    freopen("party.out", "w", stdout);

    int M;
    scanf("%d%d", &N, &M);

    while (M--)
    {
        int x, y, op;
        scanf("%d%d%d", &x, &y, &op);

        if (op == 1) y = Non(y);
        else if (op == 2) x = Non(x);
        else if (op == 3)
        {
            x = Non(x);
            y = Non(y);
        }

        G[Non(x)].push_back(y);
        G[Non(y)].push_back(x);
        Gt[x].push_back(Non(y));
        Gt[y].push_back(Non(x));
    }

    for (int i = 1; i <= 2 * N; i++)
        if (!V[i])
            Dfs(i);

    for (int i = 2 * N; i; i--)
    {
        const int node = SortedNodes[i];

        if (!Cc[node])
        {
            Ncc++;
            Dfs1(node);
        }
    }

    vector<int> Ans;
    for (int i = 1; i <= N; i++)
        if (Cc[i] > Cc[Non(i)])
            Ans.push_back(i);

    printf("%u\n", Ans.size());
    for (const int p: Ans) printf("%d\n", p);
}
