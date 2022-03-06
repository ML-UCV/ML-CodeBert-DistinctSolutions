#include <fstream>
#include <vector>
#include <queue>
#define N 30002

using namespace std;

int n, m, x, y, d[N];
bool ok;
vector<pair<int,int>>A[N];

void df(int nod)
{
    if(nod==y)
        ok=1;

    if(!ok)
    {
        for(auto i:A[nod])
        {
            if(!d[i.first])
            {
                d[i.first]=d[nod]+i.second;
                df(i.first);
            }
        }
    }
}

int main()
{
    //freopen("sate.in", "r", stdin);
    //freopen("sate.out", "w", stdout);
    ifstream fin("sate.in");
    ofstream fout("sate.out");
    //scanf("%d %d %d %d", &n, &m, &x, &y);
    fin>>n>>m>>x>>y;
    for(int i=1; i<=m; i++)
    {
        int n1,n2,n3;
        //scanf("%d %d %d", &n1, &n2, &n3);
        fin>>n1>>n2>>n3;
        A[n1].push_back({n2,n3});
        A[n2].push_back({n1,-n3});
    }
    d[x]=1;
    df(x);
    //printf("%d\n",d[y]-1);
    fout<<d[y]-1;
    return 0;
}
