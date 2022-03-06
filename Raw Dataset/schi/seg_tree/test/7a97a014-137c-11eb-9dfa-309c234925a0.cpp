#include <bits/stdc++.h>

int arb[100000], v[50000], rsp[50000];

int querry(int poz, int x, int put){
    if(poz>=put)
        return poz;
    if(arb[poz*2]>=x)
        return querry(poz*2, x, put);
    return querry(poz*2+1, x-arb[poz*2], put);
}

void update(int poz){
    if(poz!=1){
        arb[poz/2]=arb[poz/2*2]+arb[poz/2*2+1];
        update(poz/2);
    }
}

int main(){
    FILE *fin, *fout;
    int n, i, put, j, var;
    fin=fopen("schi.in", "r");
    fout=fopen("schi.out", "w");
    fscanf(fin, "%d", &n);
    for(i=0;i<n;i++)
        fscanf(fin, "%d", &v[i]);
    put=1;
    while(put*2<n)
        put*=2;
    put*=2;
    for(i=0;i<n;i++){
        arb[put+i]=1;
        update(put+i);
    }
    for(i=n-1;i>=0;i--){
        var=querry(1, v[i], put)-put+1;
        rsp[var]=i+1;
        arb[put+var-1]=0;
        update(put+var-1);
    }
    for(i=1;i<=n;i++)
        fprintf(fout, "%d\n", rsp[i]);
    fclose(fin);
    fclose(fout);

    return 0;
}
