#include <fstream>
#include <string.h>


using namespace std;

ifstream f("swap.in");

ofstream g("swap.out");

int i, n, perm[50010], lastap[50010], poz[27][50010], ind[27], vtmp[50010], nr, k, ap1[27], ap2[27];

char a[50010], b[50010];



void interc(int st, int mid, int dr)

{

    int i=0, j=0, k=0;

    for (i=st, j=mid+1; i<=mid && j<=dr; ) {

        if (perm[i] > perm[j]) {

            vtmp[++k]=perm[j];

            j++;

            nr=nr+mid-i+1;

        }

        else {

            vtmp[++k]=perm[i];

            i++;

        }

    }

    for (; i<=mid; i++)

        vtmp[++k]=perm[i];

    for (; j<=dr; j++)

        vtmp[++k]=perm[j];

    k=0;

    for (i=st; i<=dr; i++)

        perm[i]=vtmp[++k];

}

void divimp(int st, int dr)

{

    if (dr-st<=1) {

        if (perm[st] > perm[dr]) {

            nr++;

            int tmp=perm[st];

            perm[st]=perm[dr];

            perm[dr]=tmp;

        }

    }

    else {

        int mid=(st+dr)/2;

        divimp(st, mid);

        divimp(mid+1, dr);

        interc(st, mid, dr);

    }

}



int main()

{

    f.get(a, 50001);

    f.get();

    f.get(b, 50001);

    n=strlen(a);

    for (i=0; i<n; i++) {

        poz[a[i]-'a'][ ++poz[a[i]-'a'][0] ]=i;

        ap1[a[i]-'a']++;

        ap2[b[i]-'a']++;

    }

    for (i=0; i<=26; i++) {

        ind[i]=1;

        if (ap1[i]!=ap2[i]) {

            g<<-1;

            return 0;

        }

    }

    for (i=0; i<n; i++) {

        perm[i]=poz[b[i]-'a'][ind[b[i]-'a']];

        ind[b[i]-'a']++;

    }

    divimp(0, n-1);

    g<<nr;

    return 0;

}
