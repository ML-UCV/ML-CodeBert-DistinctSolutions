#include <stdio.h>
#include <vector>






using namespace std;



long n, i, j, k, l, sol;

char s1[51000], s2[51000];

long p[29], v[51000], aib[51000];

vector <long> poz[29];



int lsb(int x)

{

    return (x&(x-1))^x;

}



void update(int x)

{

    while(x<=l)

    {

        aib[x]++;

        x=x+lsb(x);

    }

}



int query(int x)

{

    int rez=0;

    while(x)

    {

        rez+=aib[x];

        x=x-lsb(x);

    }

    return rez;

}



int main()

{

    freopen("swap.in", "r", stdin);

    freopen("swap.out", "w", stdout);

    l=1;

    scanf("%c", &s1[l]);

    while(s1[l]>='a')

    {

        l++;

        scanf("%c", &s1[l]);

    }

    l--;

    for(i=1; i<=l; i++)

    {

        scanf("%c", &s2[i]);

        poz[s2[i]-'a'].push_back(i);

        aib[i]=0;

    }

    for(i=1; i<=l; i++)

    {

        k=s1[i]-'a';

        if(p[k]==poz[k].size())

        {

            printf("-1\n");

            return 0;

        }

        else

        {

            v[i]=poz[k][p[k]];

            p[k]++;

        }

    }

    for(i=1; i<=l; i++)

    {

        sol+=(i-1-query(v[i]));

        update(v[i]);

    }

    printf("%d\n", sol);

    return 0;

}
