#include <fstream>
#include <algorithm>
#include <math.h>
#include <iomanip>




using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");



int n;

pair<long long, long long> v[100010], aux[100010], verifica[100010];



long long DistantaLaPatrat(pair<long long, long long>a, pair<long long, long long>b){

    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);

}



void interclasare(int st, int mid, int dr){

    int n=mid;

    int m=dr;

    int i=st;

    int j=mid+1;

    int k=st-1;

    while(i<=n && j<=m){

        if(v[i].second<v[j].second){

            k++;

            aux[k]=v[i];

            i++;

        }else{

            k++;

            aux[k]=v[j];

            j++;

        }

    }

    for(; i<=n; i++){

        k++;

        aux[k]=v[i];

    }

    for(; j<=m; j++){

        k++;

        aux[k]=v[j];

    }

    for(i=st; i<=dr; i++){

        v[i]=aux[i];

    }

}



long long solve(long long st, long long dr){

    long long sol;

    if(dr-st==1){

        sol=DistantaLaPatrat(v[st], v[dr]);

        interclasare(st, st, dr);

        return sol;

    }

    if(dr-st==2){

        sol=min( DistantaLaPatrat(v[st], v[st+1]), DistantaLaPatrat(v[st+1], v[dr]) );

        interclasare(st, st, st+1);

        interclasare(st, st+1, dr);

        return sol;

    }

    long long mid=(st+dr)/2;

    long long sol1=solve(st, mid);

    long long sol2=solve(mid+1, dr);

    interclasare(st, mid, dr);

    sol=min(sol1, sol2);

    long long nr=0;

    for(int i=st; i<=dr; i++){

        if(max(v[mid].first-v[i].first, v[i].first-v[mid].first) <= sol){

            nr++;

            verifica[nr]=v[i];

        }

    }

    for(int i=1; i<=nr; i++){

        for(int j=i+1; j<=nr && j<=i+7; j++){

            sol=min(sol, DistantaLaPatrat(verifica[i], verifica[j]));

        }

    }

    return sol;

}



int main(){

    fin>>n;

    for(int i=1; i<=n; i++){

        fin>>v[i].first>>v[i].second;

    }

    sort(v+1,v+n+1);

    fout<<setprecision(6)<<fixed<<(double)sqrt( solve(1,n) );

}
