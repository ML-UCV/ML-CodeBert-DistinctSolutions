#include <fstream>

using namespace std;

ifstream fin ("sate.in");
ofstream fout ("sate.out");

const int N=100002;
const int M=1000002;
int nr,lst[N+1],urm[2*M+1],vf[2*M+1],q[N+1],n,m, s=0, drum[2*M+1], g1, g2, dp[N+1];
bool viz[N+1];

void adauga (int x, int y, int km)
{
    vf[++nr]=y;
    drum[nr]=km;
    urm[nr]=lst[x];
    lst[x]=nr;
}
void bfs (int xx)
{
    int x;
    int st,dr;
    st=0;
    dr=-1;
    q[++dr]=xx;
    while (st<=dr)
    {
        x=q[st++];
        viz[x]=true;
        if(x!=g2)
            for (int p=lst[x]; p!=0; p=urm[p])
            {
                int y=vf[p];
                if (!viz[y])
                {
                    q[++dr]=y;
                    dp[y]=dp[x]+drum[p];
                    viz[y]=true;
                }
            }
    }
}

int main()
{
    int x,y, km;
    fin>>n>>m>>g1>>g2;
    for(int i=1; i<=m; i++)
    {
        fin>>x>>y>>km;
        if(x>y)
            swap(x,y);
        adauga(x, y, km);
        adauga(y, x, -km);
    }
    bfs(g1);
    fout<<dp[g2];
    return 0;
}
