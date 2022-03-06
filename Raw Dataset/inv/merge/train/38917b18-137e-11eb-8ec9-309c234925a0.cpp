#include <iostream>
#include <fstream>
using namespace std;

ifstream f ("inv.in");

ofstream g ("inv.out");

int a[100005];

void merging(int p[100005], int st, int mij, int dr, long long& nr_swaps)

{

    int l[mij-st+2];

    int r[dr-mij+1];

    for(int i=1; i<=mij-st+1; i++)

    {

        l[i]=p[st+i-1];

    }

    for(int i=1; i<=dr-mij; i++)

    {

        r[i]=p[mij+i];

    }

    int i=1, j=1;

    int t=st;

    int pate=0;

    while(i<=mij-st+1 && j<=dr-mij)

    {

        if(r[j]<l[i])

        {

            int len1=mij-st-(i-1)-pate;

            int len2=j-1;

            nr_swaps+=len1+len2+1;

            p[t]=r[j];

            pate++;

            j++;

            t++;

        }

        else

        {

            p[t]=l[i];

            i++;

            t++;

        }

    }

    while(i<=mij-st+1)

    {

        p[t]=l[i];

        t++;

        i++;

    }

    while(j<=dr-mij)

    {

        p[t]=r[j];

        j++;

        t++;

    }

}

void merge_sort(int p[100005], int st, int dr, long long& nr_swaps)

{

    if(st<dr)

    {

        if(st+1==dr)

        {

            if(p[dr]<p[st])

            {

                nr_swaps++;

                swap(p[st], p[dr]);

            }

        }

        else

        {

            int mij=(st+dr)/2;

            merge_sort(p, st, mij, nr_swaps);

            merge_sort(p, mij+1, dr, nr_swaps);

            merging(p, st, mij, dr, nr_swaps);

        }

    }

    return;

}



int n;

int main()

{

    f>>n;

    for(int i=1; i<=n; i++)

    {

        f>>a[i];

    }

    long long rez=0;

    merge_sort(a, 1, n, rez);

    g<<rez%9917;

    return 0;

}
