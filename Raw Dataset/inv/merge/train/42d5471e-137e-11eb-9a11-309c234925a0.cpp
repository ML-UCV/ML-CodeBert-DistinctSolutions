#include <fstream>

using namespace std;

ifstream in("inv.in");
ofstream out("inv.out");

int aux[100000];

long long merge_v(int v[], int st, int dr){
    int m=(st+dr)/2, i, j, k;
    long long r=0;
    i=k=st;
    j=m+1;
    while(i<=m && j<=dr){
        if(v[i]<=v[j]){
            aux[k++]=v[i++];
        }else{
            aux[k++]=v[j++];
            r+=m-i+1;
        }
    }
    while(i<=m){ aux[k++]=v[i++]; }
    while(j<=dr){ aux[k++]=v[j++]; }
    for(k=st; k<=dr; k++){
        v[k]=aux[k];
    }
    return r;
}

long long ms(int v[], int st, int dr){
    long long r=0;
    if(st==dr){
        return 0;
    }
    int m=(st+dr)/2;
    r+=ms(v, st, m);
    r+=ms(v, m+1, dr);
    r+=merge_v(v, st, dr);
    return r;
}

int main()
{
    int v[100000], n;
    in>>n;
    for(int i=0; i<n; i++){
        in>>v[i];
    }
    out<<ms(v, 0, n-1)%9917;
    return 0;
}
