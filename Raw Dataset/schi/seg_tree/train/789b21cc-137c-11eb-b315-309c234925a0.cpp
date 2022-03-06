#include <bits/stdc++.h>


using namespace std;



const int MAX = 131072;

const int NMAX = 30100;

const int INF = 1e6;



struct arb{

    int mi, del, poz;

} T[3*NMAX];



int N, ans;

int v[NMAX];



int pos;

char f[MAX];



inline void Read(int &nr){

    nr = 0;

    while(f[pos] < '0' || f[pos] > '9'){

        pos++;

        if(pos == MAX)

            fread(f, MAX, 1, stdin), pos = 0;

    }

    while(f[pos] >= '0' && f[pos] <= '9'){

        nr = 10 * nr + f[pos++] - '0';

        if(pos == MAX)

            fread(f, MAX, 1, stdin), pos = 0;

    }

}



void build(int node, int st, int nd){

    if(st == nd){

        T[node].mi = v[st];

        T[node].poz = st;

    } else {

        int mid = (st + nd) / 2;

        build(2 * node, st, mid);

        build(2 * node + 1, mid + 1, nd);

        T[node].mi = T[2 * node + 1].mi;

        T[node].poz = T[2 * node + 1].poz;

        if(T[2 * node].mi < T[2 * node + 1].mi){

            T[node].mi = T[2 * node].mi;

            T[node].poz = T[2 * node].poz;

        }

    }

}



int Update(int node, int st, int nd){

    if(st == nd){

        T[node].mi = INF;

        return 0;

    } else {

        int mid = (st + nd) / 2;

        if(T[2 * node].mi < T[2 * node + 1].mi){

            T[2 * node + 1].del++;

            T[2 * node + 1].mi--;

            Update(2 * node, st, mid);

        } else Update(2 * node + 1, mid + 1, nd);

    }

    T[node].mi = T[2 * node].mi;

    T[node].poz = T[2 * node].poz;

    if(T[node].mi >= T[2 * node + 1].mi){

        T[node].mi = T[2 * node + 1].mi;

        T[node].poz = T[2 * node + 1].poz;

    }

    T[node].mi -= T[node].del;

}



int read(){

    fread(f, 1, MAX, stdin);

    Read(N);

    for(int i = 1; i <= N; i++)

        Read(v[i]);

}



int main(){



    freopen("schi.in", "r", stdin);

    freopen("schi.out", "w", stdout);



    read();

    build(1, 1, N);



    for(int i = 1; i <= N; i++){

        ans = T[1].poz;

        Update(1, 1, N);

        printf("%d\n", ans);

    }



    return 0;

}
