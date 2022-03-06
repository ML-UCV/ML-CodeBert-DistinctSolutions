#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <assert.h>
#include <iomanip>
#include <algorithm>


const int MAXN = 100000 + 5;



using namespace std;



typedef long long ll;



ifstream in("cmap.in");

ofstream out("cmap.out");





int n;

struct punct{

    ll x,y;

}v[MAXN],puncte_posibile[MAXN];



bool cmp_x(punct a,punct b){

    return a.x < b.x;

}

bool cmp_y(punct a,punct b){

    return a.y > b.y;

}

ll dist(punct a,punct b){

    ll ans = abs(a.x - b.x) * abs(a.x - b.x) + abs(a.y - b.y) * abs(a.y - b.y);

    assert(ans > 0);

    return ans;

}



ll divide(int l,int r){

    if(r - l <= 3){

        ll minim = 2e18;

        for(int i = l; i <= r; i++){

            for(int j = l; j <= r; j++){

                if(j != i)

                    minim = min(minim,dist(v[i],v[j]));

            }

        }



        return minim;

    }

    int mij = (l + r) / 2;

    ll dreapta = divide(l,mij);

    ll stanga = divide(mij + 1,r);

    ll distanta = min(dreapta,stanga);



    int index = 0;

    for(int i = l; i <= r; i++)

        if(abs(v[i].x - v[mij].x) <= distanta)

            puncte_posibile[++index] = v[i];

    sort(puncte_posibile + 1,puncte_posibile + index + 1,cmp_y);



    ll distanta_minima = 2e18;

    for(int i = 1; i <= index; i++){

        for(int j = i + 1; j <= min(index,i + 9); j++){

            distanta_minima = min(distanta_minima,dist(puncte_posibile[i],puncte_posibile[j]));

        }

    }

    assert(distanta > 0);

    return min(distanta_minima,distanta);

}

void testare(){

    srand(0);

    for(int teste = 1; teste <= 100; teste++){

        n = rand() % (int)1e2 + 2;

        for(int i = 1; i <= n; i++){

            v[i].x = rand() % (int)1e9;

            v[i].y = rand() % (int)1e9;

        }



        sort(v + 1, v + n + 1,cmp_x);

        ll rezultat = divide(1,n);

        ll distanta_minima = 2e18;

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= n; j++){

                if(j != i)

                    distanta_minima = min(distanta_minima,dist(v[i],v[j]));

            }

        }

        assert(distanta_minima == rezultat);

        out<<setprecision(10)<<fixed<<sqrt(rezultat);

    }

}



int main()

{

    in>>n;

    for(int i = 1; i <= n; i++){

        in>>v[i].x>>v[i].y;

    }

    sort(v + 1,v + n + 1,cmp_x);

    ll rezultat = divide(1,n);

    double radical = sqrt(rezultat);

    out<<setprecision(10)<<fixed<<radical;





    return 0;

}
