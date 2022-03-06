#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

ifstream fin ("inv.in");

ofstream fout ("inv.out");

int n,i,S[100010],A[100010],sol,dbl;

pair <int,int>v[100010];

int q(int p){

    int nr=0;

    for(;p;p-=(p&-p))

        nr+=A[p];

    return nr;

}

void up(int p){

    for(;p<=n;p+=(p&-p))

        A[p]++;

}

int main(){

    fin>>n;

    for(i=1;i<=n;i++){

        fin>>v[i].first;

        v[i].second=i;

}

    sort(v+1,v+n+1);

    for(i=1;i<=n;i++){

        if(v[i].first==v[i-1].first){

            S[v[i].second]=S[v[i-1].second];

            dbl++;

        }

        else

            S[v[i].second]=i-dbl;

    }

    for(i=1;i<=n;i++){

        sol+=q(n-dbl)-q(S[i]);

        sol%=9917;

        up(S[i]);

    }

    fout<<sol;

    return 0;

}
