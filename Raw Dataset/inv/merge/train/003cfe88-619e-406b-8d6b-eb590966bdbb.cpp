#include <fstream>
#include <iostream>

using namespace std;

const int N=100001;
const int M=9917;
int aux[N], v[N];

ifstream in("inv.in");
ofstream out("inv.out");

int merge_v(int v[], int st, int dr){
    int m=(st+dr)/2;
    int i, j, k, r=0;
    i=k=st;
    j=m+1;
    while(i<=m && j<=dr){
        if(v[i]<=v[j]){
            aux[k++]=v[i++];
        } else {
            aux[k++]=v[j++];
            r+=m-i+1;
            r%=M;
        }
    }
    while(i<=m){
        aux[k++]=v[i++];
    }
    while(j<=dr){
        aux[k++]=v[j++];
    }
    for(k=st; k<=dr; k++){
        v[k]=aux[k];
    }
    return r;
}

int ms(int v[], int st, int dr){
    int r=0;
    if(st==dr){
        return 0;
    }
    int m=(st+dr)/2;
    r+=ms(v, st, m);
    r%=M;
    r+=ms(v, m+1, dr);
    r%=M;
    r+=merge_v(v, st, dr);
    r%=M;
    return r;
}

int main(){
    int n;
    in>>n;
    for(int i=1; i<=n; i++){
        in>>v[i];
    }
    out<<ms(v, 1, n);
    return 0;
}
