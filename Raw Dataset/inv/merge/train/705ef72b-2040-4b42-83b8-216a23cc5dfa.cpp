#include <iostream>
#include <fstream>




using namespace std;

ifstream f("inv.in");
ofstream g("inv.out");

int n,sir[100000 +5],aux[100000 +5],rez;

void mergesort(int l,int r){
    if(l>=r){
        return;
    }
    int i,j,m=(l+r)/2,k=l;
    mergesort(l,m);
    mergesort(m+1,r);
    i=l;
    j=m+1;
    while(i<=m&&j<=r){
        if(sir[i]<=sir[j]){
            aux[k++]=sir[i++];
        }else{
            rez=(rez+m-i+1+9917)%9917;
            aux[k++]=sir[j++];
        }
    }
    while(i<=m){
        aux[k++]=sir[i++];
    }
    while(j<=r){
        aux[k++]=sir[j++];
    }
    for(int i=l;i<=r;i++){
        sir[i]=aux[i];
    }
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    mergesort(1,n);
    g<<rez;
    f.close();
    g.close();
}
