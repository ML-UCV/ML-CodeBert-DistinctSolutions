#include<bits/stdc++.h>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int a, b, s[30001], x[100001], y[100001], c[100001], n, m;

int main(){
    int i;
    fin>>n>>m>>a>>b;
    s[a]=1;
    for (i=1;i<=m;i++)
        fin>>x[i]>>y[i]>>c[i];
    while(!s[b]){
        for (int i=1; i<=m; i++){
            if (s[x[i]] && !s[y[i]])
                s[y[i]]=s[x[i]]+c[i];
            else if (!s[x[i]] && s[y[i]])
                s[x[i]]=s[y[i]]-c[i];}
    }
    fout<<s[b]-1;
    return 0;
}
