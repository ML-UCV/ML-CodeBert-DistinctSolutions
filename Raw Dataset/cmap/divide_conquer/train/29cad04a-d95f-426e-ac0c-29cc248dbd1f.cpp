#include <bits/stdc++.h>


using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");

const long long NMAX = 100005;

const long long INF = (1LL<<62);

pair <long long,long long> a[NMAX],b[NMAX],c[NMAX];

long long n;

long long Abs(long long x){

    if(x<0) return -x;

    return x;

}

long long dist(pair<long long,long long> x,pair<long long,long long> y){

    return 1LL*(x.first-y.first)*(x.first-y.first)+1LL*(x.second-y.second)*(x.second-y.second);

}

long long solve(long long st,long long dr){

    if(st>=dr) return INF;

    if(dr-st+1==2){

        if(b[st+1]<b[st]){

            pair<long long,long long> aux;

            aux=b[st+1];

            b[st+1]=b[st];

            b[st]=aux;

        }

        return dist(a[st],a[st+1]);

    }

    long long mij=(st+dr)/2;

    long long d=min(solve(st,mij),solve(mij+1,dr));

    long long i=st,j=mij+1,m=0;

    while(i<=mij and j<=dr){

        if(b[i]<=b[j]){

            c[++m]=b[i];

            i++;

        }

        else{

            c[++m]=b[j];

            j++;

        }

    }

    while(i<=mij){

        c[++m]=b[i];

        i++;

    }

    while(j<=dr){

        c[++m]=b[j];

        j++;

    }

    for(long long i=st;i<=dr;i++) b[i]=c[i-st+1];

    long long m2=0;

    for(long long i=st;i<=dr;i++){

        if(Abs(b[i].second-a[mij].first)<=d)

            c[++m2]=b[i];

    }

    for(long long i=1;i<=m2;i++)

        for(long long j=i+1;j<=m2 and j<=i+7;j++)

            d=min(d,dist(c[i],c[j]));

    return d;

}

int main()

{

    fin >> n;

    for(long long i=1;i<=n;i++) fin >> a[i].first >> a[i].second;

    sort(a+1,a+n+1);

    for(long long i=1;i<=n;i++){

        b[i].first=a[i].second;

        b[i].second=a[i].first;

    }

    fout << setprecision(6) << fixed << sqrt(solve(1,n));

    return 0;

}
