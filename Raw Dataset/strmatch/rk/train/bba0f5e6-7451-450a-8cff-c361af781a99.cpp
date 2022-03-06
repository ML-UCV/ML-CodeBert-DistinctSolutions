#include <bits/stdc++.h>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");



string A,B;

int hashA1,hashA2,P1,P2;

char match[2000001];



void Read()

{

    f>>A;

    f>>B;

    f.close();

}



void Solve()

{

    int lenA,lenB;

    lenA = A.length();

    lenB = B.length();

    P1 = P2 = 1;

    hashA1 = hashA2 = 0;

    for(int i=0;i<lenA;++i)

    {

        hashA1 = (hashA1*73 + A[i]) % 100007;

        hashA2 = (hashA2*73 + A[i]) % 100021;



        if(i != 0)

            {

                P1 = (P1 * 73) % 100007;

                P2 = (P2 * 73) % 100021;

            }

    }



    if(lenA > lenB)

    {

        g<<0<<'\n';

        g.close();

        return;

    }



    int hash1 = 0;

    int hash2 = 0;

    for(int i=0;i<lenA;++i)

    {

        hash1 = (hash1*73 + B[i]) % 100007;

        hash2 = (hash2*73 + B[i]) % 100021;

    }



    int Nr = 0;

    if(hash1 == hashA1 && hash2 == hashA2)

    {

        match[0] = 1;

        ++Nr;

    }



    for(int i=lenA;i<lenB;++i)

    {

        hash1 = ((hash1-(B[i-lenA] * P1) % 100007 + 100007) * 73 + B[i]) % 100007;

        hash2 = ((hash2 - (B[i-lenA]*P2) % 100021 + 100021) * 73 + B[i]) % 100021;



        if(hash1 == hashA1 && hash2 == hashA2)

        {

            match[i-lenA+1] = 1;

            ++Nr;

        }

    }

    g<<Nr<<'\n';



    Nr = 0;

    for(int i=0;i<lenB && Nr< 1000;++i)

        if(match[i])

            {

                ++Nr;

                g<<i<<" ";

            }

    g<<'\n';

    g.close();

}



int main()

{

    Read();

    Solve();

    return 0;

}
