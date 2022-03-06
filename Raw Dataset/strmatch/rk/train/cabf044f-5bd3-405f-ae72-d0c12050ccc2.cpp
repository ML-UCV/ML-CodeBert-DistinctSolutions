#include <fstream>
#include <cstring>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

char s[2000001],s2[2000001];

int n,b=101,mod1=100007,mod2=100021,h1,h2,m,i,hash1,hash2,p1,p2,rasp,v[1001];

int main() {

    f>>s>>s2;

    n=strlen(s);

    m=strlen(s2);

    p1=1;

    p2=1;

    for(i=0; i<n; i++) {

        hash1=hash1*b%mod1+s[i];

        hash2=hash2*b%mod2+s[i];

        if(i!=0) {

            p1=p1*b%mod1;

            p2=p2*b%mod2;

        }

    }

    if(n>m) {

        g<<0<<'\n';

        return 0;

    }

    for(i=0; i<n; i++) {

        h1=h1*b%mod1+s2[i];

        h2=h2*b%mod2+s2[i];

    }

    if(h1==hash1 && h2==hash2) {

        rasp++;

        v[rasp]=0;

    }

    for(i=n; i<m; i++) {

        h1=((h1-s2[i-n]*p1%mod1+mod1)*b+s2[i])%mod1;

        h2=((h2-s2[i-n]*p2%mod2+mod2)*b+s2[i])%mod2;

        if(h1==hash1 && h2==hash2) {

            rasp++;

            if(rasp<=1000) {

                v[rasp]=i-n+1;

            }

        }

    }

    g<<rasp<<'\n';

    rasp=min(1000,rasp);

    for(i=1;i<=rasp;i++)

    {

        g<<v[i]<<" ";

    }

}
