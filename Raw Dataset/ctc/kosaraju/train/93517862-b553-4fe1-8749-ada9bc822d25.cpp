#include <fstream>
#include <vector>
using namespace std;
ifstream cin("ctc.in");
ofstream cout("ctc.out");
const int N = 100005;
int viz[N];
vector <int> L[N], trans[N],postord;
int n ,m,x,y,k;
vector <int> ctc[N];
void dfs(int x)
{
    viz[x] = 1;
    for(int i : L[x])
        if(!viz[i])
            dfs(i);
    postord.push_back(x);
}
void dfs1(int x)
{
    viz[x] = 0;
    for(int i : trans[x])
        if(viz[i])
            dfs1(i);
    ctc[k].push_back(x);
}
int main() {
    cin >> n >>m ;
    for(int i = 1 ;i <=m ;i ++)
    {
        cin >> x >> y;
        L[x].push_back(y);
        trans[y].push_back(x);
    }
    for(int i = 1 ;i <=n; i ++)
    {
        if(!viz[i])
            dfs(i);
    }
    for(int i = postord.size() - 1 ;i >= 0 ;i --)
    {
        if(viz[postord[i]])
            dfs1(postord[i]),k++;
    }
    cout << k<<'\n';
    for(int i = 0 ; i < k ; i ++,cout << '\n')
        for(int j : ctc[i])
            cout << j << " ";
    return 0;
}
