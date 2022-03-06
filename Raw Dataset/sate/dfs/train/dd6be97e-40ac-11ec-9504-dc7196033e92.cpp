#include <cstdio>
#include <fstream>

using namespace std;

struct Nod	{
	int et, cost;
	Nod *adr;
} *L[30005];

int n, m, X, Y, x, y, c;
int marcat[30005];

const int Lim = 10000000;
int u =  Lim - 1;
char s[Lim];

void Next () {
	if (++u == Lim)
		fread(s, 1, Lim, stdin), u = 0;
}

void Get (int &x)  {
	for (; s[u] < '0' || s[u] > '9'; Next());
	for (x = 0; s[u] >= '0' && s[u] <= '9'; Next())
		x = x * 10 + s[u] - '0';
}

void dfs(int nod)	 {
	for (Nod *a = L[nod]; a != NULL; a = a -> adr)	{
		if (marcat[a -> et] || a -> et == X)
			continue;
		marcat[a -> et] = marcat[nod] + a -> cost;
		dfs(a -> et);
		if (a -> et == Y)	 {
			printf("%d", marcat[a -> et]);
			exit(0);
		}
	}
}

int main()	{
	freopen("sate.in", "r", stdin);
	freopen("sate.out", "w", stdout);
	Get(n); Get(m); Get(X); Get(Y);
	for (int i = 1; i <= m; ++i)	{
		Get(x); Get(y); Get(c);
		Nod *p = new Nod;
		p -> et = y;
		p -> cost = c;
		p -> adr = L[x];
		L[x] = p;
		p = new Nod;
		p -> et = x;
		p -> cost = - c;
		p -> adr = L[y];
		L[y] = p;
	}
	dfs(X);
	return 0;
}
