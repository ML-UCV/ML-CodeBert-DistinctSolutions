#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, d;
vector <pair <int, int> > v[30005];
bool f[30005], viz[30005];
queue <pair <int, int> > q;
inline int bfs(int nod){
//    if(nod == d) return cost;
//    for(vector <pair <int, int> > :: iterator it = v[nod].begin() ; it != v[nod].end() ; ++it){
//        if(viz[it->first]) continue ;
//        if(it->first > nod){
//            viz[it->first] = 1;
//            int k = bfs(it->first, cost + it->second);
//            viz[it->first] = 0;
//            if(k == -1) continue ;
//            return k;
//        }
//        else{
//            viz[it->first] = 1;
//            int k = bfs(it->first, cost - it->second);
//            viz[it->first] = 0;
//            if(k == -1) continue ;
//            return k;
//        }
//    }
    q.push(make_pair(nod, 0));
    while(!q.empty()){
        int nod = q.front().first, cost = q.front().second;
        q.pop();
        if(nod == d) return cost;
        for(vector <pair <int, int> > :: iterator it = v[nod].begin() ; it != v[nod].end() ; ++it){
            if(viz[it->first]) continue ;
            if(it->first > nod){
                viz[it->first] = 1;
                q.push(make_pair(it->first, cost + it->second));
            }
            else{
                viz[it->first] = 1;
                q.push(make_pair(it->first, cost - it->second));
            }
        }
    }
    return -1;
}
int main()
{
    freopen("sate.in", "r", stdin);
    freopen("sate.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &x, &y);
    int a, b, dist;
    for(int i = 1; i <= m ; ++i){
        scanf("%d%d%d", &a, &b, &dist);
        v[a].push_back(make_pair(b, dist));
        v[b].push_back(make_pair(a, dist));
        f[a] = f[b] = 1;
    }
    for(int i = 1; i <= n ; ++i){
        if(!f[i]) continue ;
        d = x;
        viz[i] = 1;
        a = bfs(i);
        d = y;
        memset(viz, 0, sizeof(viz));
        viz[i] = 1;
        b = bfs(i);
        if(a == -1 || b == -1) continue ;
        printf("%d", b - a); return 0;
    }
    return 0;
}

