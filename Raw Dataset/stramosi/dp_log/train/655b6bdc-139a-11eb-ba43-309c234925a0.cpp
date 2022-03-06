#include <stdio.h>


using namespace std;



int v[19][250005];

char chs[1000000 + 1];

int chs_poz = 1000000;



int parse_int()

{

    int x = 0;

    if(chs_poz >= 1000000)

    {

        chs_poz = 0;

        int num;

        num = fread(chs, 1, 1000000, stdin);

    }



    if(chs[chs_poz] < '0' || chs[chs_poz] > '9')

    {

        do

        {

            chs_poz++;

            if(chs_poz >= 1000000)

            {

                chs_poz = 0;

                int num;

                num = fread(chs, 1, 1000000, stdin);

            }

        }

        while(chs[chs_poz] < '0' || chs[chs_poz] > '9');

    }



    while(chs[chs_poz] >= '0' && chs[chs_poz] <= '9')

    {

        x = x*10 + chs[chs_poz] - '0';

        chs_poz++;

        if(chs_poz >= 1000000)

        {

            chs_poz = 0;

            int num;

            num = fread(chs, 1, 1000000, stdin);

        }

    }

    return x;

}



int get_lsb(int n)

{

    return (n&(n-1))^n;

}



int get_logpow2(int n)

{

    int p = 0;

    while(n > 1)

    {

        p++;

        n = n>>1;

    }

    return p;

}



int main()

{

    freopen("stramosi.in", "r", stdin);

    freopen("stramosi.out", "w", stdout);



    int n, m, i, j, k, p, q, powk;

    n = parse_int();

    m = parse_int();

    for(i = 1; i <= n; i++)

    {

        v[0][i] = parse_int();

    }



    for(k = 1; 1<<k <= n; k++)

    {

        for(i = 1; i <= n; i++)

        {

            v[k][i] = v[k - 1][v[k - 1][i]];

        }

    }



    powk = 1<<k;

    int p_crt, anc, pas_pow;

    for(i = 0; i < m; i++)

    {

        q = parse_int();

        p = parse_int();

        anc = q;

        while(p >= 0)

        {

            p_crt = get_lsb(p);

            p -= p_crt;

            pas_pow = get_logpow2(p_crt);

            anc = v[pas_pow][anc];

            if(anc == 0 || p == 0)

                break;

        }

        printf("%d\n", anc);

    }



    return 0;

}
