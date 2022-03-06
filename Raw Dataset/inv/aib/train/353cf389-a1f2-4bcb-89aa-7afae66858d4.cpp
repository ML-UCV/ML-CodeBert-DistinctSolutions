#include <stdio.h>
#include <algorithm>
using namespace std;



FILE *fin = fopen("inv.in", "r");

FILE *fout = fopen("inv.out", "w");



struct tablou {int x; int poz;} a[100005];



int n,i,aib[100005];

long long total;



bool comparare(tablou a, tablou b)

{

    if(a.x!=b.x) return (a.x < b.x);

    return(a.poz<b.poz);

}



void update(int poz)

{

    for(int i=poz; i<=n; i+=i&(-i))

        aib[i]++;

}



int sum(int poz)

{

    int ans = 0;



    for(int i=poz; i>=1; i-=i&(-i))

        ans += aib[i];



    return ans;

}



int main()

{

    fscanf(fin, "%d", &n);

    for(i=1; i<=n; ++i)

    {

        fscanf(fin, "%d", &a[i].x);

        a[i].poz = i;

    }



    sort(a+1, a+n+1, comparare);



    for(i=1; i<=n; ++i)

    {

        total += 1LL*sum(a[i].poz);

        update(a[i].poz);

    }



    fprintf(fout, "%d", (1LL*n*(n-1)/2 - total)%9917);



    fclose(fin);

    fclose(fout);

    return 0;

}
