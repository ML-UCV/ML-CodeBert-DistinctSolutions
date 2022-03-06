#include <bits/stdc++.h>


using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



struct ex{

    int x, y, c;

}g[400005], sol[400005];



int n, m, t[200005], rang[200005], z;

 int sum;



bool cmp(ex a, ex b){

    return a.c < b.c;

}



int radacina(int k){

    if(!t[k])

        return k;

    else{

        int x = radacina(t[k]);

        t[k] = x;

        return x;

    }

}



void unire(int rk, int rp){

    if(rang[rk] > rang[rp])

        t[rp] = rk;

    else{

        t[rk] = rp;

        if(rang[rp] == rang[rk])

            rang[rp]++;

    }

}



int main(){

    in>>n>>m;



    for(int i = 1; i <= m; i++)

        in>>g[i].x>>g[i].y>>g[i].c;



    sort(g + 1, g + m + 1, cmp);



    for(int i = 1; i <= m; i++){

        int rk = radacina(g[i].x), rp = radacina(g[i].y);

        if(rk != rp){

            unire(rk, rp);

            sol[++z].x = g[i].y, sol[z].y = g[i].x;

            sol[z].c = g[i].c;

            sum += g[i].c;

        }

    }

    out<<sum<<"\n";

    out<<z<<"\n";

    for(int i = 1; i <= z; i++)

        out<<sol[i].x<<" "<<sol[i].y<<"\n";

}
