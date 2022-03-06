#include <fstream>
#include <cstring>
using namespace std;

ifstream f("swap.in");

ofstream g("swap.out");

int i,l,sol;

int fr_a[30],fr_b[30],AIB[1<<16],v[26][1<<16];

char a[1<<16],b[1<<16];

inline int zeros(int x)

{

    return ((x^(x-1))&x);

}

inline void bagval(int poz,int val)

{

    while(poz<=l)

    {

        AIB[poz]+=val;

        poz+=zeros(poz);

    }

}

inline int Query(int poz)

{

    int suma=0;

    while(poz)

    {

        suma+=AIB[poz];

        poz-=zeros(poz);

    }

    return suma;

}

int main()

{

    f>>(a+1)>>(b+1);

    l=strlen(a+1);

    for(i=l;i;--i)

    {

        short w=b[i]-'a';

        v[w][++v[w][0]]=i;

        bagval(i,1);

    }

    for(i=1;i<=l;++i)

    {

        short w=a[i]-'a';

        if(!v[w][0])

        {

            g<<-1;

            return 0;

        }

        sol+=Query(v[w][v[w][0]]-1);

        bagval(v[w][v[w][0]],-1);

        --v[w][0];

    }

    g<<sol;

    return 0;

}
