#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;



FILE *f, *g;



int rez;



unsigned short apa[26 + 1];

unsigned short apb[26 + 1];



int n;

char a[50009 + 2];

char b[50009 + 2];



unsigned short k;

unsigned short lst[26 + 1];

unsigned short nod[50009 + 1];

unsigned short urm[50009 + 1];



unsigned short aib[50009 + 1];



int getLen()

{

    int rez = 1;

    while(a[rez] >= 'a' && a[rez] <= 'z')

        rez ++;



    return rez;

}



void modif(char a[])

{

    int i;

    for(i = n; i >= 1; i --)

        a[i] = a[i - 1];

}



void readFile()

{

    f = fopen("swap.in", "r");



    fgets(a, 50009 + 2, f);

    fgets(b, 50009 + 2, f);



    n = getLen();



    modif(a);

    modif(b);



    fclose(f);

}



int pos()

{

    int i;

    int rez = 1;

    for(i = 1; i <= n; i ++)

    {

        apa[a[i] - 'a' + 1] ++;

        apb[b[i] - 'a' + 1] ++;

    }



    i = 1;

    while(i <= 26 && rez == 1)

    {

        rez = rez && (apa[i] == apb[i]);



        i ++;

    }



    return rez;

}



void addChar(int a, int b)

{

    k ++;



    nod[k] = b;

    urm[k] = lst[a];



    lst[a] = k;

}
void getRez()

{

    int i;

    for(i = 1; i <= n; i ++)

    {

        addChar(a[i] - 'a' + 1, i);

    }



    int p2, s;

    for(i = n; i >= 1; i --)

    {

        int nr = b[i] - 'a' + 1;

        int poz = nod[lst[nr]];

        lst[nr] = urm[lst[nr]];



        int p2 = poz + 1;

        while(p2 <= n)

        {

            aib[p2] += 1;



            p2 += p2 & (-p2);

        }



        s = 0;

        p2 = poz;

        while(p2 > 0)

        {

            s += aib[p2];



            p2 -= p2 & (-p2);

        }

        poz -= s;



        rez += i - poz;

    }

}



void solve()

{

    if(pos() == 0)

    {

        rez = -1;



        return;

    }



    getRez();

}



void printFile()

{

    g = fopen("swap.out", "w");



    fprintf(g, "%d\n", rez);
    fclose(g);

}



int main()

{

    readFile();



    solve();



    printFile();



    return 0;

}
