#include<cassert>
#include<fstream>
#include<vector>

using namespace std;

int n;

int no(int x){
  if(x <= n)
    return x + n;
  return x - n;
}

vector<int> graph[205], gt[205];

void implying(int x, int y){
  graph[x].push_back(y);
  gt[y].push_back(x);
}

vector<int> st;
int vis[205];

void dfs1(int x){
  vis[x] = 1;
  for(int i = 0; i < graph[x].size(); ++i)
    if(!vis[graph[x][i]])
      dfs1(graph[x][i]);
  st.push_back(x);
}

int impossible, vis2[205], val[205];

void dfs2(int x){
  if(val[x])
    impossible = 1;
  val[no(x)] = 1;
  vis2[x] = 1;
  for(int i = 0; i < gt[x].size(); ++i)
    if(!vis2[gt[x][i]])
      dfs2(gt[x][i]);
}

int main(){
  ifstream in("party.in");
  ofstream out("party.out");

  int m;
  in >> n >> m;

  for(int i = 1; i <= m; ++i){
    int x, y, tip;
    in >> x;
    in >> y;
    in >> tip;
    if(tip == 0){
      implying(no(x), y);
      implying(no(y), x);
    }
    else if(tip == 1){
      implying(no(x), no(y));
      implying(y, x);
    }
    else if(tip == 2){
      implying(no(y), no(x));
      implying(x, y);
    }
    else{
      implying(x, no(y));
      implying(y, no(x));
    }
  }

  for(int i = 1; i <= n * 2; ++i)
    if(!vis[i])
      dfs1(i);

  for(int i = n * 2 - 1; i >= 0; --i)
    if(!vis2[st[i]] && !vis2[no(st[i])])
      dfs2(st[i]);

  int ans = 0;

  for(int i = 1; i <= n; ++i)
    if(val[i])
      ++ans;

  assert(ans != 0);

  out << ans << "\n";

  for(int i = 1; i <= n; ++i)
    if(val[i])
      out << i << "\n";

  return 0;
}
