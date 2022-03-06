#include <iostream>
#include <cstdio>
using namespace std;
const int NMAX = 30000;
const int MMAX = 100024;
int last[NMAX+1],d[NMAX+1],urm[2*MMAX+1],vf[2*MMAX+1],dist[2*MMAX+1],nr,n;
int q[NMAX+1];
bool visited[NMAX+1];

void adauga(int x, int y, int l){
    dist[++nr] = l;
    vf[nr] = y;
    urm[nr] = last[x];
    last[x] = nr;
}

void bfs(int x0){
    int st, dr;
    st = 0, dr = -1;
    q[++dr] = x0;
    visited[x0] = true;
    while(st <= dr){
        int nod = q[st++];
        for(int p=last[nod]; p!=0; p=urm[p]){
            int next = vf[p];
            if(!visited[next]){
                visited[next] = true;
                d[next] = d[nod] + dist[p];
                q[++dr] = next;
            }
        }
    }
}

int main()
{
    FILE *fin, *fout;
    int m,first,last,i,x,y,l;
    fin = fopen("sate.in","r");
    fout = fopen("sate.out","w");
    fscanf(fin,"%d %d %d %d",&n,&m,&first,&last);
    for(i=0; i<m; i++){
        fscanf(fin,"%d %d %d",&x,&y,&l);
        adauga(x,y,l);
        adauga(y,x,-l);
    }
    bfs(first);
    fprintf(fout,"%d\n",d[last]);
    fclose(fin);
    fclose(fout);
    return 0;
}
