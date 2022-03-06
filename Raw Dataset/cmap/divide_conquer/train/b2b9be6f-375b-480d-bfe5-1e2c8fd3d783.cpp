#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>


using namespace std;



const int maxN=1e5+2;

const double INF=1e14;



int n;

pair<long long,long long> v[maxN];

pair<long long,long long> aux[maxN];



double getDist(pair<long long,long long> a,pair<long long,long long> b){

    return ((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));

}



void mergeHalves(int st,int mij,int dr){

    int idx1=st;

    int idx2=mij+1;

    int sz=0;



    while(idx1<=mij && idx2<=dr){

        if(v[idx1].second<v[idx2].second){

            aux[++sz]=v[idx1];

            idx1++;

        } else {

            aux[++sz]=v[idx2];

            idx2++;

        }

    }



    while(idx1<=mij){

        aux[++sz]=v[idx1];

        idx1++;

    }



    while(idx2<=dr){

        aux[++sz]=v[idx2];

        idx2++;

    }



    for(int i=1;i<=sz;i++){

        v[st+i-1]=aux[i];

    }

}



double divimp(int st,int dr){

    if(st>=dr){

        return INF;

    }



    if(dr-st==1){

        mergeHalves(st,st,dr);

        return getDist(v[st],v[dr]);

    }



    int mij=(st+dr)/2;

    double midX=v[mij].first;



    double leftDist=divimp(st,mij);

    double rightDist=divimp(mij+1,dr);

    double res=min(leftDist,rightDist);



    mergeHalves(st,mij,dr);



    int sz=0;

    for(int i=st;i<=dr;i++){

        if(abs(v[i].first-midX)<=res){

            aux[++sz]=v[i];

        }

    }



    for(int i=1;i<=sz;i++){

        for(int j=i-1;j>0 && i-j<8;j--){

            res=min(res,getDist(aux[i],aux[j]));

        }

    }



    return res;

}



int main(){

    ifstream f("cmap.in");

    ofstream g("cmap.out");



    f>>n;

    for(int i=1;i<=n;i++){

        f>>v[i].first>>v[i].second;

    }



    sort(v+1,v+n+1);



    g<<fixed<<setprecision(6)<<sqrt(divimp(1,n));



    return 0;

}
