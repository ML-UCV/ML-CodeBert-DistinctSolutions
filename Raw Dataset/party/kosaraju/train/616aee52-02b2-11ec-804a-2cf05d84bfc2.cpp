#include <cstdio>




int q, val[2*1000 +1], next[2*1000 +1], e[2*1000 +1], urm[2*1000 +1];

int u, n, k, sol[200 +1], list[200 +1], lista[200 +1], v[200 +1];

bool viz[200 +1], ans[200 +1];

inline int non(int x){

    if(x<=n)return x+n;

    return x-n;

}

inline void add(int x, int y){

    q++;

    e[q]=y;

    urm[q]=list[x];

    list[x]=q;

}

inline void adauga(int x, int y){

    add(y, x);

    k++;

    val[k]=y;

    next[k]=lista[x];

    lista[x]=k;

}

inline void sau(int x, int y){

    adauga(non(x), y);

    adauga(non(y), x);

}

void dfs1(int x){

    int p=lista[x];

    viz[x]=1;

    while(p){

        if(viz[val[p]]==0){

            dfs1(val[p]);

        }

        p=next[p];

    }

    v[++u]=x;

}

void dfs2(int x){

    int p=list[x];

    ans[non(x)]=1;

    viz[x]=0;

    while(p){

        if(viz[e[p]]){

            dfs2(e[p]);

        }

        p=urm[p];

    }

}

int main(){

    int m, x, y, z, i;

    FILE *fin, *fout;

    fin=fopen("party.in", "r");

    fout=fopen("party.out", "w");

    fscanf(fin, "%d%d", &n, &m);

    for(i=0; i<m; i++){

        fscanf(fin, "%d%d%d", &x, &y, &z);

        if(z==0){

            sau(x, y);

        }else if(z==1){

            sau(x, non(y));

        }else if(z==2){

            sau(y, non(x));

        }else{

            sau(non(x), non(y));

        }

    }

    for(i=1; i<=2*n; i++){

        if(viz[i]==0){

            dfs1(i);

        }

    }

    for(i=u; i>0; i--){

        if((viz[v[i]])&&(viz[non(v[i])])){

            dfs2(v[i]);

        }

    }

    for(i=1; i<=n; i++){

        if(ans[i]){

            sol[++sol[0]]=i;

        }

    }

    for(i=0; i<=sol[0]; i++){

        fprintf(fout, "%d\n", sol[i]);

    }

    fclose(fin);

    fclose(fout);

    return 0;

}
