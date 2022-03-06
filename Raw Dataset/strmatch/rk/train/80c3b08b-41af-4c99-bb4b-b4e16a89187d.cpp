#include <fstream>
#include <array>
#include <cstring>
#include <vector>






using namespace std;





ifstream f("strmatch.in");

ofstream g("strmatch.out");



char s1[2000005], s2[2000005];

int nr=0, sol[2000005];



struct Hash{

   long long n, m, power, hashh;

   void init(char *s, long long len)

    {

        power=1;

        hashh=0;

        for(long long i=len-1; i>=0; i--)

        {

            hashh=(hashh+(1LL*power*s[i])%m)%m;

            if(i)

                power=(power*n)%m;

        }

    }



    void roll(char toRemove, char toAdd)

    {

        hashh=(((hashh-(1LL*toRemove*power)%m+m)*n)%m+toAdd)%m;

    }





};



int main()

{

    int l1, l2;

    f.getline(s1, 2000005);

    f.getline(s2, 2000005);

    l1=strlen(s1);

    l2=strlen(s2);

    Hash pHash{31,40099},tHash{31,40099};

    Hash hHash{53,319993},oHash{53,319993};

    long long nr=0;

    pHash.init(s1,l1);

    tHash.init(s2,l1);

    hHash.init(s1,l1);

    oHash.init(s2,l1);

    if(pHash.hashh==tHash.hashh && hHash.hashh==oHash.hashh)

    {

        sol[++nr]=0;

    }

     for(long long i=l1;i<l2;i++)

    {

        tHash.roll(s2[i-l1],s2[i]);

        oHash.roll(s2[i-l1],s2[i]);

        if(tHash.hashh==pHash.hashh && hHash.hashh==oHash.hashh)

        {

            if(nr<=1000)

                sol[++nr]=(i-l1+1);

            else nr++;

        }

    }

    g<<nr<<'\n';

    if(nr>=1000)

        nr=1000;

    for(int i=1; i<=nr;i++)

       g<<sol[i]<<" ";

    return 0;

}
