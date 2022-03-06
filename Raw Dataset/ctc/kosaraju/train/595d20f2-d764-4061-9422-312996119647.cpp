#include <iostream>
#include <fstream>
using namespace std;

ifstream in ("ctc.in");
ofstream out ("ctc.out");

const int N = 100000;
const int M = 200000;
int n, m, vf[M], urm[M], lst[N], q[N], vf2[M], urm2[M], lst2[N], st[N], st2[N], nvf[N];
bool viz1[N], viz2[N];
int nc, nr;

void adauga (int a, int b){
    vf[++nr] = b;
    urm[nr] = lst[a];
    lst[a] = nr;
    vf2[nr] = a;
    urm2[nr] = lst2[b];
    lst2[b] = nr;
}

void dfs1(int x){
    viz1[x] = true;
    for(int p = lst[x]; p != 0; p = urm[p]){
        int y = vf[p];
        if(viz1[y] == false){
            dfs1(y);
        }
    }
    st[++nr] = x;
}

void dfs2(int x){
    viz2[x] = true;
    nvf[nc]++;
    st2[++nr] = x;
    for(int p = lst2[x]; p != 0; p = urm2[p]){
        int y = vf2[p];
        if(!viz2[y]){
            dfs2(y);
        }
    }
}


int main()
{
    int x, y;
    in >> n >> m;
    for(int i = 0; i < m; i++){
        in >> x >> y;
        adauga(x, y);
    }
    nr = 0;
    for(int i = 1; i <= n; i++)
    {
        if(viz1[i] == 0)
        {
            dfs1(i);
        }
    }
    nr = 0;
    nc = 0;
    for(int i = n; i >= 1; i--){
        if(viz2[st[i]] == false){
            nc++;
            dfs2(st[i]);
        }
    }
    out << nc << "\n";
    int a = 1;
    for(int i = 1; i <= nc; i++){
        for(int j = 0; j < nvf[i]; j++)
        {
            out << st2[a++] << " ";
            }
            out << "\n";
    }
    return 0;
}
