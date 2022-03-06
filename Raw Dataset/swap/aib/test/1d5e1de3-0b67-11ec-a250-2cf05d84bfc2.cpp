#include <algorithm>#include <fstream>#include <cstring>
#include <vector>
using namespace std;
vector <int> p[26];

int aib[50005],f[26];

char a[50005],b[50005];

int n,nrt;



int lsb (int x)

{

    return x^(x-1)&x;

}



void update (int poz,int val)

{

    for ( ; poz<=n; poz+=lsb (poz))

        aib[poz]+=val;

}



int query (int poz)

{

    int sum;



    for (sum=0; poz; poz-=lsb (poz))

        sum+=aib[poz];

    return sum;

}



void solve ()

{

    int i;



    n=strlen (a+1)-1;

    for (i=1; i<=n; ++i)

        p[a[i]-'a'].push_back (i);

    for (i=1; i<=n; ++i)

        update (i,1);

    for (i=1; i<=n; ++i)

    {

        if (f[b[i]-'a']>=(int)p[b[i]-'a'].size ())

        {

            printf ("-1");

            return ;

        }

        nrt+=query (p[b[i]-'a'][f[b[i]-'a']]-1);

        update (p[b[i]-'a'][f[b[i]-'a']],-1);

        ++f[b[i]-'a'];

    }

    printf ("%d",nrt);

}



int main ()

{

    freopen ("swap.in","r",stdin);

    freopen ("swap.out","w",stdout);



    fgets (a+1,50005,stdin);

    fgets (b+1,50005,stdin);

    solve ();



    return 0;

}
