#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100010;



FILE *IN, *OUT;



int N, M, K;

int srt[NMAX], ord[NMAX];

bool seen[NMAX];



vector <int> edges[NMAX], vAns[NMAX], Gph[NMAX];



int pos, sign;

char f[131072];



inline void Read(int &nr){

    sign = 0;

    nr = 0;

    while(f[pos] < '0' || f[pos] > '9'){

        if(f[pos] == '-') sign = 1;

        pos++;

        if(pos == 131072)

            fread(f, 131072, 1, IN), pos = 0;

    }

    while(f[pos] >= '0' && f[pos] <= '9'){

        nr = 10 * nr + f[pos++] - '0';

        if(pos == 131072)

            fread(f, 131072, 1, IN), pos = 0;

    }

    if(sign) nr =- nr;

}



void read(){

    Read(N); Read(M);

    int a, b;

    for(int i = 1; i <= M; i++){

        Read(a); Read(b);

        edges[a].push_back(b);

        Gph[b].push_back(a);

    }

}



void dfs(int node){

    seen[node] = true;

    for(auto it : edges[node])

        if(!seen[it])

            dfs(it);

    srt[++K] = node;

}



void solDFS(int node){

    seen[node] = false;

    vAns[K].push_back(node);

    for(auto it : Gph[node])

        if(seen[it])

            solDFS(it);

}



int main(){



    IN = fopen("ctc.in", "r");

    OUT = fopen("ctc.out", "w");



    read();



    for(int i = 1; i <= N; i++)

        if(!seen[i])

            dfs(i);

    K = 0;

    for(int i = N; i > 0; i--)

        if(seen[srt[i]])

            K++, solDFS(srt[i]);



    fprintf(OUT, "%d\n", K);

    for(int i = 1; i <= K; i++){

        for(auto it : vAns[i])

            fprintf(OUT, "%d ", it);

        fprintf(OUT, "\n");

    }





    return 0;

}
