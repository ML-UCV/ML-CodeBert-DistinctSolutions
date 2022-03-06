#include<stdio.h>






int Aib[30007];

int n, Q, a[30007], Ans[30007];



void update(int poz, int val){

    while(poz <= n){

        Aib[poz] += val;

        poz += poz & (poz ^ (poz - 1));

    }

}



int query(int poz){

    int sol = 0;

    while(poz){

        sol += Aib[poz];

        poz -= poz & (poz ^ (poz - 1));

    }

    return sol;

}



inline int cb(int Val){

    int st = 1, dr = n;

    while(st <= dr){

        int med = (st + dr) >> 1;

        if(Val <= query(med))

            dr = med - 1;

        else

            st = med + 1;

    }

    return st;

}



int main(){

    freopen("schi.in", "r", stdin);

    freopen("schi.out", "w", stdout);

    scanf("%d", &n);

    for(int i = 1; i <= n; ++i){

        scanf("%d", &a[i]);

        update(i, 1);

    }

    for(int i = n; i >= 1; --i){

        int poz = cb(a[i]);

        Ans[poz] = i;

        update(poz, -1);

    }

    for(int i = 1; i <= n; ++i)

        printf("%d\n", Ans[i]);

    return 0;

}
