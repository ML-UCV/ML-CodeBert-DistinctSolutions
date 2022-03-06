#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>





using namespace std;

ifstream f("cmap.in");
ofstream g("cmap.out");

int n;
pair <int,int> sir[100000 +5],aux[100000 +5];

long long dist2(int i,int j){
    return (long long)(1LL*(sir[i].first-sir[j].first)*(sir[i].first-sir[j].first)+1LL*(sir[i].second-sir[j].second)*(sir[i].second-sir[j].second));
}

long long minim(long long a,long long b){
    if(a<b){
        return a;
    }
    return b;
}

long long modul(long long a){
    if(a<0){
        return -a;
    }
    return a;
}

long long distanta(int st,int dr){
    if(dr-st+1==3){
        if(sir[dr].second<sir[st].second){
            swap(sir[st],sir[dr]);
        }
        if(sir[dr-1].second<sir[st].second){
            swap(sir[st],sir[dr-1]);
        }
        if(sir[dr].second<sir[dr-1].second){
            swap(sir[dr-1],sir[dr]);
        }
        return minim(dist2(st,st+1),minim(dist2(st+1,dr),dist2(st,dr)));
    }
    if(dr-st+1==2){
        if(sir[dr].second<sir[st].second){
            swap(sir[st],sir[dr]);
        }
        return dist2(st,dr);
    }
    int mij=(st+dr)/2,ii=st,jj=mij+1,ll=st-1;
    long long d1,d2,dmin,dreapta;
    dreapta=sir[mij].first;
    d1=distanta(st,mij);
    d2=distanta(mij+1,dr);
    dmin=minim(d1,d2);


    while(ii<=mij&&jj<=dr){
        if(sir[ii].second<sir[jj].second){
            aux[++ll]=sir[ii++];
        }else{
            aux[++ll]=sir[jj++];
        }
    }
    while(ii<=mij){
        aux[++ll]=sir[ii++];
    }
    while(jj<=dr){
        aux[++ll]=sir[jj++];
    }
    for(int i=st;i<=dr;i++){
        sir[i]=aux[i];
    }
    ll=0;
    for(int i=st;i<=dr;i++){
        if(1LL*modul(sir[i].first-dreapta)*modul(sir[i].first-dreapta)<=1LL*dmin){
            aux[++ll]=sir[i];
        }
    }
    for(int i=1;i<=ll;i++){
        for(int j=i+1;j<=min(i+8,ll);j++){
            d1=(long long)(1LL*(aux[i].first-aux[j].first)*(aux[i].first-aux[j].first)+1LL*(aux[i].second-aux[j].second)*(aux[i].second-aux[j].second));
            dmin=minim(dmin,d1);
        }
    }

    return dmin;
}

int main() {
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i].first>>sir[i].second;
    }
    sort(sir+1,sir+n+1);
    g<<fixed<<setprecision(6)<<sqrt((long double)distanta(1,n));
}
