#include <bits/stdc++.h>


using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");



struct ex{

    int x , y, cost;

}g[200005], sol[200005];



int n, m, rang[200005], z, t[200005];

long long int sum;



bool cmp(ex a, ex b){

    return a.cost < b.cost;

}



int radacina(int k){

    if(!t[k])

        return k;

    else

        return t[k] = radacina(t[k]);

}



void unire(int rp, int rk){

        if(rang[rk] > rang[rp])

            t[rp] = rk;

        else{

            t[rk] = rp;

            if(rang[rk] == rang[rp])

                rang[rp]++;

        }

}



int main(){

    in>>n>>m;

    for(int i = 1; i <= m; i++)

        in>>g[i].x>>g[i].y>>g[i].cost;

    sort(g + 1, g + m + 1, cmp);



    for(int i = 1; i <= m; i++){

        int rk = radacina(g[i].x), rp = radacina(g[i].y);

        if(rk != rp){

            unire(rp, rk);

            sol[++z].x = g[i].x, sol[z].y = g[i].y, sol[z].cost = g[i].cost;

            sum += g[i].cost;

        }

    }

    out<<sum<<"\n"<<z<<"\n";

    for(int i = 1; i <= z; i++)

        out<<sol[i].x<<" "<<sol[i].y<<"\n";

}
