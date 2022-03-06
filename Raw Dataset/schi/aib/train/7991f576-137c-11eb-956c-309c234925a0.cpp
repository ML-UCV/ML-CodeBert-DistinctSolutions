#include <stdio.h>
using namespace std;



FILE *fin = fopen("schi.in", "r");

FILE *fout = fopen("schi.out", "w");



int n,a[30005],aib[30005],i,ans[30005],loc;



void update(int poz)

{

    for(int i=poz; i<=n; i+=i&(-i))

        aib[i]--;

}



int sum(int poz)

{

    int rez = 0;



    for(int i=poz; i>=1; i-=i&(-i))

        rez += aib[i];



    return rez;

}



int query(int poz)

{

    int left = 1;

    int right = n,mid;

    int rez = -1;

    while(left <= right)

    {

        mid = (left+right) /2;



        if(sum(mid) >= poz)

        {

            rez = mid;

            right = mid-1;

        }

        else

            left = mid+1;

    }



    return rez;

}



int main()

{

    fscanf(fin, "%d", &n);

    for(i=1; i<=n; ++i)

    {

        fscanf(fin, "%d", &a[i]);

        aib[i] = i&(-i);

    }



    for(i=n; i>=1; --i)

    {

        loc = query(a[i]);

        ans[loc] = i;

        update(loc);

    }



    for(i=1; i<=n; ++i)

        fprintf(fout, "%d\n", ans[i]);



    fclose(fin);

    fclose(fout);

    return 0;

}
