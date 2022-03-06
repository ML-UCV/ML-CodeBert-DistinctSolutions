#include <iostream>
#include <cstdio>
using namespace std;
const int mmax = 200000;
const int nmax = 100000;

int nr,ctc,poz,inside;
int lst[nmax], lst_inv[nmax];
int urm[mmax], urm_inv[mmax];
int vf[mmax], vf_inv[mmax];
bool visited[nmax], visited_inv[nmax];
int top[nmax], componenta[nmax], noduri[nmax];

void adauga(int x, int y){
    nr++;
    vf[nr] = y;
    urm[nr] = lst[x];
    lst[x] = nr;

    vf_inv[nr] = x;
    urm_inv[nr] = lst_inv[y];
    lst_inv[y] = nr;
}

void dfs(int node){
    visited[node] = true;
    for(int p=lst[node]; p!=0; p=urm[p]){
        int next = vf[p];
        if(!visited[next])
            dfs(next);
    }
    top[++nr] = node;
}

void dfs_inv(int node){
    visited_inv[node] = true;
    for(int p=lst_inv[node]; p!=0; p=urm_inv[p]){
        int next = vf_inv[p];
        if(!visited_inv[next])
            dfs_inv(next);
    }
    componenta[++poz] = node;
    inside++;
}

int main()
{
    FILE *fin, *fout;
    int n,m,i,x,y;
    fin = fopen("ctc.in","r");
    fout = fopen("ctc.out","w");
    fscanf(fin,"%d %d",&n,&m);
    for(i=0; i<m; i++){
        fscanf(fin,"%d %d",&x,&y);
        adauga(x,y);
    }
    nr = 0;
    for(i=1; i<=n; i++)
        if(!visited[i])
            dfs(i);
    ctc = poz = 0;
    for(i=nr; i>0; i--)
        if(!visited_inv[top[i]]){
            inside = 0;
            ctc++;
            dfs_inv(top[i]);
            noduri[ctc] = inside;
        }
    fprintf(fout,"%d\n",ctc);
    int j=1;
    for(i=1; i<=poz; i++){
        if(noduri[j] == 0){
            j++;
            fprintf(fout,"\n");
        }
        fprintf(fout,"%d ",componenta[i]);
        noduri[j]--;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
