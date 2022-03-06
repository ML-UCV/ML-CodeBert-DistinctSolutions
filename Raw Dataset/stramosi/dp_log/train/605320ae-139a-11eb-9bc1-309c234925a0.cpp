#include <bits/stdc++.h>




using namespace std;

const int NMAX = 250010;



FILE *IN, *OUT;



int N, M;

int depth[NMAX], dp[19][NMAX];



int pos, sign, out;

char f[131072], Out[131072], str[10];



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



inline void Write_Ch(char ch){

    Out[out++] = ch;

    if(out == 131072)

        fwrite(Out, 131072, 1, OUT), out = 0;

}



inline void Write_Int(int nr){

    int x = 0;

    if(nr < 0) Write_Ch('-'), nr = -nr;

    do{

        str[x++] = nr % 10 + '0';

        nr /= 10;

    } while(nr);

    while(x > 0)

        Write_Ch(str[--x]);

}



void read(){

    int x;

    Read(N); Read(M);

    for(int i = 1; i <= N; i++)

        Read(dp[0][i]);

}



int main(){



    IN = fopen("stramosi.in", "r");

    OUT = fopen("stramosi.out", "w");



    read();



    for(int i = 1; (1 << i) <= N; i++)

        for(int j = 1; j <= N; j++)

            dp[i][j] = dp[i - 1][dp[i - 1][j]];



    int Q, P, p;

    for(int i = 1; i <= M; i++){

        Read(Q); Read(P); p = 0;

        while(P != 0){

            if(P % 2) Q = dp[p][Q];

            P /= 2; p++;

        }

        Write_Int(Q); Write_Ch('\n');

    }





    if(out > 0) fwrite(Out, 1, out, OUT);



    return 0;

}
