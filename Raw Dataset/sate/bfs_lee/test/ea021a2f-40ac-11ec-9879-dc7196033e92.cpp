#include <fstream>
#include <vector>
using namespace std;
int n, m, x, y, i, j, a, b, d, l[30001], numar;
bool exp[30001];
vector < pair <int, int> > adj[30001];
int q[30001], cnt;
char sir[1005];
ifstream fin ("sate.in");
ofstream fout ("sate.out");

void BFS (int s)
{
    int x=0, st=1, dr=0;
    l[s]=0;
    exp[s]=1;
    q[++dr]=s;
    while (st<=dr && l[y]==0) {
        x=q[st];
        st++;
        for (int i=0;i<adj[x].size();i++) {
            if (!exp[adj[x][i].first]) {
                exp[adj[x][i].first]=1;
                l[adj[x][i].first]=l[x]+adj[x][i].second;
                q[++dr]=adj[x][i].first;
            }
        }
    }
}

int main () {
    fin>>n>>m>>x>>y;
    fin.get();
    for (i=1;i<=m;i++) {
        cnt=0;
        fin.getline(sir, 1001);
        for (j=0;sir[j]!=0;j++) {
            if (sir[j]>='0' && sir[j]<='9') {
                numar=0;
                cnt++;
                while (sir[j]>='0' && sir[j]<='9') {
                    numar=numar*10+sir[j]-'0';
                    j++;
                }
                if (cnt==1) {
                    a=numar;
                } else if (cnt==2)
                    b=numar;
                else if (cnt==3)
                    d=numar;
            }
        }
        adj[a].push_back({b, d});
        adj[b].push_back({a,-d});
    }

    BFS(x);
    fout<<l[y];
    return 0;
}
