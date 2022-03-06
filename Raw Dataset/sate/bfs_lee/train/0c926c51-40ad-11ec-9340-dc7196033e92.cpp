#include <stdio.h>
#include <unistd.h>

#define NMAX 30000
#define MMAX 100024
#define CHUNK (1 << 21)

static struct edge {
    int v;
    int d;
    int next;
} edges[2*MMAX+1];

static int adj_list[NMAX+1], dist[NMAX+1], q[NMAX], visited[NMAX+1];
static char buf[CHUNK];
static size_t bpos;

static inline int read_int(void)
{
    int x = 0;

    while ('0' <= buf[bpos] && buf[bpos] <= '9') {
        x = x * 10 + (buf[bpos] - '0');
        bpos++;
    }

    bpos++;
    return x;
}

int main(void)
{
    int i, n, m, x, y, u, v, s, qt, qh;

    freopen("sate.in", "r", stdin);
    freopen("sate.out", "w", stdout);

    read(STDIN_FILENO, buf, CHUNK);

    n = read_int();
    m = read_int();
    x = read_int();
    y = read_int();

    for (i = 1; i <= m; i++) {
        u = read_int();
        v = read_int();
        s = read_int();

        edges[2*i].v = v;
        edges[2*i].d = s;
        edges[2*i].next = adj_list[u];
        adj_list[u] = 2*i;

        edges[2*i+1].v = u;
        edges[2*i+1].d = s;
        edges[2*i+1].next = adj_list[v];
        adj_list[v] = 2*i+1;
    }

    qh = qt = 0;
    q[qt++] = x;
    visited[x] = 1;

    while (qh < qt) {
        s = q[qh++];
        for (i = adj_list[s]; i != 0; i = edges[i].next) {
            if (!visited[edges[i].v]) {
                visited[edges[i].v] = 1;
                q[qt++] = edges[i].v;
                if (s < edges[i].v) {
                    dist[edges[i].v] = dist[s] + edges[i].d;
                } else {
                    dist[edges[i].v] = dist[s] - edges[i].d;
                }

                if (edges[i].v == y) {
                    printf("%d\n", dist[edges[i].v]);
                    return 0;
                }
            }
        }
    }
}
