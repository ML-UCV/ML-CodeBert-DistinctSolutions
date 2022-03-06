#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream f("ctc.in");
ofstream g("ctc.out");
vector<int>gf[100005],gft[100005],sol[100005];
stack<int>st;
int n,m,x,y,cnt;
bool use[100005];
void dfs(int nod)
{
    use[nod]=1;
    int lg=gf[nod].size();
    for(int i=0;i<lg;i++)
    {
        int vec=gf[nod][i];
        if(!use[vec])
            dfs(vec);
    }
    st.push(nod);
}
void dfst(int nod)
{
    use[nod]=0;
    sol[cnt].push_back(nod);
    int lg=gft[nod].size();
    for(int i=0;i<lg;i++)
    {
        int vec=gft[nod][i];
        if(use[vec])
            dfst(vec);
    }
}
int main() {
    f>>n>>m;
    for(int i=1;i<=m;i++)
    {
        f>>x>>y;
        gf[x].push_back(y);
        gft[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
       if(use[i]==0)dfs(i);
    while(!st.empty())
    {
        int nod=st.top();
        st.pop();
        if(use[nod])
        {
        cnt++;
        dfst(nod);
        }
    }
    g<<cnt<<'\n';
    for(int i=1;i<=cnt;i++)
    {
        int lg=sol[i].size();
        for(int j=0;j<lg;j++)g<<sol[i][j]<<" ";
        g<<'\n';
    }
    return 0;
}
