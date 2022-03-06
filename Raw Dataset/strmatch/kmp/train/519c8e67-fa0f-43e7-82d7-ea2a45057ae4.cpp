#include <bits/stdc++.h>


using namespace std;

const int NMAX = 2000100;



int ans;

int lg1, lg2;

int pi_n[NMAX], pos[NMAX];

char N[NMAX], M[NMAX];



void cal_pi_n(){

    int k = 0;

    for(int i = 2; i <= lg1; i++){

        while(k > 0 && N[k + 1] != N[i])

            k = pi_n[k];

        if(N[k + 1] == N[i])

            k++;

        pi_n[i] = k;

    }

}



void cal_pi_m(){

    int k = 0;

    for(int i = 1; i <= lg2; i++){

        while(k > 0 && N[k + 1] != M[i])

            k = pi_n[k];

        if(N[k + 1] == M[i])

            k++;

        if(k == lg1)

            pos[++ans] = i - lg1;

    }

}



int main(){



    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);



    scanf("%s%s", N + 1, M + 1);

    lg1 = strlen(N + 1);

    lg2 = strlen(M + 1);

    cal_pi_n();

    cal_pi_m();

    printf("%d\n", ans);

    for(int i = 1; i <= min(ans, 1000); i++)

        printf("%d ", pos[i]);





    return 0;

}
