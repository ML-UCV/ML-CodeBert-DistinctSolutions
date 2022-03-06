#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>




using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



long long n,i,j;

pair <long long,long long> v[100001],r[100001],w[100001];



long long dist(pair<long long,long long> a, pair<long long,long long> b){

    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);

}



long long inter(long long st, long long mid, long long dr){

    long long i=st;

    long long j=mid+1;

    long long k=st-1;



    while(i<=mid && j<=dr){

        if(v[i].second<v[j].second)

            r[++k]=v[i++];

        else

            r[++k]=v[j++];

    }



    for(;i<=mid;i++)

        r[++k]=v[i];

    for(;j<=dr;j++)

        r[++k]=v[j];



    for(i=st;i<=dr;i++)

        v[i]=r[i];

}



long long solve(long long st, long long dr){

    long long sol,i,j;



    if(dr-st==1){

        inter(st,st,dr);

        return dist(v[st],v[dr]);

    }

    if(dr-st==2){

        inter(st,st,dr-1);

        inter(st,dr-1,dr);

        return min(dist(v[st],v[dr]),min(dist(v[st+1],v[st]),dist(v[st+1],v[dr])));

    }



    long long mid=(st+dr)/2;



    sol=min(solve(st,mid),solve(mid+1,dr));

    inter(st,mid,dr);



    long long cnt=0;

    for(i=st;i<=dr;i++){

        if(abs(v[mid].first-v[i].first)<=sol){

            w[++cnt]=v[i];

        }

    }



    for(i=1;i<cnt;i++)

        for(j=i+1;j<=min(cnt,i+7);j++)

            sol=min(sol,dist(w[i],w[j]));



    return sol;

}



int main(){

    fin>>n;

    for(i=1;i<=n;i++)

        fin>>v[i].first>>v[i].second;

    sort(v+1,v+n+1);



    fout<<setprecision(7)<<fixed<<sqrt(solve(1,n));



    return 0;

}
