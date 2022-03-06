#include<cstdio>
#include<queue>
#define N_MAX 30005
using namespace std;

int n, m, X, Y, d[N_MAX];
queue<int>Q;
bool used[N_MAX];
struct nod
{
    int val, cost;
    nod *next;
};

nod *L[N_MAX];

inline void add(int x, int y, int c)
{
    nod *elem = new nod;
    elem->val = y;
    elem->cost = c;
    elem->next = L[x];
    L[x] = elem;
}

void BFS(int x)
{
    int Nod;
    nod *p;
    used[x] = 1;
    Q.push(x);
    while(!Q.empty() && !used[Y])
    {
        Nod = Q.front();
        Q.pop();
        p = L[Nod];
        while(p != NULL)
        {
            if(!used[p->val])
            {
                used[p->val] = 1;
                d[p->val] = d[Nod] + p->cost;
                Q.push(p->val);
            }
            p = p->next;
        }
    }
}


int main()
{
    int i, a, b, c;
    FILE *fin, *fout;
    fin = fopen("sate.in","r");
    fout = fopen("sate.out","w");
    fscanf(fin,"%d%d%d%d",&n,&m,&X,&Y);
    for(i=1; i<=m; i++)
    {
        fscanf(fin,"%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,-c);
    }
    fclose(fin);
    BFS(X);
    fprintf(fout,"%d\n",d[Y]);
    fclose(fout);
    return 0;
}
