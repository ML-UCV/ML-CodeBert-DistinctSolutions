#include <bits/stdc++.h>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



vector< pair<int,int> >ar;

int n, m, v[400001], s;



struct muchii{

    int x, y, cost;



}lm[400001];



bool compara(muchii a, muchii b){

    return a.cost<b.cost;

}



int radacina(int i){

    if(v[i]!=i)

        v[i] = radacina(v[i]);

    return v[i];

}



int main(){

    f >> n >> m;



    for(int i = 0; i < m; i++)

        f >> lm[i].x >> lm[i].y >> lm[i].cost;



    sort(lm, lm + m, compara);



    for(int i = 1; i <= n; i++)

        v[i] = i;



    for(int i = 0; i < m; i++)

        if(radacina(lm[i].x) != radacina(lm[i].y)){

            v[radacina(lm[i].y)] = lm[i].x;

            s += lm[i].cost;

            ar.push_back ( make_pair(lm[i].x,lm[i].y));

        }



    g<<s<<endl;

    g<<ar.size()<<endl;



    for( auto elem =ar.begin(); elem != ar.end(); elem++)

        g<<(*elem).first<<" " << (*elem).second<<endl;



    return 0;

}
