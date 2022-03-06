#include <algorithm>
#include <bitset>
#include <cstdio>
#include <vector>

using namespace std;

const int maxval = 105;

vector<int> G[2 * maxval], Gt[2 * maxval];
bitset<2 * maxval> V;
int graph[2 * maxval], Cc[2 * maxval];

int N, P, Ncc;

inline int Non(const int x)
{
    return (x > N ? x - N: x + N);
}

void DFSSS(const int node)
{
    V[node] = 1;
    for (const int next: G[node])
        if (!V[next])
            DFSSS(next);

    graph[++P] = node;
}

void dfsTRAV(const int node)
{
    Cc[node] = Ncc;
    for (const int next: Gt[node])
        if (!Cc[next])
            dfsTRAV(next);
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
            DFSSS(i);

    for (int i = 2 * N; i; i--)
    {
        const int node = graph[i];

        if (!Cc[node])
        {
            Ncc++;
            dfsTRAV(node);
        }
    }

    vector<int> Ans;
    for (int i = 1; i <= N; i++)
        if (Cc[i] > Cc[Non(i)])
            Ans.push_back(i);

    printf("%u\n", Ans.size());
    for (const int p: Ans) printf("%d\n", p);
}
