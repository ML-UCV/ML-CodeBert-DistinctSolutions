#include <bits/stdc++.h>






using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int aib[30005], v[30005], sol[30005];

int n,m;



void add(int val,int poz){

    int i;

    for(i = poz; i <= n; i += (i&-i)){

        aib[i] += val;

    }

}



int sum(int poz){

    int i,sol = 0;

    for(i = poz; i >= 1; i -= (i&-i)){

        sol += aib[i];

    }

    return sol;

}



int sumsrc(int val){

    int st = 1,dr = n,mid,midsum,sol = 900000005;

    while(st <= dr){

        mid = (st+dr)/2;

        midsum = sum(mid);

        if(val < midsum){

            dr = mid-1;

        }else if(val == midsum){

            sol = min(sol,mid);

            dr = mid-1;

        }else if(midsum < val){

            st = mid+1;

        }

    }

    return sol;

}



int main()

{

    int i,sumpoz;

    fin>>n;

    for(i = 1; i <= n; i++){

        fin>>v[i];

        add(1,i);

    }

    for(i = n; i >= 1; i--){

        sumpoz = sumsrc(v[i]);

        sol[sumpoz] = i;

        add(-1,sumpoz);

    }

    for(i = 1; i <= n; i++){

        fout<<sol[i]<<'\n';

    }

    return 0;

}
