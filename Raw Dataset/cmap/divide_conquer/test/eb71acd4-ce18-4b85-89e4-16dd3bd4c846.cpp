#include <bits/stdc++.h>


using namespace std;



ifstream fin ("cmap.in");

ofstream fout ("cmap.out");

pair <long long, long long> v[100010],w[100010],d[100010];

int n,i;

long long dist (pair <long long,long long> a, pair <long long,long long> b){

    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);

}

long long modul (long long n){

    if (n < 0)

        return -n;

    return n;

}

void interclaseaza (int st, int mid, int dr){

    int i = st, j = mid+1;

    int el = st-1;

    while (i <= mid && j <= dr){

        if (v[i].second < v[j].second){

            d[++el] = v[i];

            i++;

        } else {

            d[++el] = v[j];

            j++;

        }

    }

    for (;i<=mid;i++)

        d[++el] = v[i];

    for (;j<=dr;j++)

        d[++el] = v[j];

    for (int i=st;i<=dr;i++)

        v[i] = d[i];

}

long long solve (int st, int dr){

    if (dr-st == 1){

        interclaseaza (st,st,dr);

        return dist (v[st],v[dr]);

    }

    if (dr-st == 2){

        long long sol = dist (v[st],v[st+1]);

        sol = min (sol,dist(v[st],v[st+2]));

        sol = min (sol,dist(v[st+1],v[st+2]));



        interclaseaza (st,st,st+1);

        interclaseaza (st,st+1,st+2);

        return sol;

    }

    int mid = (st+dr)>>1;

    long long sol_st = solve (st,mid);

    long long sol_dr = solve (mid+1,dr);



    interclaseaza(st,mid,dr);



    long long sol = min (sol_st,sol_dr);



    int k = 0;

    for (int i=st;i<=dr;i++){

        if (modul (v[i].first - v[mid].first) <= sol)

            w[++k] = v[i];

    }

    for (int i=1;i<=k;i++)

        for (int j=i+1;j<=min(k,i+7);j++)

            sol = min (sol,dist(w[i],w[j]));



    return sol;

}

int main (){



    fin>>n;

    for (i=1;i<=n;i++)

        fin>>v[i].first>>v[i].second;



    sort (v+1,v+n+1);

    fout<<setprecision(7)<<fixed<<(double)sqrt(solve(1,n));





    return 0;

}
